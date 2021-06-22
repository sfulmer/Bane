#pragma once

#include <QList>
#include <QString>

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
                        class LoadMenuModel
                        {
                            QList<QString> mLstOptions;
                            unsigned muiSelectedIndex;
                        public:
                            LoadMenuModel();
                            LoadMenuModel(const QList<QString> &lstOptions, const unsigned &uiSelectedOption = 0);
                            LoadMenuModel(const LoadMenuModel &refCopy);
                            ~LoadMenuModel();

                            QList<QString> &getOptions() const;
                            unsigned getSelectedIndex() const;
                            void setOptions(const QList<QString> &lstOptions);
                            void setSelectedIndex(const unsigned uiIndex);

                            LoadMenuModel &operator=(const LoadMenuModel &refCopy);
                            bool operator==(const LoadMenuModel &refOther) const;
                            bool operator!=(const LoadMenuModel &refOther) const;
                        };
                    }
                }
            }
        }
    }
}
