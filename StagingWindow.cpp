#include "BaneApp.h"
#include "GameWindow.h"
#include <QLayout>
#include <QHBoxLayout>
#include <QLayout>
#include "SettingsDialog.h"
#include "StagingWindow.h"

using namespace net::draconia::games::bane::ui;

void StagingWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    if(getGameWindow()->isVisible())
        getGameWindow()->close();
    if(getSettingsDialog()->isVisible())
        getSettingsDialog()->reject();
}

BaneController &StagingWindow::getController() const
{
    return(mRefBaneController);
}

StagingPanel *StagingWindow::getStagingPanel()
{
    if(mPnlStaging == nullptr)
        mPnlStaging = new StagingPanel(this, getController());

    return(mPnlStaging);
}

void StagingWindow::initControls() const
{
    QLayout *HLayout;
    StagingWindow *ptrThis = const_cast<StagingWindow *>(this);

    HLayout = new QHBoxLayout(ptrThis);

    HLayout->addWidget(ptrThis->getStagingPanel());

    ptrThis->setLayout(HLayout);
}

void StagingWindow::initWindow() const
{
    const_cast<StagingWindow *>(this)->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    initControls();
}

StagingWindow::StagingWindow(QWidget *parent)
    :   StagingWindow(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

StagingWindow::StagingWindow(QWidget *parent, const BaneController &refController)
    :   QWidget(parent)
    ,   mRefBaneController(const_cast<BaneController &>(refController))
    ,   mPnlStaging(nullptr)
{
    initWindow();
}

GameWindow *StagingWindow::getGameWindow()
{
    return(getStagingPanel()->getGameWindow());
}

SettingsDialog *StagingWindow::getSettingsDialog()
{
    return(getStagingPanel()->getSettingsDialog());
}
