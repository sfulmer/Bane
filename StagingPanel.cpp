#include "BaneApp.h"
#include "GameWindow.h"
#include <QHBoxLayout>
#include "SettingsDialog.h"
#include "StagingPanel.h"

using namespace net::draconia::games::bane::ui;

void StagingPanel::doSettings()
{
    QDialog *dlg = new SettingsDialog(this, Qt::WindowFlags(), getController().getSettingsModel());

    dlg->exec();

    delete dlg;
}

void StagingPanel::doStartGame()
{
    QWidget *ptrGameWindow = new GameWindow(this);

    ptrGameWindow->showNormal();
}

BaneController &StagingPanel::getController() const
{
    return(mRefBaneController);
}

QPushButton *StagingPanel::getSettingsButton()
{
    if(mBtnSettings == nullptr)
        {
        mBtnSettings = new QPushButton("Settings", this);

        connect(mBtnSettings, &QPushButton::clicked, this, &StagingPanel::doSettings);
        }

    return(mBtnSettings);
}

QPushButton *StagingPanel::getStartGameButton()
{
    if(mBtnStartGame == nullptr)
        {
        mBtnStartGame = new QPushButton("Start Game", this);

        connect(mBtnStartGame, &QPushButton::clicked, this, &StagingPanel::doStartGame);
        }

    return(mBtnStartGame);
}

void StagingPanel::initControls() const
{
    QLayout *layout;
    StagingPanel *ptrThis = const_cast<StagingPanel *>(this);

    layout = new QHBoxLayout(ptrThis);

    layout->addWidget(ptrThis->getStartGameButton());
    layout->addWidget(ptrThis->getSettingsButton());

    ptrThis->setLayout(layout);
}

void StagingPanel::initPanel() const
{
    const_cast<StagingPanel *>(this)->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    initControls();
}

StagingPanel::StagingPanel(QWidget *parent)
    :   StagingPanel(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

StagingPanel::StagingPanel(QWidget *parent, const BaneController &refController)
    :   QWidget(parent)
    ,   mRefBaneController(const_cast<BaneController &>(refController))
    ,   mBtnSettings(nullptr)
    ,   mBtnStartGame(nullptr)
{
    initPanel();
}
