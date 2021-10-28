#include "AudioVolumeObserver.h"
#include "BaneApp.h"
#include "DisplayTypeChangedObserver.h"
#include "GeneralSettingsTab.h"
#include "ItemModel.h"
#include "LanguageChangedObserver.h"
#include "PausedWhileInBackgroundObserver.h"
#include <QFormLayout>
#include "VideoResolutionChangedObserver.h"

using namespace net::draconia::games::bane::ui;
using namespace net::draconia::games::bane::ui::model;
using namespace net::draconia::games::bane::ui::observers;

extern template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::Language>;
extern template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::VideoResolution>;

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
        QList<SettingsModel::Language> lstLanguages(getSettingsModel().getAvailableLanguages());
        mCboLanguage = new QComboBox(this);
        mCboLanguage->setModel(new ItemModel<SettingsModel::Language>(lstLanguages));

        mCboLanguage->setCurrentIndex(lstLanguages.indexOf(getSettingsModel().getLanguage()));

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
    return(mRefModel);
}

QComboBox *GeneralSettingsTab::getVideoResolutionComboBox()
{
    if(mCboVideoResoution == nullptr)
        {
        QList<SettingsModel::VideoResolution> lstVideoResolutions(getSettingsModel().getAvailableVideoResolutions());
        mCboVideoResoution = new QComboBox(this);
        mCboVideoResoution->setModel(new ItemModel<SettingsModel::VideoResolution>(lstVideoResolutions));

        int iVideoResolution = lstVideoResolutions.indexOf(getSettingsModel().getVideoResolution());

        mCboVideoResoution->setCurrentIndex(iVideoResolution);

        connect(mCboVideoResoution, SIGNAL(currentIndexChanged(int)), this, SLOT(videoResolutionChanged(int)));
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
    QVBoxLayout *layout = new QVBoxLayout(ptrThis);
    QFormLayout *subLayout = new QFormLayout(ptrThis);

    subLayout->addRow(ptrThis->getLanguageLabel(), ptrThis->getLanguageComboBox());
    subLayout->addRow(ptrThis->getVideoResolutionLabel(), ptrThis->getVideoResolutionComboBox());
    subLayout->addRow(ptrThis->getAudioVolumeLabel(), ptrThis->getAudioVolumeSlider());
    subLayout->addRow(ptrThis->getDisplayLabel(), ptrThis->getDisplayComboBox());
    subLayout->addRow(ptrThis->getPauseGameCheckBox());

    layout->addItem(subLayout);
    layout->addStretch();

    ptrThis->setLayout(layout);
}

void GeneralSettingsTab::initTab() const
{
    const_cast<GeneralSettingsTab *>(this)->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

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

void GeneralSettingsTab::languageChanged(int iLanguage)
{
    SettingsModel::Language objLanguage = getLanguageComboBox()->itemData(iLanguage, Qt::DisplayRole).value<SettingsModel::Language>();

    getSettingsModel().setLanguage(objLanguage);
}

void GeneralSettingsTab::pauseClicked()
{
    getSettingsModel().setPauseWhileInBackground(getPauseGameCheckBox()->isChecked());
}

void GeneralSettingsTab::videoResolutionChanged(const int iVideoResolution)
{
    SettingsModel::VideoResolution objVideoResolution = getVideoResolutionComboBox()->itemData(iVideoResolution, Qt::DisplayRole).value<SettingsModel::VideoResolution>();

    getSettingsModel().setVideoResolution(objVideoResolution);
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
    getSettingsModel().addObserver(new LanguageChangedObserver(getLanguageComboBox()));
    getSettingsModel().addObserver(new VideoResolutionChangedObserver(getVideoResolutionComboBox()));
    getSettingsModel().addObserver(new AudioVolumeObserver(getAudioVolumeLabel()->getDisplayLabel(), getAudioVolumeSlider()));
    getSettingsModel().addObserver(new DisplayTypeChangedObserver(getDisplayComboBox()));
    //getSettingsModel().addObserver(new PausedWhileInBackgroundObserver(getPauseGameCheckBox()));

    initTab();
}
