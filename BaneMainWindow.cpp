#include "BaneApp.h"
#include "BaneMainWindow.h"
#include<QCloseEvent>
#include <QMenuBar>

using namespace net::draconia::games::bane::ui;

void BaneMainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void BaneMainWindow::exitClicked()
{
    getController().exit();
}

BaneController &BaneMainWindow::getController()
{
    return(mRefController);
}

QAction *BaneMainWindow::getExitAction()
{
    if(mActExit == nullptr)
        {
        mActExit = new QAction("E&xit...", this);

        connect(mActExit, &QAction::triggered, this, &BaneMainWindow::exitClicked);
        }

    return(mActExit);
}

QMenu *BaneMainWindow::getBaneMenu()
{
    return(mMnuBane);
}

GamePanel *BaneMainWindow::getMainPanel()
{
    return(mPnlMain);
}

void BaneMainWindow::initControls()
{
    setMinimumSize(QSize(512, 550));

    setCentralWidget(getMainPanel());
}

void BaneMainWindow::initMenus()
{
    QMenuBar *mMnuBar = menuBar();

    if(mMnuBar == nullptr)
        mMnuBar = new QMenuBar(this);

    mMnuBar->addMenu(getBaneMenu());

    setMenuBar(mMnuBar);
}

void BaneMainWindow::initWindow()
{
    setWindowTitle("Bane");

    initControls();
    initMenus();
}

BaneMainWindow::BaneMainWindow(QWidget *parent)
    :   BaneMainWindow(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

BaneMainWindow::BaneMainWindow(QWidget *parent, BaneController &refController)
    :   QMainWindow(parent), mRefController(refController)
{
    initWindow();
}
