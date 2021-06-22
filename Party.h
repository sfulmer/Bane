#pragma once

#include "Character.h"
#include "Item.h"
#include "Observable.h"
#include <QList>
#include <QMap>

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
                    class Party : public Observable
                    {
                        Point *mPtrPosition;
                        QList<Character> mLstCharacters;
                        QMap<Item, unsigned> mMapInventory;
                        quint64 muiMoney;
                    public:
                        Party();
                        Party(const Party &refCopy);
                        ~Party();

                        QList<Character> &getCharacters() const;
                        QMap<Item, unsigned> &getInventory() const;
                        quint64 &getMoney() const;
                        Point &getPosition();
                        void setCharacters(const QList<Character> &lstCharacters);
                        void setInventory(const QMap<Item, unsigned> mapInventory);
                        void setMoney(const quint64 uiMoney);
                        void setPosition(const Point &refPosition);

                        Party &operator=(const Party &refCopy);
                        bool operator==(const Party &refOther) const;
                        bool operator!=(const Party &refOther) const;
                    };
                }
            }
        }
    }
}
