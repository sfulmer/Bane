#pragma once

#include "BaneController.h"
#include "GameWindow.h"
#include<QPushButton>
#include <QWidget>
#include "SettingsDialog.h"

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
                    class StagingPanel : public QWidget
                    {
                        Q_OBJECT

                        BaneController &mRefBaneController;
                        GameWindow *mWndGame;
                        QPushButton *mBtnSettings, *mBtnStartGame;
                        SettingsDialog *mDlgSettings;
                    protected:
                        void doSettings();
                        void doStartGame();
                        BaneController &getController() const;
                        QPushButton *getSettingsButton();
                        QPushButton *getStartGameButton();
                        void initControls() const;
                        void initPanel() const;
                    public:
                        StagingPanel(QWidget *parent);
                        StagingPanel(QWidget *parent, const BaneController &refController);

                        GameWindow *getGameWindow();
                        SettingsDialog *getSettingsDialog();
                    };
                }
            }
        }
    }
}
