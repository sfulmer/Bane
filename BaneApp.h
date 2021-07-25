#pragma once

#include "StagingWindow.h"
#include "BaneController.h"
#include <QApplication>
#include <QList>
#include <QString>

using net::draconia::games::bane::ui::StagingWindow;

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
                    StagingWindow mWndStaging;
                    BaneController mObjController;
                    QList<QString> mLstArgs;
                protected:
                    void setArguments(int argc, char *argv[]);
                    void showStagingWindow();
                public:
                    BaneApp(int argc, char *argv[]);
                    int exec();
                    void exit();
                    QList<QString> &getArguments() const;
                    BaneController &getController();
                    StagingWindow &getStagingWindow();
                };
            }
        }
    }
}
