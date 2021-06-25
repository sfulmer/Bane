#include "Enemy.h"

using namespace net::draconia::games::bane::model;

Enemy::Enemy()
    :   Character()
{ }

QList<Item> &Enemy::getLoot() const
{
    return(const_cast<Enemy &>(*this).mLstLoot);
}

void Enemy::setLoot(const QList<Item> &lstLoot)
{
    mLstLoot = lstLoot;
}
