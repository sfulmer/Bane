#pragma once

#include "BaneController.h"
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
                        BaneController &getController() const;
                        StagingPanel *getStagingPanel();
                        void initControls() const;
                        void initWindow() const;
                    public:
                        StagingWindow(QWidget *parent);
                        StagingWindow(QWidget *parent, const BaneController &refController);
                    };
                }
            }
        }
    }
}
