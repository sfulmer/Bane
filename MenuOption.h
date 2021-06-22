#pragma once

#include "Observable.h"
#include <QString>

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
                        class MenuOption : public Observable
                        {
                            bool mbVisible;
                            unsigned muiIndex;
                            QString msText;
                        public:
                            MenuOption();
                            MenuOption(const unsigned uiIndex, const QString sText);
                            MenuOption(const MenuOption &refCopy);
                            ~MenuOption();

                            unsigned getIndex() const;
                            QString getText() const;
                            bool isVisible() const;
                            void setIndex(const unsigned uiIndex);
                            void setText(const QString sText);
                            void setVisible(const bool bVisible);

                            MenuOption &operator=(const MenuOption &refCopy);
                            bool operator==(const MenuOption &refOther) const;
                            bool operator!=(const MenuOption &refOther) const;
                        };
                    }
                }
            }
        }
    }
}
