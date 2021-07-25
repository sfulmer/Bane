#include "AudioVolumeLabel.h"
#include "BaneApp.h"
#include <QHBoxLayout>

using net::draconia::games::bane::BaneApp;
using net::draconia::games::bane::BaneController;
using namespace net::draconia::games::bane::ui;

SettingsModel &AudioVolumeLabel::getModel() const
{
    return(mRefModel);
}

void AudioVolumeLabel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getMainLabel());
    layout->addWidget(getDisplayLabel());

    setLayout(layout);
}

void AudioVolumeLabel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding));

    initControls();
}

AudioVolumeLabel::AudioVolumeLabel(const QWidget *parent)
    :   AudioVolumeLabel(parent, static_cast<BaneApp *>(qApp)->getController().getSettingsModel())
{ }

AudioVolumeLabel::AudioVolumeLabel(const QWidget *parent, const SettingsModel &refModel)
    :   QWidget(const_cast<QWidget *>(parent))
    ,   mLblDisplay(nullptr)
    ,   mLblMainLable(nullptr)
    ,   mPtrBuddy(nullptr)
    ,   mRefModel(const_cast<SettingsModel &>(refModel))
{
    initPanel();
}

QWidget *AudioVolumeLabel::buddy() const
{
    return(mPtrBuddy);
}

QLabel *AudioVolumeLabel::getDisplayLabel()
{
    if(mLblDisplay == nullptr)
        {
        mLblDisplay = new QLabel(QString("%1").arg(getModel().getAudioVolume()));

        mLblDisplay->setAutoFillBackground(false);
        }

    return(mLblDisplay);
}

QLabel *AudioVolumeLabel::getMainLabel()
{
    if(mLblMainLable == nullptr)
        {
        mLblMainLable = new QLabel("&Audio Volume: ");

        if(buddy() != nullptr)
            mLblMainLable->setBuddy(buddy());
        }

    return(mLblMainLable);
}

void AudioVolumeLabel::setBuddy(const QWidget *ptrBuddy)
{
    mPtrBuddy = const_cast<QWidget *>(ptrBuddy);

    getMainLabel()->setBuddy(buddy());
}
