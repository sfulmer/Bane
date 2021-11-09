#include "BaneApp.h"
#include "BaneController.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QScreen>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include "SettingsModel.h"

using namespace net::draconia::games::bane::model;

QList<SettingsModel::Language> SettingsModel::Language::loadFromRepo(QSqlDatabase &db)
{
    QList<SettingsModel::Language> lstReturn;
    QSqlQuery query(db);

    query.prepare("select Id, Language, Region from Languages;");

    if(query.exec())
        {
        if(query.first())
            do
                {
                unsigned uiId;
                QString sLanguage, sRegion;

                uiId = query.value("Id").toUInt();
                sLanguage = query.value("Language").toString();
                sRegion = query.value("Region").toString();

                lstReturn.append(SettingsModel::Language(uiId, sLanguage, sRegion));
                }
            while(query.next());
        }
    else
            qDebug() << query.lastError();

    return(lstReturn);
}

SettingsModel::Language::Language()
{ }

SettingsModel::Language::Language(const unsigned uiId, const QString &sLanguage, const QString &sRegion)
    :   muiId(uiId)
    ,   msLanguage(sLanguage)
    ,   msRegion(sRegion)
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

SettingsModel::Language::operator QString() const
{
    return(toString());
}

QJsonObject SettingsModel::Language::toJson() const
{
    QJsonObject obj;

    obj["language"] = getLanguage();
    obj["region"] = getRegion();

    return(obj);
}

QString SettingsModel::Language::toString() const
{
    return(getLanguage() + "(" + getRegion() + ")");
}

QList<SettingsModel::VideoResolution> SettingsModel::VideoResolution::loadFromRepo(QSqlDatabase &db)
{
    QList<SettingsModel::VideoResolution> lstReturn;
    QSqlQuery query(db);

    query.prepare("select Id, Width, Height from VideoResolutions;");

    if(query.exec())
        {
        if(query.first())
            do
                {
                int iId, iWidth, iHeight;

                iId = query.value("Id").toInt();
                iWidth = query.value("Width").toInt();
                iHeight = query.value("Height").toInt();

                lstReturn.append(SettingsModel::VideoResolution(iId, iWidth, iHeight));
                }
            while(query.next());
        }

    return(lstReturn);
}

SettingsModel::VideoResolution::VideoResolution()
{ }

SettingsModel::VideoResolution::VideoResolution(const unsigned uiId, const unsigned uiWidth, const unsigned uiHeight)
    :   muiId(uiId), muiHeight(uiHeight), muiWidth(uiWidth)
{ }

SettingsModel::VideoResolution::VideoResolution(const unsigned uiWidth, const unsigned uiHeight)
    :   muiHeight(uiHeight), muiWidth(uiWidth)
{ }

SettingsModel::VideoResolution::VideoResolution(const VideoResolution &refCopy)
    :   SettingsModel::VideoResolution(refCopy.getId(), refCopy.getWidth(), refCopy.getHeight())
{ }

SettingsModel::VideoResolution::~VideoResolution()
{ }

unsigned SettingsModel::VideoResolution::getHeight() const
{
    return(muiHeight);
}

unsigned SettingsModel::VideoResolution::getId() const
{
    return(muiId);
}

unsigned SettingsModel::VideoResolution::getWidth() const
{
    return(muiWidth);
}

void SettingsModel::VideoResolution::setHeight(const unsigned uiHeight)
{
    muiHeight = uiHeight;
}

void SettingsModel::VideoResolution::setId(const unsigned int uiId)
{
    muiId = uiId;
}

void SettingsModel::VideoResolution::setWidth(const unsigned uiWidth)
{
    muiWidth = uiWidth;
}

SettingsModel::VideoResolution SettingsModel::VideoResolution::operator=(const SettingsModel::VideoResolution &refCopy)
{
    setHeight(refCopy.getHeight());
    setId(refCopy.getId());
    setWidth(refCopy.getWidth());

    return(*this);
}

bool SettingsModel::VideoResolution::operator==(const SettingsModel::VideoResolution &refOther) const
{
    return  (   (getId() == refOther.getId())
            &&  (getHeight() == refOther.getHeight())
            &&  (getWidth()) == refOther.getWidth());
}

bool SettingsModel::VideoResolution::operator!=(const SettingsModel::VideoResolution &refOther) const
{
    return(!operator==(refOther));
}

SettingsModel::VideoResolution::operator QString() const
{
    qDebug() << toString();

    return(toString());
}

QJsonObject SettingsModel::VideoResolution::toJson() const
{
    QJsonObject obj;

    obj["id"] = QJsonValue(static_cast<int>(getId()));
    obj["width"] = QJsonValue(static_cast<int>(getWidth()));
    obj["height"] = QJsonValue(static_cast<int>(getHeight()));

    return(obj);
}

QString SettingsModel::VideoResolution::toString() const
{
    return(QString("%1").arg(getWidth()) + "x" + QString("%1").arg(getHeight()));
}

const QString SettingsModel::mcsSettingsPath(QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory) + "Bane/Settings.json");

QList<SettingsModel::Language> SettingsModel::msLstLanguagesAvailable;
QList<SettingsModel::VideoResolution> SettingsModel::msLstVideoResolutionsAvailable;

