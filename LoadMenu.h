#pragma once

#include "LoadMenuOption.h"
#include "Observable.h"
#include <QList>
#include <QString>
#include "Renderable.h"

using net::draconia::util::Observable;

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
                        class LoadMenu : public Renderable
                        {
                        public:
                            class Option;

                            QList<Option> mLstOptions;
                            unsigned muiSelectedIndex;
                        public:
                            LoadMenu();
                            LoadMenu(const QList<Option> &lstOptions, const unsigned &uiSelectedOption = 0);
                            LoadMenu(const LoadMenu &refCopy);
                            ~LoadMenu();

                            void addOption(const QString &sOption);
                            void addOption(const Option &objOption);
                            QList<Option> &getOptions() const;
                            unsigned getSelectedIndex() const;
                            void setOptions(const QList<Option> &lstOptions);
                            void setSelectedIndex(const unsigned uiIndex);

                            LoadMenu &operator=(const LoadMenu &refCopy);
                            bool operator==(const LoadMenu &refOther) const;
                            bool operator!=(const LoadMenu &refOther) const;

                            virtual void render(const QPainter &refPainter);

                            class Option : public Observable
                            {
                                bool mbEnabled;
                                QString msName;
                                unsigned muiIndex;
                            public:
                                Option();
                                Option(const unsigned uiIndex, const QString &sName, const bool bEnabled = false);
                                Option(const QString &sNme, const bool bEnabled = false);
                                Option(const Option &refCopy);
                                ~Option();

                                unsigned getIndex() const;
                                QString &getName() const;
                                bool isEnabled() const;
                                void setEnabled(const bool bEnabled);
                                void setIndex(const unsigned uiIndex);
                                void setName(const QString &sName);

                                Option &operator=(const Option &refCopy);
                                bool operator==(const Option &refOther) const;
                                bool operator!=(const Option &refOther) const;
                                bool operator>(const Option &refOther) const;
                                bool operator>=(const Option &refOther) const;
                                bool operator<(const Option &refOther) const;
                                bool operator<=(const Option &refOther) const;
                            };
                        };
                    }
                }
            }
        }
    }
}
