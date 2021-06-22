#pragma once

#include "GamePanel.h"
#include "BaneController.h"
#include <QAction>
#include <QMainWindow>
#include <QMenu>

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
                    class GameWindow : public QMainWindow
                    {
                        Q_OBJECT
                        GamePanel *mPnlMain;
                        BaneController &mRefController;
                        QAction *mActExit;
                        QMenu *mMnuBane;
                    protected:
                        void closeEvent(QCloseEvent *event);
                        void exitClicked();
                        BaneController &getController();
                        QAction *getExitAction();
                        GamePanel *getMainPanel();
                        QMenu *getBaneMenu();
                        void initControls();
                        void initMenus();
                        void initWindow();
                    public:
                        GameWindow(QWidget *parent);
                        GameWindow(QWidget *parent, BaneController &refController);
                    };
                }
            }
        }
    }
}
