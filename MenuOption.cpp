#include "MenuOption.h"

using namespace net::draconia::games::bane::ui::model;

MenuOption::MenuOption()
    :   Observable(), muiIndex(0)
{ }

MenuOption::MenuOption(const unsigned uiIndex, const QString sText)
    :   Observable(), muiIndex(uiIndex), msText(sText)
{ }

MenuOption::MenuOption(const MenuOption &refCopy)
    :   MenuOption(refCopy.getIndex(), refCopy.getText())
{ }

MenuOption::~MenuOption()
{ }

unsigned MenuOption::getIndex() const
{
    return(muiIndex);
}

QString MenuOption::getText() const
{
    return(msText);
}

bool MenuOption::isVisible() const
{
    return(mbVisible);
}

void MenuOption::setIndex(const unsigned uiIndex)
{
    muiIndex = uiIndex;

    setChanged();
    notifyObservers("Index");
}

void MenuOption::setText(const QString sText)
{
    msText = sText;

    setChanged();
    notifyObservers("Text");
}

void MenuOption::setVisible(const bool bVisible)
{
    mbVisible = bVisible;

    setChanged();
    notifyObservers("Visible");
}

MenuOption &MenuOption::operator=(const MenuOption &refCopy)
{
    setIndex(refCopy.getIndex());
    setText(refCopy.getText());
    setVisible(refCopy.isVisible());

    return(*this);
}

bool MenuOption::operator==(const MenuOption &refOther) const
{
    return  (   (getText() == refOther.getText())
            &&  (getIndex() == refOther.getIndex()));
}

bool MenuOption::operator!=(const MenuOption &refOther) const
{
    return(!operator==(refOther));
}
