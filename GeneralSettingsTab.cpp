#include "AudioVolumeObserver.h"
#include "BaneApp.h"
#include "DisplayTypeChangedObserver.h"
#include "GeneralSettingsTab.h"
#include "LanguageChangedObserver.h"
#include "PausedWhileInBackgroundObserver.h"
#include <QFormLayout>
#include "VideoResolutionChangedObserver.h"

using namespace net::draconia::games::bane::ui;
using namespace net::draconia::games::bane::ui::model;
using namespace net::draconia::games::bane::ui::observers;

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
        mObjAudioVolume->setMaximum(100);
        mObjAudioVolume->setMinimum(0);
        mObjAudioVolume->setTickInterval(1);
        mObjAudioVolume->setValue(getSettingsModel().getAudioVolume());

        connect(mObjAudioVolume, SIGNAL(valueChanged(int)), this, SLOT(audioVolumeChanged(int)));
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

        connect(mCboDisplay, SIGNAL(currentIndexChanged(int)), this, SLOT(displayTypeChanged(int)));
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
        mCboLanguage = new QComboBox(this);

        mCboLanguage->addItems(getSettingsModel().getAvailableLanguagesAsStringList());

        SettingsModel::Language &refLanguage = getSettingsModel().getLanguage();
        int iLanguageIndex = getSettingsModel().getAvailableLanguages().indexOf(refLanguage);

        mCboLanguage->setCurrentIndex(iLanguageIndex);

        connect(mCboLanguage, SIGNAL(currentIndexChanged(int)), this, SLOT(languageChanged(int)));
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

SettingsModel &GeneralSettingsTab::getSettingsModel()
{
    if(mPtrModel == nullptr)
        mPtrModel = &static_cast<BaneApp *>(qApp)->getController().getSettingsModel();

    return(*mPtrModel);
}


QComboBox *GeneralSettingsTab::getVideoResolutionComboBox()
{
    if(mCboVideoResolution == nullptr)
        {
        mCboVideoResolution = new QComboBox(this);

        mCboVideoResolution->addItems(getSettingsModel().getAvailableVideoResolutionsAsStringList());

        mCboVideoResolution->setCurrentIndex(getSettingsModel().getAvailableVideoResolutions().indexOf(getSettingsModel().getVideoResolution()));

        connect(mCboDisplay, SIGNAL(currentIndexChanged(int)), this, SLOT(videoResolutionChanged(int)));
        }

    return(mCboVideoResolution);
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

void GeneralSettingsTab::initControls()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *subLayout = new QFormLayout(this);

    subLayout->addRow(getLanguageLabel(), getLanguageComboBox());
    subLayout->addRow(getVideoResolutionLabel(), getVideoResolutionComboBox());
    subLayout->addRow(getAudioVolumeLabel(), getAudioVolumeSlider());
    subLayout->addRow(getDisplayLabel(), getDisplayComboBox());
    subLayout->addRow(getPauseGameCheckBox());

    layout->addItem(subLayout);
    layout->addStretch();

    setLayout(layout);
}

void GeneralSettingsTab::initTab()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

void GeneralSettingsTab::audioVolumeChanged(const int iVolume)
{
    getSettingsModel().setAudioVolume(iVolume);
}

void GeneralSettingsTab::displayTypeChanged(const int iDisplayType)
{
    getSettingsModel().setDisplayType(static_cast<SettingsModel::DisplayType>(iDisplayType));
}

void GeneralSettingsTab::languageChanged(const int iLanguage)
{
    QList<SettingsModel::Language> lstLanguages = getSettingsModel().getAvailableLanguages();
    SettingsModel::Language &refLanguage = lstLanguages[iLanguage], &refSetLanguage = getSettingsModel().getLanguage();

    if(refLanguage != refSetLanguage)
        getSettingsModel().setLanguage(refLanguage);
}

void GeneralSettingsTab::pauseClicked()
{
    getSettingsModel().setPauseWhileInBackground(getPauseGameCheckBox()->isChecked());
}

void GeneralSettingsTab::videoResolutionChanged(const int iVideoResolution)
{
    QList<SettingsModel::VideoResolution> lstVideoResolutions = getSettingsModel().getAvailableVideoResolutions();

    if(lstVideoResolutions[iVideoResolution] != getSettingsModel().getVideoResolution())
        getSettingsModel().setVideoResolution(lstVideoResolutions[iVideoResolution]);
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
    ,   mCboVideoResolution(nullptr)
    ,   mLblDisplay(nullptr)
    ,   mLblLanguage(nullptr)
    ,   mLblVideoResolution(nullptr)
    ,   mObjAudioVolume(nullptr)
    ,   mPtrModel(&const_cast<SettingsModel &>(refModel))
{
    getSettingsModel().addObserver(new LanguageChangedObserver(getLanguageComboBox()));
    getSettingsModel().addObserver(new AudioVolumeObserver(getAudioVolumeLabel()->getDisplayLabel(), getAudioVolumeSlider()));
    getSettingsModel().addObserver(new DisplayTypeChangedObserver(getDisplayComboBox()));
    getSettingsModel().addObserver(new PausedWhileInBackgroundObserver(getPauseGameCheckBox()));
    getSettingsModel().addObserver(new VideoResolutionChangedObserver(getVideoResolutionComboBox()));


    initTab();
}

GeneralSettingsTab::~GeneralSettingsTab()
{
    getSettingsModel().clearObservers();
}
