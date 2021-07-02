#include "LoadMenuOption.h"

using namespace net::draconia::games::bane::ui::model;

LoadMenuOption::LoadMenuOption()
    :   mbEnabled(false)
{ }

LoadMenuOption::LoadMenuOption(const unsigned uiIndex, const QString &sName, const bool bEnabled)
    :   mbEnabled(bEnabled)
    ,   msName(sName)
    ,   muiIndex(uiIndex)
{ }

LoadMenuOption::LoadMenuOption(const QString &sName, const bool bEnabled)
    :   LoadMenuOption(0, sName, bEnabled)
{ }

LoadMenuOption::LoadMenuOption(const LoadMenuOption &refCopy)
    :   LoadMenuOption(refCopy.getIndex(), refCopy.getName(), refCopy.isEnabled())
{ }

LoadMenuOption::~LoadMenuOption()
{ }

unsigned LoadMenuOption::getIndex() const
{
    return(muiIndex);
}

QString &LoadMenuOption::getName() const
{
    return(const_cast<LoadMenuOption &>(*this).msName);
}

bool LoadMenuOption::isEnabled() const
{
    return(mbEnabled);
}

void LoadMenuOption::setEnabled(const bool bEnabled)
{
    mbEnabled = bEnabled;
}

void LoadMenuOption::setIndex(const unsigned uiIndex)
{
    muiIndex = uiIndex;
}

void LoadMenuOption::setName(const QString &sName)
{
    msName = sName;
}

LoadMenuOption &LoadMenuOption::operator=(const LoadMenuOption &refCopy)
{
    setIndex(refCopy.getIndex());
    setName(refCopy.getName());
    setEnabled(refCopy.isEnabled());

    return(*this);
}

bool LoadMenuOption::operator==(const LoadMenuOption &refOther) const
{
    return  (   (getIndex() == refOther.getIndex())
            &&  (getName() == refOther.getName())
            &&  (isEnabled() == refOther.isEnabled()));
}

bool LoadMenuOption::operator!=(const LoadMenuOption &refOther) const
{
    return(!operator==(refOther));
}

bool LoadMenuOption::operator>(const LoadMenuOption &refOther) const
{
    return(getIndex() > refOther.getIndex());
}

bool LoadMenuOption::operator>=(const LoadMenuOption &refOther) const
{
    return(getIndex() >= refOther.getIndex());
}

bool LoadMenuOption::operator<(const LoadMenuOption &refOther) const
{
    return(getIndex() < refOther.getIndex());
}

bool LoadMenuOption::operator<=(const LoadMenuOption &refOther) const
{
    return(getIndex() <= refOther.getIndex());
}
