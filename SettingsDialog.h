#pragma once

#include "BaneController.h"
#include <QDialog>
#include <QMap>
#include <QPushButton>
#include <QTabWidget>

using net::draconia::games::bane::BaneController;

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
                    class SettingsDialog : public QDialog
                    {
                        Q_OBJECT

                        SettingsModel &mRefSettingsModel;
                        QPushButton *mBtnCancel, *mBtnOk, *mBtnReset;
                        QTabWidget *mTabBar;
                    protected:
                        void doCancel() const;
                        void doOk();
                        void doReset();
                        QPushButton *getCancelButton();
                        QPushButton *getOkButton();
                        QPushButton *getResetButton();
                        SettingsModel &getSettingsModel();
                        QTabWidget *getTabPanel();
                        void initControls();
                        void initDialog();
                    public:
                        SettingsDialog(QWidget *parent, Qt::WindowFlags f = Qt::WindowFlags());
                        SettingsDialog(QWidget *parent, Qt::WindowFlags f, const SettingsModel &refSettingsModel);
                    };
                }
            }
        }
    }
}
