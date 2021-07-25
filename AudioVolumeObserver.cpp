#include "AudioVolumeObserver.h"
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QLabel *AudioVolumeObserver::getAudioVolumeLabel()
{
    return(mLblAudioVolume);
}

QSlider *AudioVolumeObserver::getAudioVolumeSlider()
{
    return(mObjAudioVolume);
}

void AudioVolumeObserver::setAudioVolumeSlider(QSlider *objAudioVolume)
{
    mObjAudioVolume = objAudioVolume;
}

void AudioVolumeObserver::setAudioVolumeLabel(const QLabel *lblAudioVolume)
{
    mLblAudioVolume = const_cast<QLabel *>(lblAudioVolume);
}

AudioVolumeObserver::AudioVolumeObserver(QLabel *lblAudioVolume, QSlider *objAudioVolume)
    :   Observer()
    ,   mLblAudioVolume(lblAudioVolume)
    ,   mObjAudioVolume(objAudioVolume)
{ }

AudioVolumeObserver::AudioVolumeObserver(const AudioVolumeObserver &refCopy)
    :   AudioVolumeObserver(const_cast<AudioVolumeObserver &>(refCopy).getAudioVolumeLabel(), const_cast<AudioVolumeObserver &>(refCopy).getAudioVolumeSlider())
{ }

AudioVolumeObserver::~AudioVolumeObserver()
{ }

void AudioVolumeObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));

    if(static_cast<int>(refModel.getAudioVolume()) != getAudioVolumeSlider()->value())
        getAudioVolumeSlider()->setValue(refModel.getAudioVolume());
    if(static_cast<int>(refModel.getAudioVolume()) != getAudioVolumeLabel()->text())
       getAudioVolumeLabel()->setText(QString("%1").arg(refModel.getAudioVolume()));
}
