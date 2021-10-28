#include "ItemModel.h"
#include "SettingsModel.h"

using namespace net::draconia::games::bane::ui::model;

template<typename T>
QList<T> ItemModel<T>::getModel() const
{
    return(mLstModel);
}

template<typename T>
ItemModel<T>::ItemModel()
{ }

template<typename T>
ItemModel<T>::ItemModel(const std::initializer_list<T> lstModel)
    :   mLstModel(lstModel)
{ }

template<typename T>
ItemModel<T>::ItemModel(const QList<T> &lstModel)
    :   mLstModel(lstModel)
{ }

template<typename T>
ItemModel<T>::ItemModel(const ItemModel<T> &refCopy)
    :   ItemModel<T>(const_cast<ItemModel<T> &>(refCopy).getModel())
{ }

template<typename T>
int ItemModel<T>::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(1);
}

template<typename T>
QVariant ItemModel<T>::data(const QModelIndex &index, int role) const
{
    if((role == Qt::DisplayRole) && (index.isValid()))
        {
        QVariant objReturnValue;
        const QList<T> &lstModel = getModel();
        const T &val = lstModel[index.row()];

        objReturnValue.setValue(val);

        return(objReturnValue);
        }
    else
        return(QVariant());
}

template<typename T>
QModelIndex ItemModel<T>::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(createIndex(row, column));
}

template<typename T>
QModelIndex	ItemModel<T>::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return(QModelIndex());
}

template<typename T>
int	ItemModel<T>::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(getModel().size());
}

template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::Language>;
template class net::draconia::games::bane::ui::model::ItemModel<SettingsModel::VideoResolution>;
