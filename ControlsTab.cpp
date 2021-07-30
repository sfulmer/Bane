#include "BaneApp.h"
#include "ControlsTab.h"
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLineEdit>
#include <QList>

using net::draconia::games::bane::BaneApp;
using namespace net::draconia::games::bane::ui;

void ControlsTab::connectedGamepadsChanged()
{
    if(getGamePad() != nullptr)
        {
        connect(getGamePad(), &QGamepad::axisLeftXChanged, this, &ControlsTab::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::axisLeftYChanged, this, &ControlsTab::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::buttonDownChanged, this, &ControlsTab::gamepadDownPressed);
        connect(getGamePad(), &QGamepad::buttonLeftChanged, this, &ControlsTab::gamepadLeftPressed);
        connect(getGamePad(), &QGamepad::buttonRightChanged, this, &ControlsTab::gamepadRightPressed);
        connect(getGamePad(), &QGamepad::buttonStartChanged, this, &ControlsTab::gamepadStartPressed);
        connect(getGamePad(), &QGamepad::buttonUpChanged, this, &ControlsTab::gamepadUpPressed);
        }
}

bool ControlsTab::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::FocusIn)
        if(object->objectName().length() > 0)
            {
            const QString &sName = object->objectName();
            const QStringList sParts = sName.split("_");
            const QString sType = sParts[0].trimmed();
            const QString sControl = sParts[1].trimmed();

            if(sType == "Controller")
                setFocusedInferfaceType(SettingsModel::InterfaceType::Controller);
            else if(sType == "Keyboard")
                setFocusedInferfaceType(SettingsModel::InterfaceType::Keyboard);

            setFocusedControl(sControl);
            }

    return(false);
}

void ControlsTab::gamepadLeftXAxisTilted(double dValue)
{
    Q_UNUSED(dValue);

    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        getFocusControl()->setText("Left stick");
}

void ControlsTab::gamepadLeftYAxisTilted(double dValue)
{
    Q_UNUSED(dValue);

    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        getFocusControl()->setText("Right stick");
}

void ControlsTab::gamepadDownPressed(const bool bPressed)
{
    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        if(bPressed)
            getFocusControl()->setText("↓");
}

void ControlsTab::gamepadLeftPressed(const bool bPressed)
{
    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        if(bPressed)
            getFocusControl()->setText("←");
}

void ControlsTab::gamepadRightPressed(const bool bPressed)
{
    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        if(bPressed)
            getFocusControl()->setText("→");
}

void ControlsTab::gamepadStartPressed(const bool bPressed)
{
    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
        if(bPressed)
            getFocusControl()->setText("Start");
}

void ControlsTab::gamepadUpPressed(const bool bPressed)
{
    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller)
            if(bPressed)
                getFocusControl()->setText("↑");
}

QTableWidget *ControlsTab::getControlsTable()
{
    if(mTblControls == nullptr)
        {
        QList<QString> lstColumns = {{"Keyboard", "Controller"}};
        QList<QString> lstRows = {{"Up", "Down", "Left", "Right", "Select", "Cancel", "Select All Targets", "Menu / Runaway"}};
        mTblControls = new QTableWidget(8, 2, this);

        mTblControls->setSortingEnabled(false);

        mTblControls->setHorizontalHeaderLabels(lstColumns);
        mTblControls->setVerticalHeaderLabels(lstRows);

        for(unsigned uiColLength = mTblControls->columnCount(), uiColLoop = 1; uiColLoop < uiColLength; uiColLoop++)
            for(unsigned uiRowLength = mTblControls->rowCount(), uiRowLoop = 1; uiRowLoop < uiRowLength; uiRowLoop++)
                {
                QLineEdit *ptrText = new QLineEdit(this);

                ptrText->setObjectName(lstColumns[uiColLoop] + "_" + lstRows[uiRowLoop]);
                mTblControls->setCellWidget(uiRowLoop, uiColLoop, ptrText);

                QObject::installEventFilter(this);
                }
        }

    return(mTblControls);
}

QGamepad *ControlsTab::getFirstConnectedGamePad()
{
    if(getGamePadManager()->connectedGamepads().length() > 0)
        return(new QGamepad(getGamePadManager()->connectedGamepads()[0]));
    else
        return(nullptr);
}

QLineEdit *ControlsTab::getFocusControl()
{
    return(QObject::findChild<QLineEdit *>(QString((getFocusedInferfaceType() == SettingsModel::InterfaceType::Controller) ? "Controller" : "Keyboard") + "_" + getFocusedControlName()));
}

QString &ControlsTab::getFocusedControlName() const
{
    return(const_cast<ControlsTab &>(*this).msFocusedControl);
}

