#include "AudioVolumeObserver.h"
#include "BaneApp.h"
#include "DisplayTypeChangedObserver.h"
#include "GeneralSettingsTab.h"
#include "LanguageChangedObserver.h"
#include <QGridLayout>
#include "PausedWhileInBackgroundObserver.h"
#include "ItemModel.h"
#include "VideoResolutionChangedObserver.h"

using namespace net::draconia::games::bane::ui;
using namespace net::draconia::games::bane::ui::model;
using namespace net::draconia::games::bane::ui::observers;

extern template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::Language>;
extern template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::VideoResolution>;

void GeneralSettingsTab::audioVolumeChanged()
{
    getSettingsModel().setAudioVolume(getAudioVolumeSlider()->value());
}

void GeneralSettingsTab::displayTypeChanged(const int iDisplayType)
{
    getSettingsModel().setDisplayType((SettingsModel::DisplayType)(iDisplayType));
}

AudioVolumeLabel *GeneralSettingsTab::getAudioVolumeLabel()
{
    if(mLblAudioVolume == nullptr)
        {
        mLblAudioVolume = new AudioVolumeLabel(this, getSettingsModel());

        mLblAudioVolume->setBuddy(getAudioVolumeSlider());
        }

    return(mLblAudioVolume);
}

QSlider *GeneralSettingsTab::getAudioVolumeSlider()
{
    if(mObjAudioVolume == nullptr)
        {
        mObjAudioVolume = new QSlider(Qt::Orientation::Horizontal, this);

        mObjAudioVolume->setAutoFillBackground(true);
        mObjAudioVolume->setTickInterval(1);
        mObjAudioVolume->setValue(getSettingsModel().getAudioVolume());

        connect(mObjAudioVolume, &QSlider::valueChanged, this, &GeneralSettingsTab::audioVolumeChanged);
        }

    return(mObjAudioVolume);
}

QComboBox *GeneralSettingsTab::getDisplayComboBox()
{
    if(mCboDisplay == nullptr)
        {
        QList<QString> lstDisplayTypes({{"Borderless", "Full Screen", "Windowed"}});
        mCboDisplay = new QComboBox(this);

        mCboDisplay->addItems(lstDisplayTypes);

        switch(getSettingsModel().getDisplayType())
            {
            case SettingsModel::DisplayType::Borderless:
                mCboDisplay->setCurrentIndex(lstDisplayTypes.indexOf("Borderless"));
                break;
            case SettingsModel::DisplayType::FullScreen:
                mCboDisplay->setCurrentIndex(lstDisplayTypes.indexOf("Full Screen"));
                break;
            case SettingsModel::DisplayType::Windowed:
                mCboDisplay->setCurrentIndex(lstDisplayTypes.indexOf("Windowed"));
                break;
            default:
                mCboDisplay->setCurrentIndex(-1);
            }

        connect(mCboDisplay, SIGNAL(QComboBox::currentIndexChanged(int)), this, SLOT(GeneralSettingsTab::displayTypeChanged(int)));
        }

    return(mCboDisplay);
}

QLabel *GeneralSettingsTab::getDisplayLabel()
{
    if(mLblDisplay == nullptr)
        {
        mLblDisplay = new QLabel("&Display:", this);
        mLblDisplay->setAutoFillBackground(false);
        mLblDisplay->setBuddy(getDisplayComboBox());
        }

    return(mLblDisplay);
}

QComboBox *GeneralSettingsTab::getLanguageComboBox()
{
    if(mCboLanguage == nullptr)
        {
        QList<SettingsModel::Language> lstLanguages(getSettingsModel().getAvailableLanguages());
        mCboLanguage = new QComboBox(this);
        mCboLanguage->setModel(new ItemModel<SettingsModel::Language>(lstLanguages));

        mCboLanguage->setCurrentIndex(lstLanguages.indexOf(getSettingsModel().getLanguage()));

        connect(mCboLanguage, SIGNAL(QComboBox::currentIndexChanged(int)), this, SLOT(GeneralSettingsTab::languageChanged(int)));
        }

    return(mCboLanguage);
}

QLabel *GeneralSettingsTab::getLanguageLabel()
{
    if(mLblLanguage == nullptr)
        {
        mLblLanguage = new QLabel("&Language:", this);
        mLblLanguage->setAutoFillBackground(false);
        mLblLanguage->setBuddy(getLanguageComboBox());
        }

    return(mLblLanguage);
}

QCheckBox *GeneralSettingsTab::getPauseGameCheckBox()
{
    if(mChkPauseGame == nullptr)
        {
        mChkPauseGame = new QCheckBox("&Pause Game When In Background", this);

        mChkPauseGame->setAutoFillBackground(true);
        mChkPauseGame->setChecked(getSettingsModel().isPausedWhileInBackground());

        connect(mChkPauseGame, &QCheckBox::clicked, this, &GeneralSettingsTab::pauseClicked);
        }

    return(mChkPauseGame);
}

