#include "Spell.h"

using namespace net::draconia::games::bane;

Spell::Spell(const QString &sName, const unsigned uiCost)
    :   msName(sName), muiCost(uiCost)
{ }

Spell::Spell(const Spell &refCopy)
    :   Spell(refCopy.getName(), refCopy.getCost())
{ }

Spell::~Spell()
{ }

unsigned Spell::getCost() const
{
    return(muiCost);
}

QString &Spell::getName() const
{
    return(const_cast<Spell &>(*this).msName);
}

void Spell::setCost(const unsigned uiCost)
{
    muiCost = uiCost;

    setChanged();
    notifyObservers("Cost");
}

void Spell::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

Spell &Spell::operator=(const Spell &refCopy)
{
    setName(refCopy.getName());
    setCost(refCopy.getCost());

    return(*this);
}

bool Spell::operator==(const Spell &refOther) const
{
    return  (   (getName() == refOther.getName())
            &&  (getCost() == refOther.getCost()));
}

bool Spell::operator!=(const Spell &refOther) const
{
    return(!operator==(refOther));
}
