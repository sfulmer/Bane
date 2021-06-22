#include "StatusEffect.h"

using namespace net::draconia::games::bane;

StatusEffect::StatusEffect()
{ }

StatusEffect::StatusEffect(const QString &sName)
    :   msName(sName)
{ }

StatusEffect::StatusEffect(const QString &sName, const QImage &imgAppearance)
    :   mImgAppearance(imgAppearance), msName(sName)
{ }

StatusEffect::StatusEffect(const StatusEffect &refCopy)
    :   StatusEffect(refCopy.getName(), refCopy.getAppearance())
{ }

StatusEffect::~StatusEffect()
{ }

QImage &StatusEffect::getAppearance() const
{
    return(const_cast<StatusEffect &>(*this).mImgAppearance);
}

QString &StatusEffect::getName() const
{
    return(const_cast<StatusEffect &>(*this).msName);
}

void StatusEffect::setAppearance(const QImage &imgAppearance)
{
    mImgAppearance = imgAppearance;
}

void StatusEffect::setName(const QString &sName)
{
    msName = sName;
}

StatusEffect &StatusEffect::operator=(const StatusEffect &refCopy)
{
    setName(refCopy.getName());
    setAppearance(refCopy.getAppearance());

    return(*this);
}

bool StatusEffect::operator==(const StatusEffect &refOther) const
{
    return  (   (getName() == refOther.getName())
            &&  (getAppearance() == refOther.getAppearance()));
}

bool StatusEffect::operator!=(const StatusEffect &refOther) const
{
    return(!operator==(refOther));
}
