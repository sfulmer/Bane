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
                class Target
                {
                    QList<Spell *> mLstSpells;
                public:
                    Target();
                    Target(const Spell &refSpell);
                    Target(const QList<Spell *> lstSpells);
                    Target(const Target &refCopy);
                    ~Target();

                    QList<Spell *> &getSpells() const;
                    void registerSpell(const Spell &refSpell);
                    void setSpells(const QList<Spell *> &lstSpell);
                    void unregisterSpell(const Spell &refSpell);

                    void castOnSelf();

                    Target &operator=(const Target &refCopy);
                    bool operator==(const Target &refOther) const;
                    bool operator!=(const Target &refOther) const;
                };
            }
        }
    }
}
