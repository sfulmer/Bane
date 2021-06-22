#include "BaneApp.h"
#include <QWindow>
#include <QtGamepad/QGamepadManager>

using namespace net::draconia::games::bane;

void BaneApp::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void BaneApp::showMainWindow()
{
    QGamepadManager *ptrManager = QGamepadManager::instance();

    Q_UNUSED(ptrManager);

    QWindow *wnd = new QWindow();
    wnd->show();
    delete wnd;

    processEvents();

    getMainWindow().show();
}

BaneApp::BaneApp(int argc, char *argv[])
    :   QApplication(argc, argv)
    //,   mWndGame(nullptr)
    //,   mObjController(*this)
{
    setArguments(argc, argv);
}

int BaneApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

void BaneApp::exit()
{
    getMainWindow().close();
}

QList<QString> &BaneApp::getArguments() const
{
    return(const_cast<BaneApp &>(*this).mLstArgs);
}

/*BaneController &BaneApp::getController()
{
    return(mObjController);
}*/

/*GameWindow &PacManApp::getMainWindow()
{
    return(mWndGame);
}*/
