#pragma once

#include "Observable.h"
#include "Point.h"
#include "Target.h"

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace model
                {
                    class Character : public Observable, public Target
                    {
                        int miAgility, miConstitution, miDexterity, miIntelligence, miStrength;
                        unsigned muiHitPoints, muiMagicPoints, muiMaxHitPoints, muiMaxMagicPoints;
                    public:
                        Character();
                        Character(const int iAgility, const int iConstitution, const int iDexterity, const int iIntelligence, const int iStrength);
                        Character(const Character &refCopy);
                        ~Character();

                        int getAgility() const;
                        int getConstitution() const;
                        unsigned getCurrentHitPoints() const;
                        unsigned getCurrentMagicPoints() const;
                        unsigned getDefense() const;
                        int getDexterity() const;
                        int getIntelligence() const;
                        unsigned getMagic() const;
                        unsigned getMaxHitPoints() const;
                        unsigned getMaxMagicPoints() const;
                        unsigned getSpellResistance() const;
                        int getStrength() const;
                        void setAgility(const int iAgility);
                        void setConstitution(const int iConstitution);
                        void setCurrentHitPoints(const unsigned uiHitPoints);
                        void setCurrentMagicPoints(const unsigned uiMagicPoints);
                        void setDexterity(const int iDexterity);
                        void setIntelligence(const int iIntelligence);
                        void setMaxHitPoints(const unsigned uiHitPoints);
                        void setMaxMagicPoints(const unsigned uiMagicPoints);
                        void setStrength(const int iStrength);

                        Character &operator=(const Character &refCopy);
                        bool operator==(const Character &refOther) const;
                        bool operator!=(const Character &refOther) const;
                    };

                }
            }
        }
    }
}
