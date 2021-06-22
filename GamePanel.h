#pragma once

#include "GameModel.h"
#include "BaneController.h"
#include "LoadMenuModel.h"
#include <QFont>
#include <QtGamepad/QGamepadManager>
#include <QImage>
#include <QSharedPointer>
#include <QTimer>
#include <QWidget>

using net::draconia::games::bane::ui::model::LoadMenuModel;

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
                    class GameWindow;

                    class GamePanel : public QWidget
                    {
                        Q_OBJECT
                        BaneController &mRefController;
                        bool mbInLoadingMenu;
                        LoadMenuModel mObjMenuModel;
                        QGamepad *mPtrGamepad;
                        QGamepadManager *mPtrManager;
                        qint64 miFrame;
                        QSharedPointer<QFont> mPtrTitleFont;
                        QTimer *mTimerEvents;
                    protected:
                        void connectedGamepadsChanged();
                        void gamepadLeftXAxisTilted(double dValue);
                        void gamepadLeftYAxisTilted(double dValue);
                        void gamepadDownPressed(const bool bPressed);
                        void gamepadLeftPressed(const bool bPressed);
                        void gamepadRightPressed(const bool bPressed);
                        void gamepadStartPressed(const bool bPressed);
                        void gamepadUpPressed(const bool bPressed);
                        BaneController &getController();
                        QTimer *getEventTimer();
                        QGamepad *getFirstConnectedGamePad();
                        QGamepad *getGamePad();
                        qint64 getFrame();
                        QImage &getGameBoardImage();
                        QGamepadManager *getGamePadManager();
                        LoadMenuModel &getMenuModel();
                        GameModel &getModel();
                        QFont &getTitleFont();
                        void initControls();
                        void initInput();
                        void initPanel();
                        bool isInLoadingMenu() const;
                        virtual void keyPressEvent(QKeyEvent *event);
                        void paintEvent(QPaintEvent *event);
                        void setInLoadingMenu(const bool bInLoadingMenu);
                    public:
                        GamePanel(GameWindow *parent);
                        GamePanel(GameWindow *parent, BaneController &refController);

                        void doFrame();
                        QSize sizeHint() const;
                        void start();
                    signals:
                    };
                }
            }
        }
    }
}
