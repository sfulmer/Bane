#include "Character.h"

using namespace net::draconia::games::bane::model;

Character::Character()
    :   Character(0, 0, 0, 0, 0)
{ }

Character::Character(const int iAgility, const int iConstitution, const int iDexterity, const int iIntelligence, const int iStrength)
    :   miAgility(iAgility), miConstitution(iConstitution), miDexterity(iDexterity), miIntelligence(iIntelligence), miStrength(iStrength)
{ }

Character::Character(const Character &refCopy)
    :   Character(refCopy.getAgility(), refCopy.getConstitution(), refCopy.getDexterity(), refCopy.getIntelligence(), refCopy.getStrength())
{ }

Character::~Character()
{ }

int Character::getAgility() const
{
    return(miAgility);
}

int Character::getConstitution() const
{
    return(miConstitution);
}

unsigned Character::getDefense() const
{
    return(0);
}

int Character::getDexterity() const
{
    return(miDexterity);
}

int Character::getIntelligence() const
{
    return(miIntelligence);
}

unsigned Character::getMagic() const
{
    return(0);
}

unsigned Character::getSpellResistance() const
{
    return(0);
}

int Character::getStrength() const
{
    return(miStrength);
}

void Character::setAgility(const int iAgility)
{
    miAgility = iAgility;

    setChanged();
    notifyObservers("Agility");
}

void Character::setConstitution(const int iConstitution)
{
    miConstitution = iConstitution;

    setChanged();
    notifyObservers("Constitution");
}

void Character::setDexterity(const int iDexterity)
{
    miDexterity = iDexterity;

    setChanged();
    notifyObservers("Dexterity");
}

void Character::setIntelligence(const int iIntelligence)
{
    miIntelligence = iIntelligence;

    setChanged();
    notifyObservers("Intelligence");
}

void Character::setStrength(const int iStrength)
{
    miStrength = iStrength;

    setChanged();
    notifyObservers("Strength");
}

Character &Character::operator=(const Character &refCopy)
{
    setAgility(refCopy.getAgility());
    setConstitution(refCopy.getConstitution());
    setDexterity(refCopy.getDexterity());
    setIntelligence(refCopy.getIntelligence());
    setStrength(refCopy.getStrength());

    return(*this);
}

bool Character::operator==(const Character &refOther) const
{
    return  (   (getAgility() == refOther.getAgility())
            &&  (getConstitution() == refOther.getConstitution())
            &&  (getDexterity() == refOther.getDexterity())
            &&  (getIntelligence() == refOther.getIntelligence())
            &&  (getStrength() == refOther.getStrength()));
}

bool Character::operator!=(const Character &refOther) const
{
    return(!operator==(refOther));
}
