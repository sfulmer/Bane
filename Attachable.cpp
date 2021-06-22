#include "Attachable.h"

using namespace net::draconia::games::bane;

void Attachable::setSpells(const QList<Spell *> &lstSpells)
{
    mLstSpells = lstSpells;
}

Attachable::~Attachable()
{ }

QList<Spell *> &Attachable::getSpells()
{
    return(mLstSpells);
}

void Attachable::attach(const Spell *ptrSpell)
{
    getSpells().push_back(const_cast<Spell *>(ptrSpell));
}
