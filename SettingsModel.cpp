#include "BaneApp.h"
#include "BaneController.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "SettingsModel.h"

using namespace net::draconia::games::bane::model;

SettingsModel::Language::Language()
{ }

SettingsModel::Language::Language(const QString &sLanguage, const QString &sRegion)
    :   msLanguage(sLanguage)
    ,   msRegion(sRegion)
{ }

SettingsModel::Language::Language(const Language &refCopy)
    :   Language(const_cast<Language &>(refCopy).getLanguage(), const_cast<Language &>(refCopy).getRegion())
{ }

SettingsModel::Language::~Language()
{ }

QString &SettingsModel::Language::getLanguage() const
{
    return(const_cast<Language &>(*this).msLanguage);
}

QString &SettingsModel::Language::getRegion() const
{
    return(const_cast<Language &>(*this).msRegion);
}

void SettingsModel::Language::setLanguage(const QString &sLanguage)
{
    msLanguage = sLanguage;
}

void SettingsModel::Language::setRegion(const QString &sRegion)
{
    msRegion = sRegion;
}

SettingsModel::Language &SettingsModel::Language::operator=(const Language &refCopy)
{
    setLanguage(const_cast<SettingsModel::Language &>(refCopy).getLanguage());
    setRegion(const_cast<SettingsModel::Language &>(refCopy).getRegion());

    return(*this);
}

bool SettingsModel::Language::operator==(const Language &refOther) const
{
    return  (   (const_cast<SettingsModel::Language &>(*this).getLanguage() == const_cast<SettingsModel::Language &>(refOther).getLanguage())
            &&  (const_cast<SettingsModel::Language &>(*this).getRegion() == const_cast<SettingsModel::Language &>(refOther).getRegion()));
}

bool SettingsModel::Language::operator!=(const Language &refOther) const
{
    return(!operator==(refOther));
}

QJsonObject SettingsModel::Language::toJson()
{
    QJsonObject obj;

    obj["language"] = getLanguage();
    obj["region"] = getRegion();

    return(obj);
}

QString SettingsModel::Language::toString() const
{
    return("[Language = " + getLanguage() + ", Region = " + getRegion() + "]");
}

SettingsModel::VideoResolution::VideoResolution()
{ }

SettingsModel::VideoResolution::VideoResolution(const unsigned uiWidth, const unsigned uiHeight)
    :   muiHeight(uiHeight), muiWidth(uiWidth)
{ }

SettingsModel::VideoResolution::VideoResolution(const VideoResolution &refCopy)
    :   SettingsModel::VideoResolution(refCopy.getWidth(), refCopy.getHeight())
{ }

SettingsModel::VideoResolution::~VideoResolution()
{ }

unsigned SettingsModel::VideoResolution::getHeight() const
{
    return(muiHeight);
}

unsigned SettingsModel::VideoResolution::getWidth() const
{
    return(muiWidth);
}

void SettingsModel::VideoResolution::setHeight(const unsigned uiHeight)
{
    muiHeight = uiHeight;
}

void SettingsModel::VideoResolution::setWidth(const unsigned uiWidth)
{
    muiWidth = uiWidth;
}

SettingsModel::VideoResolution SettingsModel::VideoResolution::operator=(const SettingsModel::VideoResolution &refCopy)
{
    setHeight(refCopy.getHeight());
    setWidth(refCopy.getWidth());

    return(*this);
}

bool SettingsModel::VideoResolution::operator==(const SettingsModel::VideoResolution &refOther) const
{
    return  (   (getHeight() == refOther.getHeight())
            &&  (getWidth()) == refOther.getWidth());
}

bool SettingsModel::VideoResolution::operator!=(const SettingsModel::VideoResolution &refOther) const
{
    return(!operator==(refOther));
}

QJsonObject SettingsModel::VideoResolution::toJson() const
{
    QJsonObject obj;

    obj["width"] = QJsonValue(static_cast<int>(getWidth()));
    obj["height"] = QJsonValue(static_cast<int>(getHeight()));

    return(obj);
}

QString SettingsModel::VideoResolution::toString() const
{
    return(QString("%1").arg(getWidth()) + "x" + QString("%1").arg(getHeight()));
}

SettingsModel::SettingsModel()
    :   Observable()
    ,   mbPauseWhileInBackground(true)
    ,   meDisplayType(DisplayType::Windowed)
    ,   muiAudioVolume((static_cast<BaneApp *>(qApp)->getController().getAudioOutput().volume() / 1.0) * 100)
    ,   mObjVideoResolution(640, 480)
{ }

SettingsModel::SettingsModel(const SettingsModel &refCopy)
    :   Observable(refCopy)
    ,   mbPauseWhileInBackground(refCopy.isPausedWhileInBackground())
    ,   meDisplayType(refCopy.getDisplayType())
    ,   mObjLanguage(refCopy.getLanguage())
    ,   muiAudioVolume(refCopy.getAudioVolume())
    ,   mObjVideoResolution(refCopy.getVideoResolution())
{ }

SettingsModel::~SettingsModel()
{ }

unsigned SettingsModel::getAudioVolume() const
{
    return(const_cast<SettingsModel *>(this)->muiAudioVolume);
}

