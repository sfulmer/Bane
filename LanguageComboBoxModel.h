#pragma once

#include <QAbstractListModel>
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
                        class LanguageComboBoxModel : public QAbstractListModel
                        {
                            Q_OBJECT

                            QList<SettingsModel::Language> mLstModel;
                        public:
                            LanguageComboBoxModel();
                            ~LanguageComboBoxModel();

                            virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
                            const QList<SettingsModel::Language> getModel();
                            virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
                        };
                    }
                }
            }
        }
    }
}