void SettingsModel::loadFromRepo()
{
    if(QSqlDatabase::isDriverAvailable("QSQLITE"))
        {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        if(QFile(QStandardPaths::locate(QStandardPaths::AppDataLocation, QString(), QStandardPaths::LocateDirectory) + "../../Bane/resources/database/repo.db").exists())
            {
            db.setDatabaseName(QStandardPaths::locate(QStandardPaths::AppDataLocation, QString(), QStandardPaths::LocateDirectory) + "../../Bane/resources/database/repo.db");

            if(!db.open())
                qDebug() << "Error loading repo:\n" << db.lastError();
            else
                {
                msLstLanguagesAvailable = SettingsModel::Language::loadFromRepo(db);
                msLstVideoResolutionsAvailable = SettingsModel::VideoResolution::loadFromRepo(db);
                }
            }
        }
}

SettingsModel::SettingsModel()
    :   Observable()
    ,   mbPauseWhileInBackground(true)
    ,   meDisplayType(DisplayType::Windowed)
    ,   muiAudioVolume((static_cast<BaneApp *>(qApp)->getController().getAudioOutput().volume() / 1.0) * 100)
    ,   mObjVideoResolution(0, 0)
{
    loadFromRepo();

    load();

    if(getLanguage() == Language())
        for(Language &refLanguage : getAvailableLanguages())
            if(refLanguage.getLanguage().contains("English", Qt::CaseInsensitive))
                setLanguage(refLanguage);

    if(getVideoResolution() == VideoResolution(0, 0))
        {
        QRect screensize = static_cast<QGuiApplication *>(qApp)->primaryScreen()->geometry();
        QList<VideoResolution> lstResolutions = getAvailableVideoResolutions();

        for(unsigned uiLength = 0, uiLoop = lstResolutions.length() - 1; uiLoop >= uiLength; uiLoop--)
            {
            VideoResolution &refVideoResolution = lstResolutions[uiLoop];

            if((static_cast<int>(refVideoResolution.getHeight()) <= screensize.height()) && (static_cast<int>(refVideoResolution.getWidth()) <= screensize.width()))
                {
                setVideoResolution(refVideoResolution);

                break;
                }
            }

        if(getVideoResolution() == VideoResolution(0, 0))
            setVideoResolution(lstResolutions[0]);
        }
}

SettingsModel::SettingsModel(const SettingsModel &refCopy)
    :   Observable(refCopy)
    ,   mbPauseWhileInBackground(refCopy.isPausedWhileInBackground())
    ,   meDisplayType(refCopy.getDisplayType())
    ,   mObjLanguage(refCopy.getLanguage())
    ,   muiAudioVolume(refCopy.getAudioVolume())
    ,   mObjVideoResolution(refCopy.getVideoResolution())
{
    loadFromRepo();
}

SettingsModel::~SettingsModel()
{ }

unsigned SettingsModel::getAudioVolume() const
{
    return(const_cast<SettingsModel *>(this)->muiAudioVolume);
}

QList<SettingsModel::Language> &SettingsModel::getAvailableLanguages()
{
    return(msLstLanguagesAvailable);
}

QList<QString> SettingsModel::getAvailableLanguagesAsStringList()
{
    QList<QString> lstData;

    for(int iLength = getAvailableLanguages().length(), iLoop = 0; iLoop < iLength;iLoop++)
        {
        Language &refLanguage = getAvailableLanguages()[iLoop];

        lstData.append(refLanguage.toString());
        }

    return(lstData);
}

QList<SettingsModel::VideoResolution> &SettingsModel::getAvailableVideoResolutions()
{
    return(msLstVideoResolutionsAvailable);
}

QList<QString> SettingsModel::getAvailableVideoResolutionsAsStringList()
{
    QList<QString> lstData;

    for(int iLength = getAvailableVideoResolutions().length(), iLoop = 0; iLoop < iLength;iLoop++)
        {
        VideoResolution &refVideoResolution = getAvailableVideoResolutions()[iLoop];

        lstData.append(refVideoResolution.toString());
        }

    return(lstData);
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
    QFile file(sFilename);

    if(!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject obj = doc.object();

    QJsonObject objGeneral = obj["General"].toObject();

    setAudioVolume(objGeneral["AudioVolume"].toInt());
    setDisplayType(static_cast<DisplayType>(objGeneral["DisplayType"].toInt()));
    {
        const QJsonObject &refLanguage = objGeneral["Language"].toObject();
        QString sLanguage = refLanguage["language"].toString();
        QString sRegion = refLanguage["Region"].toString();

        setLanguage(Language(sLanguage, sRegion));
    }
    setPauseWhileInBackground(objGeneral["PausedWhileInBackground"].toBool(false));
    setVideoResolution(VideoResolution(objGeneral["VideoResolution"].toObject()["Width"].toInt(), objGeneral["VideoResolution"].toObject()["Height"].toInt()));

    //handle Control stuff

    file.close();
}

void SettingsModel::save(const QString &sFilename)
{
    QFile file(sFilename);
    QJsonObject obj, objGeneral, objControls;

    qDebug() << sFilename << " and " << (file.exists() ? "it exists":"it doesn't exist");

    objGeneral["AudioVolume"] = QJsonValue(static_cast<int>(getAudioVolume()));
    objGeneral["DisplayType"] = QJsonValue(getDisplayType());
    objGeneral["Language"] = QJsonValue(getLanguage().toJson());
    objGeneral["PauseWhenInBackground"] = isPausedWhileInBackground();
    objGeneral["VideoResolution"] = QJsonValue(getVideoResolution().toJson());

    obj["General"] = objGeneral;

    // Put the Controls stuff here

    obj["Controls"] = objControls;

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
