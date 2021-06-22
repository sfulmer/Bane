#pragma once

#include "Character.h"
#include "Item.h"
#include<QList>

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
                    class Enemy : public Character
                    {
                        QList<Item> mLstLoot;
                    public:
                        Enemy();

                        QList<Item> &getLoot() const;
                        void setLoot(const QList<Item> &lstLoot);
                    };
                }
            }
        }
    }
}
