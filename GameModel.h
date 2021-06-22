#pragma once

#include "Character.h"
#include "MenuOption.h"
#include "Observable.h"
#include "Party.h"
#include <QList>

using net::draconia::util::Observable;
using net::draconia::games::bane::ui::model::MenuOption;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace model
                {
                    class GameModel : public Observable
                    {
                        bool mbInMenu, mbPaused, mbStarted;
                        MenuOption *mPtrSelectedMenuOption;
                        Party mObjParty;
                        QList<Character> mLstActiveParty;
                    public:
                        GameModel();
                        ~GameModel();

                        QList<Character> &getActiveParty() const;
                        Party &getParty() const;
                        MenuOption *getSelectedMenuOption() const;
                        bool isInMenu() const;
                        bool isPaused() const;
                        bool isStarted() const;
                        void setActiveParty(const QList<Character> &lstActiveParty);
                        void setInMenu(const bool bInMenu);
                        void setParty(const Party &refParty);
                        void setPaused(const bool bPaused);
                        void setSelectedMenuOption(const MenuOption *ptrMenuOption);
                        void setStarted(const bool bStarted);
                    };
                }
            }
        }
    }
}
