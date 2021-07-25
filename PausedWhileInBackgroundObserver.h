#pragma once

#include "Observable.h"
#include <QCheckBox>

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
                        class PausedWhileInBackgroundObserver : public Observer
                        {
                            QCheckBox *mChkPausedWhileInBackground;
                        protected:
                            QCheckBox *getPausedWhileInBackgroundCheckBox() const;
                            void setPausedWhileInBackgroundCheckBox(const QCheckBox *chkPausedWhileInBackround);
                        public:
                            PausedWhileInBackgroundObserver(const QCheckBox *chkPausedWhileInBackground);
                            PausedWhileInBackgroundObserver(const PausedWhileInBackgroundObserver &refCopy);
                            virtual ~PausedWhileInBackgroundObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
