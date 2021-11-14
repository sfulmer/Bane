#pragma once

#include "BaneController.h"
#include <QCloseEvent>
#include<QWidget>
#include "StagingPanel.h"

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
                    class StagingWindow : public QWidget
                    {
                        Q_OBJECT

                        BaneController &mRefBaneController;
                        StagingPanel *mPnlStaging;
                    protected:
                        virtual void closeEvent(QCloseEvent *event);
                        BaneController &getController() const;
                        StagingPanel *getStagingPanel();
                        void initControls() const;
                        void initWindow() const;
                    public:
                        StagingWindow(QWidget *parent);
                        StagingWindow(QWidget *parent, const BaneController &refController);

                        GameWindow *getGameWindow();
                        SettingsDialog *getSettingsDialog();
                    };
                }
            }
        }
    }
}