SettingsModel &GeneralSettingsTab::getSettingsModel() const
{
    return(mRefModel);
}

QComboBox *GeneralSettingsTab::getVideoResolutionComboBox()
{
    if(mCboVideoResoution == nullptr)
        {
        QList<SettingsModel::VideoResolution> lstVideoResolutions(getSettingsModel().getAvailableVideoResolutions());
        mCboVideoResoution = new QComboBox(this);
        mCboVideoResoution->setModel(new ItemModel<SettingsModel::VideoResolution>(lstVideoResolutions));

        mCboVideoResoution->setCurrentIndex(lstVideoResolutions.indexOf(getSettingsModel().getVideoResolution()));

        connect(mCboVideoResoution, SIGNAL(QComboBox::currentIndexChanged(int)), this, SLOT(GeneralSettingsTab::videoResolutionChanged(int)));
        }

    return(mCboVideoResoution);
}

QLabel *GeneralSettingsTab::getVideoResolutionLabel()
{
    if(mLblVideoResolution == nullptr)
        {
        mLblVideoResolution = new QLabel("&Video Resolution:", this);
        mLblVideoResolution->setAutoFillBackground(false);
        mLblVideoResolution->setBuddy(getVideoResolutionComboBox());
        }

    return(mLblVideoResolution);
}

void GeneralSettingsTab::initControls() const
{
    GeneralSettingsTab *ptrThis = const_cast<GeneralSettingsTab *>(this);
    QGridLayout *layout = new QGridLayout(ptrThis);

    layout->addWidget(ptrThis->getLanguageLabel(), 0, 0);
    layout->addWidget(ptrThis->getLanguageComboBox(), 0, 1);
    layout->addWidget(ptrThis->getVideoResolutionLabel(), 1, 0);
    layout->addWidget(ptrThis->getVideoResolutionComboBox(), 1, 1);
    layout->addWidget(ptrThis->getAudioVolumeLabel(), 2, 0);
    layout->addWidget(ptrThis->getAudioVolumeSlider(), 2, 1);
    layout->addWidget(ptrThis->getDisplayLabel(), 3, 0);
    layout->addWidget(ptrThis->getDisplayComboBox(), 3, 1);
    layout->addWidget(ptrThis->getPauseGameCheckBox(), 4, 0, 1, 2);

    ptrThis->setLayout(layout);
}

void GeneralSettingsTab::initTab() const
{
    const_cast<GeneralSettingsTab *>(this)->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}


void GeneralSettingsTab::languageChanged(const int iLanguage)
{
    QMap<int, QVariant> mapValues = getLanguageComboBox()->model()->itemData((QModelIndex()));
    QVariant &refValue = mapValues[iLanguage];
    SettingsModel::Language objLanguage = refValue.value<SettingsModel::Language>();

    getSettingsModel().setLanguage(objLanguage);
}

void GeneralSettingsTab::pauseClicked()
{
    getSettingsModel().setPauseWhileInBackground(getPauseGameCheckBox()->isChecked());
}

void GeneralSettingsTab::videoResolutionChanged(const int iVideoResolution)
{
    QMap<int, QVariant> mapValues = getVideoResolutionComboBox()->model()->itemData((QModelIndex()));

    getSettingsModel().setVideoResolution((SettingsModel::VideoResolution &)(mapValues[iVideoResolution]));
}

GeneralSettingsTab::GeneralSettingsTab(QWidget *parent)
    :   GeneralSettingsTab(parent, static_cast<BaneApp *>(qApp)->getController().getSettingsModel())
{ }

GeneralSettingsTab::GeneralSettingsTab(QWidget *parent, const SettingsModel &refModel)
    :   QWidget(parent)
    ,   mLblAudioVolume(nullptr)
    ,   mChkPauseGame(nullptr)
    ,   mCboDisplay(nullptr)
    ,   mCboLanguage(nullptr)
    ,   mCboVideoResoution(nullptr)
    ,   mLblDisplay(nullptr)
    ,   mLblLanguage(nullptr)
    ,   mLblVideoResolution(nullptr)
    ,   mObjAudioVolume(nullptr)
    ,   mRefModel(const_cast<SettingsModel &>(refModel))
{
    getSettingsModel().addObserver(new AudioVolumeObserver(getAudioVolumeLabel()->getDisplayLabel(), getAudioVolumeSlider()));
    getSettingsModel().addObserver(new DisplayTypeChangedObserver(getDisplayComboBox()));
    getSettingsModel().addObserver(new LanguageChangedObserver(getLanguageComboBox()));
    getSettingsModel().addObserver(new PausedWhileInBackgroundObserver(getPauseGameCheckBox()));
    //getSettingsModel().addObserver(new VideoResolutionChangedObserver(getVideoResolutionComboBox()));

    initTab();
}
