#include "VideoResolutionItemModel.h"

using namespace net::draconia::games::bane::ui::model;

QList<SettingsModel::VideoResolution> VideoResolutionItemModel::getVideoResolutions() const
{
    return(mLstVideoResolutions);
}

VideoResolutionItemModel::VideoResolutionItemModel()
{ }

VideoResolutionItemModel::VideoResolutionItemModel(const std::initializer_list<SettingsModel::VideoResolution> lstModel)
    :   mLstVideoResolutions(lstModel)
{ }


VideoResolutionItemModel::VideoResolutionItemModel(const QList<SettingsModel::VideoResolution> &lstModel)
    :   mLstVideoResolutions(lstModel)
{ }

VideoResolutionItemModel::VideoResolutionItemModel(const VideoResolutionItemModel &refCopy)
    :   VideoResolutionItemModel(const_cast<VideoResolutionItemModel &>(refCopy).getVideoResolutions())
{ }

int VideoResolutionItemModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(1);
}

QVariant VideoResolutionItemModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        {
        const QList<SettingsModel::VideoResolution> &lstResolutions = getVideoResolutions();

        return(lstResolutions[index.row()].toString());
        }
    else
        return(QVariant());
}

QModelIndex VideoResolutionItemModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(createIndex(row, column));
}

QModelIndex	VideoResolutionItemModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return(QModelIndex());
}

int	VideoResolutionItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return(getVideoResolutions().size());
}
