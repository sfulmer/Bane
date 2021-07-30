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
                        template<typename T>
                        class ItemModel : public QAbstractItemModel
                        {
                            QList<T> mLstModel;
                        protected:
                            QList<T> getModel() const;
                        public:
                            ItemModel();
                            ItemModel(const std::initializer_list<T> lstModel);
                            ItemModel(const QList<T> &lstModel);
                            ItemModel(const ItemModel<T> &refCopy);

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