QMap<SettingsModel::InterfaceType, QMap<QString, QString>> &SettingsModel::getControlMap() const
{
    return(const_cast<SettingsModel *>(this)->mMapControls);
}

SettingsModel::DisplayType &SettingsModel::getDisplayType() const
{
    return(const_cast<SettingsModel *>(this)->meDisplayType);
}

SettingsModel::Language &SettingsModel::getLanguage() const
{
    return(const_cast<SettingsModel *>(this)->mObjLanguage);
}

SettingsModel::VideoResolution &SettingsModel::getVideoResolution() const
{
    return(const_cast<SettingsModel *>(this)->mObjVideoResolution);
}

bool SettingsModel::isPausedWhileInBackground() const
{
    return(const_cast<SettingsModel *>(this)->mbPauseWhileInBackground);
}

void SettingsModel::load(const QString &sFilename)
{
    DisplayType arrDisplayTypes[3];

    arrDisplayTypes[0] = DisplayType::Borderless;
    arrDisplayTypes[1] = DisplayType::FullScreen;
    arrDisplayTypes[2] = DisplayType::Windowed;

    QFile file(sFilename);

    if(!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject obj = doc.object();

    QJsonObject objGeneral = obj["General"].toObject();

    setAudioVolume(objGeneral["AudioVolume"].toInt());
    setDisplayType(arrDisplayTypes[objGeneral["DisplayType"].toInt()]);
    setLanguage(Language(objGeneral["Language"].toObject()["language"].toString(), objGeneral["Language"].toObject()["Region"].toString()));
    setPauseWhileInBackground(objGeneral["PausedWhileInBackground"].toBool(false));
    setVideoResolution(VideoResolution(objGeneral["VideoResolution"].toObject()["Width"].toInt(), objGeneral["VideoResolution"].toObject()["Height"].toInt()));

    //handle Control stuff

    file.close();
}

void SettingsModel::save(const QString &sFilename)
{
    QFile file(sFilename);
    QJsonObject obj;

    obj["AudioVolume"] = QJsonValue(static_cast<int>(getAudioVolume()));
    obj["DisplayType"] = QJsonValue(getDisplayType());
    obj["Language"] = QJsonValue(getLanguage().toJson());
    obj["PauseWhenInBackground"] = isPausedWhileInBackground();
    obj["VideoResolution"] = QJsonValue(getVideoResolution().toJson());

    // Put the Controls stuff here

    if(!file.open(QIODevice::WriteOnly))
        return;

    file.write(QJsonDocument(obj).toJson());
    file.flush();
    file.close();
}

void SettingsModel::setAudioVolume(const unsigned uiAudioVolume)
{
    muiAudioVolume = uiAudioVolume;

setChanged();
    notifyObservers("AudioVolume");
}

void SettingsModel::setControl(const SettingsModel::InterfaceType &eInterface, const QString &sControl, const QString &sKey)
{
    QMap<SettingsModel::InterfaceType, QMap<QString, QString>> &map = const_cast<QMap<SettingsModel::InterfaceType, QMap<QString, QString>> &>(const_cast<const SettingsModel *>(this)->getControlMap());
    QMap<QString, QString> &controls = map[eInterface];

    controls[sControl] = sKey;

    setChanged();
    notifyObservers("Control");
}

void SettingsModel::setDisplayType(const SettingsModel::DisplayType &eDisplayType)
{
    meDisplayType = eDisplayType;

    setChanged();
    notifyObservers("DisplayType");
}

void SettingsModel::setLanguage(const SettingsModel::Language &refLanguage)
{
    mObjLanguage = refLanguage;

    setChanged();
    notifyObservers("Language");
}

void SettingsModel::setPauseWhileInBackground(const bool bPauseWhileInBackground)
{
    mbPauseWhileInBackground = bPauseWhileInBackground;

    setChanged();
    notifyObservers("PauseWhileInBackground");
}

void SettingsModel::setVideoResolution(const SettingsModel::VideoResolution &refVideoResolution)
{
    mObjVideoResolution = refVideoResolution;

    setChanged();
    notifyObservers("VideoResolution");
}

SettingsModel &SettingsModel::operator=(const SettingsModel &refCopy)
{
    setAudioVolume(refCopy.getAudioVolume());
    setDisplayType(refCopy.getDisplayType());
    setLanguage(refCopy.getLanguage());
    setPauseWhileInBackground(refCopy.isPausedWhileInBackground());
    setVideoResolution(refCopy.getVideoResolution());

    return(*this);
}

bool SettingsModel::operator==(const SettingsModel &refOther) const
{
    return  (   (getAudioVolume()               ==  refOther.getAudioVolume())
            &&  (getDisplayType()               ==  refOther.getDisplayType())
            &&  (getLanguage()                  ==  refOther.getLanguage())
            &&  (isPausedWhileInBackground()    ==  refOther.isPausedWhileInBackground())
            &&  (getVideoResolution()           ==  refOther.getVideoResolution()));
}

bool SettingsModel::operator!=(const SettingsModel &refOther) const
{
    return(!operator==(refOther));
}
