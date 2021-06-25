#include "Armor.h"

using namespace net::draconia::games::bane;

Armor::Armor()
    :   Observable()
{ }

Armor::Armor(const Types eType, const QString &sName, const unsigned uiModifier)
    :   Observable(), msName(sName), meType(eType), muiModifier(uiModifier)
{ }

Armor::Armor(const Armor &refCopy)
    :   Armor(refCopy.getType(), refCopy.getName(), refCopy.getModifier())
{ }

Armor::~Armor()
{ }

unsigned Armor::getModifier() const
{
    return(muiModifier);
}

QString &Armor::getName() const
{
    return(const_cast<Armor &>(*this).msName);
}

Armor::Types Armor::getType() const
{
    return(meType);
}

void Armor::setModifier(const unsigned uiModifier)
{
    muiModifier = uiModifier;

    setChanged();
    notifyObservers("Modifier");
}

void Armor::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Armor::setType(const Types eType)
{
    meType = eType;

    setChanged();
    notifyObservers("Type");
}

Armor &Armor::operator=(const Armor &refCopy)
{
    setName(refCopy.getName());
    setModifier(refCopy.getModifier());
    setType(refCopy.getType());

    return(*this);
}

bool Armor::operator==(const Armor &refOther) const
{
    return  (   (getName() == refOther.getName())
            &&  (getModifier() == refOther.getModifier())
            &&  (getType() == refOther.getType()));
}

bool Armor::operator!=(const Armor &refOther) const
{
    return(!operator==(refOther));
}
