#pragma once

#include "Observable.h"
#include <QComboBox>

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
                        class VideoResolutionChangedObserver : public Observer
                        {
                            QComboBox *mCboVideoResolutions;
                        protected:
                            QComboBox *getVideoResolutionsComboBox() const;
                            void setVideoResolutionsComboBox(const QComboBox *cboVideoResolutions);
                        public:
                            VideoResolutionChangedObserver(const QComboBox *cboideoResolutions);
                            VideoResolutionChangedObserver(const VideoResolutionChangedObserver &refCopy);
                            virtual ~VideoResolutionChangedObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
