#include "AudioOutputVolumeObserver.h"
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QAudioOutput &AudioOutputVolumeObserver::getAudioOutput() const
{
    return(mRefAudioOutput);
}

AudioOutputVolumeObserver::AudioOutputVolumeObserver(const QAudioOutput &refAudioOutput)
    :   mRefAudioOutput(const_cast<QAudioOutput &>(refAudioOutput))
{ }

AudioOutputVolumeObserver::AudioOutputVolumeObserver(const AudioOutputVolumeObserver &refCopy)
    :   AudioOutputVolumeObserver(const_cast<AudioOutputVolumeObserver &>(refCopy).getAudioOutput())
{ }

AudioOutputVolumeObserver::~AudioOutputVolumeObserver()
{ }

void AudioOutputVolumeObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));

    if(refModel.getAudioVolume() != static_cast<unsigned>(getAudioOutput().volume() * 100))
        getAudioOutput().setVolume(refModel.getAudioVolume() / 100.0);
}
