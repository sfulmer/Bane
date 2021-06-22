#pragma once

#include "Attachable.h"
#include "Observable.h"
#include <QList>
#include <QString>
#include "Spell.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class Armor : public Attachable, public Observable
                {
                public:
                    enum Types { HEAD, ARMS, TORSO, LEGS };
                private:
                    QString msName;
                    QList<Spell *> mPtrSpells;
                    Types meType;
                    unsigned muiModifier;
                public:
                    Armor();
                    Armor(const Types eType, const QString &sName, const unsigned uiModifier);
                    Armor(const Armor &refCopy);
                    ~Armor();

                    unsigned getModifier() const;
                    QString &getName() const;
                    Types getType() const;
                    void setModifier(const unsigned uiModifier);
                    void setName(const QString &sName);
                    void setType(const Types eType);

                    Armor &operator=(const Armor &refCopy);
                    bool operator==(const Armor &refOther) const;
                    bool operator!=(const Armor &refOther) const;
                };
            }
        }
    }
}
