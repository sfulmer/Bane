#include "LanguageComboBoxModel.h"
#include<QDebug>
#include <QVariant>

using namespace net::draconia::games::bane::ui::model;

LanguageComboBoxModel::LanguageComboBoxModel()
    :   QAbstractListModel()
    ,   mLstModel({{SettingsModel::Language("English", "EN"), SettingsModel::Language("Spanish","ES"), SettingsModel::Language("Portuguese", "PR"), SettingsModel::Language("Italian", "IT"), SettingsModel::Language("French", "FR"), SettingsModel::Language("Japanese", "JP"), SettingsModel::Language("Chinese", "CH")}})
{ }

LanguageComboBoxModel::~LanguageComboBoxModel()
{ }

QVariant LanguageComboBoxModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);

    if(abs(index.row()) <= rowCount())
        {
        QList<SettingsModel::Language> lstModel = const_cast<LanguageComboBoxModel &>(*this).getModel();
        QVariant objRetVal;

        objRetVal.setValue(lstModel[index.row()]);

        return(objRetVal);
        }
    else
        return(QVariant());
}

const QList<SettingsModel::Language> LanguageComboBoxModel::getModel()
{
    return(mLstModel);
}

int LanguageComboBoxModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    const QList<SettingsModel::Language> &lstModel = const_cast<LanguageComboBoxModel &>(*this).getModel();

    qDebug() << "There are " << lstModel.count() << " rows.";

    return(lstModel.count());
}
