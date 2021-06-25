#include "Item.h"

using namespace net::draconia::games::bane::model;

Item::Item()
  :   Observable()
  ,   miCost(0)
{ }

Item::Item(const QString sName, const int iCost)
  : Observable()
  , msName(sName)
  , miCost(iCost)
{ }

Item::Item(const QString sName, const int iCost, const QImage &imgThumbnail)
  : Observable()
  , mImgThumbnail(imgThumbnail)
  , msName(sName)
  , miCost(iCost)
{ }

Item::Item(const Item &refCopy)
  : Item(refCopy.getName(), refCopy.getCost())
{ }

Item::~Item()
{ }

int Item::getCost() const
{
    return(miCost);
}

QString &Item::getName() const
{
    return(const_cast<Item &>(*this).msName);
}

QImage &Item::getThumbnail() const
{
    return(const_cast<Item &>(*this).mImgThumbnail);
}

void Item::setCost(const int iCost)
{
    miCost = iCost;

    setChanged();
    notifyObservers("Cost");
}

void Item::setName(const QString sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Item::setThumbnail(const QImage &imgThumbnail)
{
    mImgThumbnail = imgThumbnail;

    setChanged();
    notifyObservers("Thumbnail");
}

Item &Item::operator=(const Item &refCopy)
{
    setName(refCopy.getName());
    setCost(refCopy.getCost());
    setThumbnail(refCopy.getThumbnail());

    return(*this);
}

bool Item::operator==(const Item &refOther) const
{
    return  (   (getName() == refOther.getName())
            &&  (getCost() == refOther.getCost())
            &&  (getThumbnail() == refOther.getThumbnail()));
}

bool Item::operator!=(const Item &refOther) const
{
    return(!operator==(refOther));
}

bool Item::operator>(const Item &refOther) const
{
    return(getName() > refOther.getName());
}

bool Item::operator>=(const Item &refOther) const
{
    return(getName() >= refOther.getName());
}

bool Item::operator<(const Item &refOther) const
{
    return(getName() < refOther.getName());
}

bool Item::operator<=(const Item &refOther) const
{
    return(getName() <= refOther.getName());
}
