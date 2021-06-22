#pragma once

#include<initializer_list>
#include "MenuOption.h"
#include "Observable.h"
#include<QColor>
#include<QList>

using net::draconia::util::Observable;

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
                    namespace model
                    {
                        class Menu : public Observable
                        {
                            QColor mClrBackground, mClrForeground, mClrSelBack, mClrSelFore;
                            QList<MenuOption> mLstOptions;
                        public:
                            Menu();
                            Menu(const QList<MenuOption> lstOptions, const QColor clrBack, const QColor clrFore, const QColor clrSelBack, const QColor clrSelFore);
                            Menu(const Menu &refCopy);
                            ~Menu();

                            QColor &getBackgroundColor() const;
                            QColor &getForegroundColor() const;
                            QList<MenuOption> &getOptions() const;
                            QColor &getSelectedBackgroundColor() const;
                            QColor &getSelectedForegroundColor() const;
                            void setBackgroundColor(const QColor clrBackground);
                            void setForegroundColor(const QColor clrForeground);
                            void setOptions(const QList<MenuOption> &lstOptions);
                            void setSelectedBackgroundColor(const QColor clrSelBack);
                            void setSelectedForegroundColor(const QColor clrSelFore);

                            Menu &operator=(const Menu &refCopy);
                            bool operator==(const Menu &refOther) const;
                            bool operator!=(const Menu &refOther) const;
                        };
                    }
                }
            }
        }
    }
}
