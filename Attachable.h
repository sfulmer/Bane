#pragma once

#include <QList>
#include "Spell.h"

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class Attachable
                {
                    QList<Spell *> mLstSpells;
                protected:
                    void setSpells(const QList<Spell *> &lstSpells);
                public:
                    virtual ~Attachable();

                    QList<Spell *> &getSpells();

                    virtual void attach(const Spell *ptrSpell);
                };
            }
        }
    }
}
