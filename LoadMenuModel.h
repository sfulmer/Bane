#pragma once

#include "LoadMenuOption.h"
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
                            QList<LoadMenuOption> mLstOptions;
                            unsigned muiSelectedIndex;
                        public:
                            LoadMenuModel();
                            LoadMenuModel(const QList<LoadMenuOption> &lstOptions, const unsigned &uiSelectedOption = 0);
                            LoadMenuModel(const LoadMenuModel &refCopy);
                            ~LoadMenuModel();

                            void addOption(const QString &sOption);
                            void addOption(const LoadMenuOption &objOption);
                            QList<LoadMenuOption> &getOptions() const;
                            unsigned getSelectedIndex() const;
                            void setOptions(const QList<LoadMenuOption> &lstOptions);
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
