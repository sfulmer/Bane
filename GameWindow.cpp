#include "GameWindow.h"
#include "BaneApp.h"
#include <QCloseEvent>
#include <QMenuBar>

using namespace net::draconia::games::bane;
using namespace net::draconia::games::bane::ui;

void GameWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void GameWindow::exitClicked()
{
    getController().exit();
}

BaneController &GameWindow::getController()
{
    return(mRefController);
}

QAction *GameWindow::getExitAction()
{
    if(mActExit == nullptr)
        {
        mActExit = new QAction("E&xit...", this);

        connect(mActExit, &QAction::triggered, this, &GameWindow::exitClicked);
        }

    return(mActExit);
}

GamePanel *GameWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        {
        mPnlMain = new GamePanel(this, getController());

        mPnlMain->setFocus(Qt::FocusReason::ActiveWindowFocusReason);
        }

    return(mPnlMain);
}

QMenu *GameWindow::getBaneMenu()
{
    if(mMnuBane == nullptr)
        {
        mMnuBane = new QMenu("&Bane");

        mMnuBane->addAction(getExitAction());
        }

    return(mMnuBane);
}

void GameWindow::initControls()
{
    setMinimumSize(QSize(512, 550));

    setCentralWidget(getMainPanel());
}

void GameWindow::initMenus()
{
    QMenuBar *mMnuBar = menuBar();

    if(mMnuBar == nullptr)
        mMnuBar = new QMenuBar(this);

    mMnuBar->addMenu(getBaneMenu());

    setMenuBar(mMnuBar);
}

void GameWindow::initWindow()
{
    SettingsModel &refModel = getController().getSettingsModel();
    SettingsModel::VideoResolution &refVideoResolution = refModel.getVideoResolution();

    setWindowTitle("Bane");

    if(refModel.getDisplayType() == SettingsModel::DisplayType::Borderless)
        setWindowFlag(Qt::FramelessWindowHint);

    resize(refVideoResolution.getWidth(), refVideoResolution.getHeight());

    initControls();
    initMenus();
}

GameWindow::GameWindow(QWidget *parent)
    :   GameWindow(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

GameWindow::GameWindow(QWidget *parent, BaneController &refController)
    :   QMainWindow(parent)
    ,   mPnlMain(nullptr)
    ,   mRefController(refController)
    ,   mActExit(nullptr)
    ,   mMnuBane(nullptr)
{
    initWindow();
}