SettingsModel::InterfaceType &ControlsTab::getFocusedInferfaceType() const
{
    return(const_cast<ControlsTab &>(*this).meFocusedInterfaceType);
}

QGamepad *ControlsTab::getGamePad()
{
    if(mPtrGamepad == nullptr)
        mPtrGamepad = getFirstConnectedGamePad();

    return(mPtrGamepad);
}

QGamepadManager *ControlsTab::getGamePadManager()
{
    if(mPtrManager == nullptr)
        {
        mPtrManager = QGamepadManager::instance();

        connect(mPtrManager, &QGamepadManager::connectedGamepadsChanged, this, &ControlsTab::connectedGamepadsChanged);
        }

    return(mPtrManager);
}

SettingsModel &ControlsTab::getModel() const
{
    return(mRefModel);
}

void ControlsTab::initControls() const
{
    ControlsTab *ptrThis = const_cast<ControlsTab *>(this);
    QLayout *layout = new QHBoxLayout(ptrThis);

    layout->addWidget(ptrThis->getControlsTable());

    ptrThis->setLayout(layout);
}

void ControlsTab::initTab() const
{
    const_cast<ControlsTab *>(this)->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdangling-else"
void ControlsTab::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);

    if(getFocusedInferfaceType() == SettingsModel::InterfaceType::Keyboard)
        if((event->key() > Qt::Key_F1) && (event->key() < Qt::Key_F35))
            getFocusControl()->setText(QString("F%1").arg(event->key() - Qt::Key_F1 + 1));
        else if((event->key() > 'A') && (event->key() < 'Z'))
            getFocusControl()->setText(QString("%1").arg(static_cast<char>(event->key() - 'A' + 1)));
        else if((event->key() > 'a') && (event->key() < 'z'))
            getFocusControl()->setText(QString("%1").arg(static_cast<char>(event->key() - 'a' + 1)));
        else if((event->key() > '1') && (event->key() < '0'))
            getFocusControl()->setText(QString(event->key() - '1' + 1));
        else
            switch(event->key())
                {
                case Qt::Key_Up:
                    getFocusControl()->setText("↑");
                    break;
                case Qt::Key_Down:
                    getFocusControl()->setText("↓");
                    break;
                case Qt::Key_Left:
                    getFocusControl()->setText("←");
                    break;
                case Qt::Key_Right:
                    getFocusControl()->setText("→");
                    break;
                case Qt::Key_Shift:
                    getFocusControl()->setText("Shift");
                    break;
                case Qt::Key_Control:
                    getFocusControl()->setText("Control");
                    break;
                case Qt::Key_Alt:
                    getFocusControl()->setText("Alt");
                    break;
                case Qt::Key_Tab:
                    getFocusControl()->setText("Tab");
                    break;
                case Qt::Key_Return:
                    getFocusControl()->setText("Enter/Return");
                    break;
                case Qt::Key_Colon:
                    getFocusControl()->setText(":");
                    break;
                case Qt::Key_Slash:
                    getFocusControl()->setText("/");
                    break;
                case Qt::Key_Backslash:
                    getFocusControl()->setText("\\");
                    break;
                case Qt::Key_hyphen:
                    getFocusControl()->setText("-");
                    break;
                case Qt::Key_Semicolon:
                    getFocusControl()->setText(";");
                    break;
                case Qt::Key_BracketLeft:
                    getFocusControl()->setText("[");
                    break;
                case Qt::Key_BracketRight:
                    getFocusControl()->setText("]");
                    break;
                case Qt::Key_Comma:
                    getFocusControl()->setText(",");
                    break;
                case Qt::Key_Apostrophe:
                    getFocusControl()->setText("'");
                    break;
                case Qt::Key_Period:
                    getFocusControl()->setText(".");
                    break;
                case Qt::Key_PageUp:
                    getFocusControl()->setText("PgUp");
                    break;
                case Qt::Key_PageDown:
                    getFocusControl()->setText("PgDn");
                    break;
                }
}
#pragma GCC diagnostic pop

void ControlsTab::setFocusedControl(const QString &sFocusedControl)
{
    msFocusedControl = sFocusedControl;
}

void ControlsTab::setFocusedInferfaceType(const SettingsModel::InterfaceType &eFocusedInterfaceType)
{
    meFocusedInterfaceType = eFocusedInterfaceType;
}

ControlsTab::ControlsTab(QWidget *parent)
    :   ControlsTab(parent, static_cast<BaneApp *>(qApp)->getController().getSettingsModel())
{ }

ControlsTab::ControlsTab(QWidget *parent, const SettingsModel &refModel)
    :   QWidget(parent)
    ,   mRefModel(const_cast<SettingsModel &>(refModel))
    ,   mPtrGamepad(nullptr)
    ,   mTblControls(nullptr)
{
    initTab();
}
