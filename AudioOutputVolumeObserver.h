#pragma once

#include "Observable.h"
#include <QAudioOutput>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace ui
                {
                    namespace observers
                    {
                        class AudioOutputVolumeObserver : public Observer
                        {
                            QAudioOutput &mRefAudioOutput;
                        protected:
                            QAudioOutput &getAudioOutput() const;
                        public:
                            AudioOutputVolumeObserver(const QAudioOutput &objAudioOutput);
                            AudioOutputVolumeObserver(const AudioOutputVolumeObserver &refCopy);
                            virtual ~AudioOutputVolumeObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
