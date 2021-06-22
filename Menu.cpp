#include "Menu.h"

using namespace net::draconia::games::bane::ui::model;

Menu::Menu()
    :   Observable()
{ }

Menu::Menu(const QList<MenuOption> lstOptions, const QColor clrBack, const QColor clrFore, const QColor clrSelBack, const QColor clrSelFore)
    :   Observable()
    ,   mClrBackground(clrBack)
    ,   mClrForeground(clrFore)
    ,   mClrSelBack(clrSelBack)
    ,   mClrSelFore(clrSelFore)
    ,   mLstOptions(lstOptions)
{ }

Menu::Menu(const Menu &refCopy)
    :   Menu(refCopy.getOptions(), refCopy.getForegroundColor(), refCopy.getBackgroundColor(), refCopy.getSelectedBackgroundColor(), refCopy.getSelectedForegroundColor())
{ }

Menu::~Menu()
{ }

QColor &Menu::getBackgroundColor() const
{
    return(const_cast<Menu &>(*this).mClrBackground);
}

QColor &Menu::getForegroundColor() const
{
    return(const_cast<Menu &>(*this).mClrForeground);
}

QList<MenuOption> &Menu::getOptions() const
{
    return(const_cast<Menu &>(*this).mLstOptions);
}

QColor &Menu::getSelectedBackgroundColor() const
{
    return(const_cast<Menu &>(*this).mClrSelBack);
}

QColor &Menu::getSelectedForegroundColor() const
{
    return(const_cast<Menu &>(*this).mClrSelFore);
}

void Menu::setBackgroundColor(const QColor clrBackground)
{
    mClrBackground = clrBackground;

    setChanged();
    notifyObservers("Background");
}

void Menu::setForegroundColor(const QColor clrForeground)
{
    mClrForeground = clrForeground;

    setChanged();
    notifyObservers("Foreground");
}

void Menu::setOptions(const QList<MenuOption> &lstOptions)
{
    mLstOptions = lstOptions;

    setChanged();
    notifyObservers("Options");
}

void Menu::setSelectedBackgroundColor(const QColor clrSelBack)
{
    mClrSelBack = clrSelBack;

    setChanged();
    notifyObservers("SelectedBackground");
}

void Menu::setSelectedForegroundColor(const QColor clrSelFore)
{
    mClrSelFore = clrSelFore;

    setChanged();
    notifyObservers("SelectedForeground");
}

Menu &Menu::operator=(const Menu &refCopy)
{
    setBackgroundColor(refCopy.getBackgroundColor());
    setForegroundColor(refCopy.getForegroundColor());
    setOptions(refCopy.getOptions());
    setSelectedBackgroundColor(refCopy.getSelectedBackgroundColor());
    setSelectedForegroundColor(refCopy.getSelectedForegroundColor());

    return(*this);
}

bool Menu::operator==(const Menu &refOther) const
{
    return  (   (getBackgroundColor() == refOther.getBackgroundColor())
            &&  (getForegroundColor() == refOther.getForegroundColor())
            &&  (getOptions() == refOther.getOptions())
            &&  (getSelectedBackgroundColor() == refOther.getSelectedBackgroundColor())
            &&(getSelectedForegroundColor() == refOther.getSelectedForegroundColor()));
}

bool Menu::operator!=(const Menu &refOther) const
{
    return(!operator==(refOther));
}
