#include "Party.h"

using namespace net::draconia::games::bane::model;

Party::Party()
    :   muiMoney(0)
{ }

Party::Party(const Party &refCopy)
    :   mLstCharacters(refCopy.getCharacters())
    ,   mMapInventory(refCopy.getInventory())
    ,   muiMoney(refCopy.getMoney())
{ }

Party::~Party()
{ }

QList<Character> &Party::getCharacters() const
{
    return(const_cast<Party &>(*this).mLstCharacters);
}

QMap<Item, unsigned> &Party::getInventory() const
{
    return(const_cast<Party &>(*this).mMapInventory);
}

quint64 &Party::getMoney() const
{
    return(const_cast<Party &>(*this).muiMoney);
}

Point &Party::getPosition()
{
    if(mPtrPosition == nullptr)
        mPtrPosition = new Point();

    return(*mPtrPosition);
}

void Party::setCharacters(const QList<Character> &lstCharacters)
{
    mLstCharacters = lstCharacters;

    setChanged();
    notifyObservers("Characters");
}

void Party::setInventory(const QMap<Item, unsigned> mapInventory)
{
    mMapInventory = mapInventory;

    setChanged();
    notifyObservers("Inventory");
}

void Party::setMoney(const quint64 uiMoney)
{
    muiMoney = uiMoney;

    setChanged();
    notifyObservers("Money");
}

void Party::setPosition(const Point &refPosition)
{
    mPtrPosition = const_cast<Point *>(&refPosition);

    setChanged();
    notifyObservers("Position");
}

Party &Party::operator=(const Party &refCopy)
{
    setCharacters(refCopy.getCharacters());
    setInventory(refCopy.getInventory());
    setMoney(refCopy.getMoney());
    setPosition(const_cast<Party &>(refCopy).getPosition());

    return(*this);
}

bool Party::operator==(const Party &refOther) const
{
    return  (   (getCharacters() == refOther.getCharacters())
            &&  (getInventory() == refOther.getInventory())
            &&  (getMoney() == refOther.getMoney())
            &&  (const_cast<Party &>(*this).getPosition() == const_cast<Party &>(refOther).getPosition()));
}

bool Party::operator!=(const Party &refOther) const
{
    return(!operator==(refOther));
}
