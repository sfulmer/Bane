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
                        class DisplayTypeChangedObserver : public Observer
                        {
                            QComboBox *mCboDisplayType;
                        protected:
                            QComboBox *getDisplayTypeComboBox() const;
                            void setDisplayTypeComboBox(const QComboBox *cboDisplayType);
                        public:
                            DisplayTypeChangedObserver(const QComboBox *cboDisplayType);
                            DisplayTypeChangedObserver(const DisplayTypeChangedObserver &refCopy);
                           virtual ~DisplayTypeChangedObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
