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
                    class BaneMainWindow : public QMainWindow
                    {
                        Q_OBJECT
                        GamePanel *mPnlMain;
                        BaneController &mRefController;
                        QAction *mActExit;
                        QMenu *mMnuPacMan;
                    protected:
                        void closeEvent(QCloseEvent *event);
                        void exitClicked();
                        BaneController &getController();
                        QAction *getExitAction();
                        GamePanel *getMainPanel();
                        QMenu *getPacManMenu();
                        void initControls();
                        void initMenus();
                        void initWindow();
                    public:
                        BaneMainWindow(QWidget *parent);
                        BaneMainWindow(QWidget *parent, BaneController &refController);
                    };
                }
            }
        }
    }
}
