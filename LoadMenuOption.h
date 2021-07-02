#pragma once

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
                        class LoadMenuOption
                        {
                            bool mbEnabled;
                            QString msName;
                            unsigned muiIndex;
                        public:
                            LoadMenuOption();
                            LoadMenuOption(const unsigned uiIndex, const QString &sName, const bool bEnabled = false);
                            LoadMenuOption(const QString &sNme, const bool bEnabled = false);
                            LoadMenuOption(const LoadMenuOption &refCopy);
                            ~LoadMenuOption();

                            unsigned getIndex() const;
                            QString &getName() const;
                            bool isEnabled() const;
                            void setEnabled(const bool bEnabled);
                            void setIndex(const unsigned uiIndex);
                            void setName(const QString &sName);

                            LoadMenuOption &operator=(const LoadMenuOption &refCopy);
                            bool operator==(const LoadMenuOption &refOther) const;
                            bool operator!=(const LoadMenuOption &refOther) const;
                            bool operator>(const LoadMenuOption &refOther) const;
                            bool operator>=(const LoadMenuOption &refOther) const;
                            bool operator<(const LoadMenuOption &refOther) const;
                            bool operator<=(const LoadMenuOption &refOther) const;
                        };
                    }
                }
            }
        }
    }
}
