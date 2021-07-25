#pragma once

#include "BaneController.h"
#include<QPushButton>
#include <QWidget>

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
                        QPushButton *mBtnSettings, *mBtnStartGame;
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
                    };
                }
            }
        }
    }
}
