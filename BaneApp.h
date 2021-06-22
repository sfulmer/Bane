#pragma once

#include "GameWindow.h"
#include "BaneController.h"
#include <QApplication>
#include <QList>
#include <QString>

using net::draconia::games::bane::ui::GameWindow;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class BaneApp : public QApplication
                {
                    GameWindow mWndGame;
                    BaneController mObjController;
                    QList<QString> mLstArgs;
                protected:
                    void setArguments(int argc, char *argv[]);
                    void showMainWindow();
                public:
                    BaneApp(int argc, char *argv[]);
                    int exec();
                    void exit();
                    QList<QString> &getArguments() const;
                    BaneController &getController();
                    GameWindow &getMainWindow();
                };
            }
        }
    }
}
