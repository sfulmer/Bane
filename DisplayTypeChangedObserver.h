#pragma once

#include "Observable.h"
#include <QComboBox>
#include "SettingsModel.h"

using namespace net::draconia::util;
using net::draconia::games::bane::model::SettingsModel;

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
