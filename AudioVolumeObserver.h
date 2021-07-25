#pragma once

#include "Observable.h"
#include <QLabel>
#include <QSlider>

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
                    namespace  observers
                    {
                        class AudioVolumeObserver : public Observer
                        {
                            QLabel *mLblAudioVolume;
                            QSlider *mObjAudioVolume;
                        protected:
                            QLabel *getAudioVolumeLabel();
                            QSlider *getAudioVolumeSlider();
                            void setAudioVolumeLabel(const QLabel *lblAudioVolume);
                            void setAudioVolumeSlider(QSlider *objAudioVolume);
                        public:
                            AudioVolumeObserver(QLabel *lblAudioVolume, QSlider *objAudioVolume);
                            AudioVolumeObserver(const AudioVolumeObserver &refCopy);
                            virtual ~AudioVolumeObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
