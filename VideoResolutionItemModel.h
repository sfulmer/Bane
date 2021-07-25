#pragma once

#include <QAbstractItemModel>
#include <QList>
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace ui
                {
                    namespace model
                    {
                        class VideoResolutionItemModel : public QAbstractItemModel
                        {
                            QList<SettingsModel::VideoResolution> mLstVideoResolutions;
                        protected:
                            QList<SettingsModel::VideoResolution> getVideoResolutions() const;
                        public:
                            VideoResolutionItemModel();
                            VideoResolutionItemModel(const std::initializer_list<SettingsModel::VideoResolution> lstModel);
                            VideoResolutionItemModel(const QList<SettingsModel::VideoResolution> &lstModel);
                            VideoResolutionItemModel(const VideoResolutionItemModel &refCopy);

                            virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
                            virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
                            virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
                            virtual QModelIndex	parent(const QModelIndex &index) const;
                            virtual int	rowCount(const QModelIndex &parent = QModelIndex()) const;
                        };
                    }
                }
            }
        }
    }
}
