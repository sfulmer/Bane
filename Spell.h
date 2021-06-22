#pragma once

#include "Observable.h"
#include <QString>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
                {
                class Target;

                class Spell : public Observable
                {
                    QString msName;
                    unsigned muiCost;
                public:
                    Spell(const QString &sName, const unsigned uiCost);
                    Spell(const Spell &refCopy);
                    virtual ~Spell();

                    unsigned getCost() const;
                    QString &getName() const;
                    void setCost(const unsigned uiCost);
                    void setName(const QString &sName);

                    Spell &operator=(const Spell &refCopy);
                    bool operator==(const Spell &refOther) const;
                    bool operator!=(const Spell &refOther) const;

                    virtual void cast(const QList<Target *> &refTargets) = 0;
                };
            }
        }
    }
}
