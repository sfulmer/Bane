#pragma once

#include "Attachable.h"
#include <initializer_list>
#include "Observable.h"
#include<QList>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class Weapon : public Attachable, public Observable
                {
                    QString msName;
                    QList<Spell *> mLstSpells;
                    unsigned muiModifier;
                public:
                    Weapon();
                    Weapon(const QString &sName, const unsigned uiModifier);
                    Weapon(const QString &sName, const unsigned uiModifier, const std::initializer_list<Spell *> lstSpells);
                    Weapon(const QString &sName, const unsigned uiModifier, const QList<Spell *> lstSpells);
                    Weapon(const Weapon &refCopy);

                    unsigned getModifier() const;
                    QString &getName() const;
                    QList<Spell *> &getSpells() const;
                    void setModifier(const unsigned uiModifier);
                    void setName(const QString &sName);
                    void setSpells(const QList<Spell *> &stSpells);

                    Weapon &operator=(const Weapon &refCopy);
                    bool operator==(const Weapon &refOther) const;
                    bool operator!=(const Weapon &refOther) const;
                };
            }
        }
    }
}
