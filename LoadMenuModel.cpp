#include "LoadMenuModel.h"

using namespace net::draconia::games::bane::ui::model;

LoadMenuModel::LoadMenuModel()
    :   muiSelectedIndex(0)
{ }

LoadMenuModel::LoadMenuModel(const QList<LoadMenuOption> &lstOptions, const unsigned &uiSelectedOption)
    :   mLstOptions(lstOptions)
    ,   muiSelectedIndex(uiSelectedOption)
{ }

LoadMenuModel::LoadMenuModel(const LoadMenuModel &refCopy)
    :   LoadMenuModel(refCopy.getOptions(), refCopy.getSelectedIndex())
{ }

LoadMenuModel::~LoadMenuModel()
{ }

void LoadMenuModel::addOption(const QString &sOption)
{
    getOptions().push_back(LoadMenuOption(getOptions().length(), sOption, true));

    setSelectedIndex(0);
}

void LoadMenuModel::addOption(const LoadMenuOption &objOption)
{
    getOptions().push_back(objOption);

    setSelectedIndex(0);
}

QList<LoadMenuOption> &LoadMenuModel::getOptions() const
{
    return(const_cast<LoadMenuModel &>(*this).mLstOptions);
}

unsigned LoadMenuModel::getSelectedIndex() const
{
    return(muiSelectedIndex);
}

void LoadMenuModel::setOptions(const QList<LoadMenuOption> &lstOptions)
{
    mLstOptions = lstOptions;
}

void LoadMenuModel::setSelectedIndex(const unsigned uiIndex)
{
    muiSelectedIndex = uiIndex;
}

LoadMenuModel &LoadMenuModel::operator=(const LoadMenuModel &refCopy)
{
    setOptions(refCopy.getOptions());
    setSelectedIndex(refCopy.getSelectedIndex());

    return(*this);
}

bool LoadMenuModel::operator==(const LoadMenuModel &refOther) const
{
    return  (   (getOptions() == refOther.getOptions())
            &&  (getSelectedIndex() == refOther.getSelectedIndex()));
}

bool LoadMenuModel::operator!=(const LoadMenuModel &refOther) const
{
    return(!operator==(refOther));
}
