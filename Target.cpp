#include "Target.h"

using namespace net::draconia::games::bane;

Target::Target()
{ }

Target::Target(const Spell &refSpell)
{
    getSpells().push_back(const_cast<Spell *>(&refSpell));
}

Target::Target(const QList<Spell *> lstSpells)
    :   mLstSpells(lstSpells)
{ }

Target::Target(const Target &refCopy)
    :   Target(refCopy.getSpells())
{ }

Target::~Target()
{ }

QList<Spell *> &Target::getSpells() const
{
    return(const_cast<Target &>(*this).mLstSpells);
}

void Target::registerSpell(const Spell &refSpell)
{
    getSpells().push_back(const_cast<Spell *>(&refSpell));
}

void Target::setSpells(const QList<Spell *> &lstSpells)
{
    getSpells().append(lstSpells);
}

void Target::unregisterSpell(const Spell &refSpell)
{
    getSpells().removeOne(const_cast<Spell *>(&refSpell));
}

void Target::castOnSelf()
{
    QList<Target *> targets;

    targets.push_back(this);

    for(Spell *ptrSpell : getSpells())
        ptrSpell->cast(targets);
}

Target &Target::operator=(const Target &refCopy)
{
    setSpells(refCopy.getSpells());

    return(*this);
}

bool Target::operator==(const Target &refOther) const
{
    return(getSpells() == refOther.getSpells());
}

bool Target::operator!=(const Target &refOther) const
{
    return(!operator==(refOther));
}
