#include "LoadMenu.h"

using namespace net::draconia::games::bane::ui::model;

LoadMenu::LoadMenu()
    :   muiSelectedIndex(0)
{ }

LoadMenu::LoadMenu(const QList<LoadMenu::Option> &lstOptions, const unsigned &uiSelectedOption)
    :   mLstOptions(lstOptions)
    ,   muiSelectedIndex(uiSelectedOption)
{ }

LoadMenu::LoadMenu(const LoadMenu &refCopy)
    :   LoadMenu(refCopy.getOptions(), refCopy.getSelectedIndex())
{ }

LoadMenu::~LoadMenu()
{ }

void LoadMenu::addOption(const QString &sOption)
{
    getOptions().push_back(LoadMenu::Option(getOptions().length(), sOption, true));

    setSelectedIndex(0);
}

void LoadMenu::addOption(const LoadMenu::Option &objOption)
{
    getOptions().push_back(objOption);

    setSelectedIndex(0);
}

QList<LoadMenu::Option> &LoadMenu::getOptions() const
{
    return(const_cast<LoadMenu &>(*this).mLstOptions);
}

unsigned LoadMenu::getSelectedIndex() const
{
    return(muiSelectedIndex);
}

void LoadMenu::setOptions(const QList<LoadMenu::Option> &lstOptions)
{
    mLstOptions = lstOptions;
}

void LoadMenu::setSelectedIndex(const unsigned uiIndex)
{
    muiSelectedIndex = uiIndex;
}

LoadMenu &LoadMenu::operator=(const LoadMenu &refCopy)
{
    setOptions(refCopy.getOptions());
    setSelectedIndex(refCopy.getSelectedIndex());

    return(*this);
}

bool LoadMenu::operator==(const LoadMenu &refOther) const
{
    return  (   (getOptions() == refOther.getOptions())
            &&  (getSelectedIndex() == refOther.getSelectedIndex()));
}

bool LoadMenu::operator!=(const LoadMenu &refOther) const
{
    return(!operator==(refOther));
}

void LoadMenu::render(const QPainter &refPainter)
{
    QPainter &painter = const_cast<QPainter &>(refPainter);

    painter.save();


    painter.restore();
}

LoadMenu::Option::Option()
    :   Observable()
    ,   muiIndex(0)
{ }

LoadMenu::Option::Option(const unsigned uiIndex, const QString &sName, const bool bEnabled)
    :   Observable()
    ,   mbEnabled(bEnabled)
    ,   msName(sName)
    ,   muiIndex(uiIndex)
{ }

LoadMenu::Option::Option(const QString &sName, const bool bEnabled)
    :   Observable()
    ,   mbEnabled(bEnabled)
    ,   msName(sName)
    ,   muiIndex(0)
{ }

LoadMenu::Option::Option(const Option &refCopy)
    :   LoadMenu::Option(refCopy.getIndex(), refCopy.getName(), refCopy.isEnabled())
{ }

LoadMenu::Option::~Option()
{ }

unsigned LoadMenu::Option::getIndex() const
{
    return(muiIndex);
}

QString &LoadMenu::Option::getName() const
{
    return(const_cast<LoadMenu::Option &>(*this).msName);
}

bool LoadMenu::Option::isEnabled() const
{
    return(const_cast<LoadMenu::Option &>(*this).mbEnabled);
}

void LoadMenu::Option::setEnabled(const bool bEnabled)
{
    mbEnabled = bEnabled;

    setChanged(true);
    notifyObservers("Enabled");
}

void LoadMenu::Option::setIndex(const unsigned uiIndex)
{
    muiIndex = uiIndex;

    setChanged(true);
    notifyObservers("Index");
}

void LoadMenu::Option::setName(const QString &sName)
{
    msName = sName;

    setChanged(true);
    notifyObservers("Name");
}

LoadMenu::Option &LoadMenu::Option::operator=(const LoadMenu::Option &refCopy)
{
    setIndex(refCopy.getIndex());
    setName(refCopy.getName());
    setEnabled(refCopy.isEnabled());

    return(*this);
}

bool LoadMenu::Option::operator==(const LoadMenu::Option &refOther) const
{
    return  (   Observable::operator==(refOther)
            &&  (getIndex() == refOther.getIndex())
            &&  (getName() == refOther.getName())
            &&  isEnabled() == refOther.isEnabled());
}

bool LoadMenu::Option::operator!=(const LoadMenu::Option &refOther) const
{
    return(!operator==(refOther));
}

bool LoadMenu::Option::operator>(const LoadMenu::Option &refOther) const
{
    if(getName() == refOther.getName())
        return(getIndex() > refOther.getIndex());
    else
        return(getName() > refOther.getName());
}

bool LoadMenu::Option::operator>=(const LoadMenu::Option &refOther) const
{
    if(getName() == refOther.getName())
        return(getIndex() >= refOther.getIndex());
    else
        return(getName() >= refOther.getName());
}

bool LoadMenu::Option::operator<(const LoadMenu::Option &refOther) const
{
    return(!operator>=(refOther));
}

bool LoadMenu::Option::operator<=(const LoadMenu::Option &refOther) const
{
    return(!operator>(refOther));
}
