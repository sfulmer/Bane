#include "GameModel.h"

using namespace net::draconia::games::bane::model;

GameModel::GameModel()
    :   Observable()
{ }

GameModel::~GameModel()
{ }

QList<Character> &GameModel::getActiveParty() const
{
    return(const_cast<GameModel &>(*this).mLstActiveParty);
}

Party &GameModel::getParty() const
{
    return(const_cast<GameModel &>(*this).mObjParty);
}

MenuOption *GameModel::getSelectedMenuOption() const
{
    return(mPtrSelectedMenuOption);
}

bool GameModel::isInMenu() const
{
    return(mbInMenu);
}

bool GameModel::isPaused() const
{
    return(mbPaused);
}

bool GameModel::isStarted() const
{
    return(mbStarted);
}

void GameModel::setActiveParty(const QList<Character> &lstActiveParty)
{
    mLstActiveParty = lstActiveParty;

    setChanged();
    notifyObservers("ActiveParty");
}

void GameModel::setInMenu(const bool bInMenu)
{
    mbInMenu = bInMenu;

    setChanged();
    notifyObservers("InMenu");
}

void GameModel::setParty(const Party &objParty)
{
    mObjParty = objParty;

    setChanged();
    notifyObservers("Party");
}

void GameModel::setPaused(const bool bPaused)
{
    mbPaused = bPaused;

    setChanged();
    notifyObservers("Paused");
}

void GameModel::setSelectedMenuOption(const MenuOption *ptrMenuOption)
{
    mPtrSelectedMenuOption = const_cast<MenuOption *>(ptrMenuOption);

    setChanged();
    notifyObservers("SelectedMenuOption");
}

void GameModel::setStarted(const bool bStarted)
{
    mbStarted = bStarted;

    setChanged();
    notifyObservers("Started");
}
