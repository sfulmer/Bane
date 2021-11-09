#include "BaneApp.h"
#include "ControlsTab.h"
#include "GeneralSettingsTab.h"
#include <QLayout>
#include <QGridLayout>
#include "SettingsDialog.h"

using namespace net::draconia::games::bane::ui;

void SettingsDialog::doCancel() const
{
    const_cast<SettingsDialog *>(this)->reject();
}

void SettingsDialog::doOk()
{
    getSettingsModel().save();

    accept();
}

void SettingsDialog::doReset()
{ }

QPushButton *SettingsDialog::getCancelButton()
{
    if(mBtnCancel == nullptr)
        {
        mBtnCancel = new QPushButton("Cancel", this);

        connect(mBtnCancel, &QPushButton::clicked, this, &SettingsDialog::doCancel);
        }

    return(mBtnCancel);
}

QPushButton *SettingsDialog::getOkButton()
{
    if(mBtnOk == nullptr)
        {
        mBtnOk = new QPushButton("Ok", this);

        connect(mBtnOk, &QPushButton::clicked, this, &SettingsDialog::doOk);
        }

    return(mBtnOk);
}

QPushButton *SettingsDialog::getResetButton()
{
    if(mBtnReset == nullptr)
        {
        mBtnReset = new QPushButton("Reset", this);

        connect(mBtnReset, &QPushButton::clicked, this, &SettingsDialog::doReset);
        }

    return(mBtnReset);
}

SettingsModel &SettingsDialog::getSettingsModel()
{
    return(mRefSettingsModel);
}

QTabWidget *SettingsDialog::getTabPanel()
{
    if(mTabBar == nullptr)
        {
        mTabBar = new QTabWidget(this);

        mTabBar->addTab(new GeneralSettingsTab(this), "General");
        mTabBar->addTab(new ControlsTab(this), "Controls");
        }

    return(mTabBar);
}

void SettingsDialog::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getTabPanel(), 0, 0, 1, 3);
    layout->addWidget(getCancelButton(), 1, 0, 1, 1);
    layout->addWidget(getOkButton(), 1, 1, 1, 1);
    layout->addWidget(getResetButton(), 1, 2, 1, 1);

    setLayout(layout);
}

void SettingsDialog::initDialog()
{
    setMinimumSize(QSize(500, 475));

    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    setAttribute(Qt::WA_DeleteOnClose);

    initControls();


}

SettingsDialog::SettingsDialog(QWidget *parent, Qt::WindowFlags f)
    :   SettingsDialog(parent, f, static_cast<BaneApp *>(qApp)->getController().getSettingsModel())
{ }

SettingsDialog::SettingsDialog(QWidget *parent, Qt::WindowFlags f, const SettingsModel &refSettingsModel)
    :   QDialog(parent, f)
    ,   mRefSettingsModel(const_cast<SettingsModel &>(refSettingsModel))
    ,   mBtnCancel(nullptr), mBtnOk(nullptr), mBtnReset(nullptr)
    ,   mTabBar(nullptr)
{
    getSettingsModel().setAudioVolume(static_cast<unsigned>(static_cast<BaneApp *>(qApp)->getController().getAudioOutput().volume() * 100));

    initDialog();
}
