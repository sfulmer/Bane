#include "BaneApp.h"
#include <QMetaType>
#include <QtGamepad/QGamepadManager>
#include <QWindow>
#include "SettingsModel.h"

using namespace net::draconia::games::bane;

void BaneApp::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void BaneApp::showStagingWindow()
{
    QGamepadManager *ptrManager = QGamepadManager::instance();

    Q_UNUSED(ptrManager);

    QWindow *wnd = new QWindow();
    wnd->show();
    delete wnd;

    processEvents();

    getStagingWindow().show();
}

BaneApp::BaneApp(int argc, char *argv[])
    :   QApplication(argc, argv)
    ,   mWndStaging(nullptr)
    ,   mObjController(*this)
{
    setArguments(argc, argv);

    QMetaType::registerConverter(&SettingsModel::Language::toString);
    QMetaType::registerConverter(&SettingsModel::VideoResolution::toString);
}

int BaneApp::exec()
{
    showStagingWindow();

    return(QApplication::exec());
}

void BaneApp::exit()
{
    getStagingWindow().close();
}

QList<QString> &BaneApp::getArguments() const
{
    return(const_cast<BaneApp &>(*this).mLstArgs);
}

BaneController &BaneApp::getController()
{
    return(mObjController);
}

StagingWindow &BaneApp::getStagingWindow()
{
    return(mWndStaging);
}
