#include "Weapon.h"

using namespace net::draconia::games::bane;

Weapon::Weapon()
    :   Attachable(), Observable()
{ }

Weapon::Weapon(const QString &sName, const unsigned uiModifier)
    :   Attachable(), Observable()
    ,   msName(sName), muiModifier(uiModifier)
{ }

Weapon::Weapon(const QString &sName, const unsigned uiModifier, const std::initializer_list<Spell *> lstSpells)
    :   Weapon(sName, uiModifier, QList<Spell *>(lstSpells))
{ }

Weapon::Weapon(const QString &sName, const unsigned uiModifier, const QList<Spell *> lstSpells)
    :   Attachable(), Observable()
    ,   msName(sName), mLstSpells(lstSpells), muiModifier(uiModifier)
{ }

Weapon::Weapon(const Weapon &refCopy)
    :   Weapon(refCopy.getName(), refCopy.getModifier(), refCopy.getSpells())
{ }

unsigned Weapon::getModifier() const
{
    return(muiModifier);
}

QString &Weapon::getName() const
{
    return(const_cast<Weapon &>(*this).msName);
}

QList<Spell *> &Weapon::getSpells() const
{
    return(const_cast<Weapon &>(*this).mLstSpells);
}

void Weapon::setModifier(const unsigned uiModifier)
{
    muiModifier = uiModifier;

    setChanged();
    notifyObservers("Modifier");
}

void Weapon::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Weapon::setSpells(const QList<Spell *> &lstSpells)
{
    mLstSpells = lstSpells;

    setChanged();
    notifyObservers("Spells");
}

Weapon &Weapon::operator=(const Weapon &refCopy)
{
    setName(refCopy.getName());
    setModifier(refCopy.getModifier());
    setSpells(refCopy.getSpells());

    return(*this);
}

bool Weapon::operator==(const Weapon &refOther) const
{
    return  (   (getName() == refOther.getName())
            &&  (getModifier() == refOther.getModifier())
            &&  (getSpells() == refOther.getSpells()));
}

bool Weapon::operator!=(const Weapon &refOther) const
{
    return(!operator==(refOther));
}
