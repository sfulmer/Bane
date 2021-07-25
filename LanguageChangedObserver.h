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
                        class LanguageChangedObserver : public Observer
                        {
                            QComboBox *mCboLanguage;
                        protected:
                            QComboBox *getLanguageComboBox() const;
                            void setLanguageComboBox(const QComboBox *cboLanguage);
                        public:
                            LanguageChangedObserver(const QComboBox *cboLanguage);
                            LanguageChangedObserver(const LanguageChangedObserver &refCopy);
                            virtual ~LanguageChangedObserver();

                            virtual void update(const Observable &refObservable, const QString &sProperty);
                        };
                    }
                }
            }
        }
    }
}
