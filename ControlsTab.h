#pragma once

#include <QGamepad>
#include <QString>
#include <QTableWidget>
#include <QWidget>
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;

class ControlsTab : public QWidget
{
    Q_OBJECT

    SettingsModel &mRefModel;
    QGamepad *mPtrGamepad;
    QGamepadManager *mPtrManager;
    QTableWidget *mTblControls;
    SettingsModel::InterfaceType meFocusedInterfaceType;
    QString msFocusedControl;
protected:
    void connectedGamepadsChanged();
    bool eventFilter(QObject *object, QEvent *event);
    void gamepadLeftXAxisTilted(double dValue);
    void gamepadLeftYAxisTilted(double dValue);
    void gamepadDownPressed(const bool bPressed);
    void gamepadLeftPressed(const bool bPressed);
    void gamepadRightPressed(const bool bPressed);
    void gamepadStartPressed(const bool bPressed);
    void gamepadUpPressed(const bool bPressed);
    QTableWidget *getControlsTable();
    QGamepad *getFirstConnectedGamePad();
    QLineEdit *getFocusControl();
    QString &getFocusedControlName() const;
    QGamepad *getGamePad();
    QGamepadManager *getGamePadManager();
    SettingsModel::InterfaceType &getFocusedInferfaceType() const;
    SettingsModel &getModel() const;
    void initControls() const;
    void initTab() const;
    virtual void keyPressEvent(QKeyEvent *event);
    void setFocusedControl(const QString &sFocusedControl);
    void setFocusedInferfaceType(const SettingsModel::InterfaceType &eFocusedInterfaceType);
public:
    ControlsTab(QWidget *parent);
    ControlsTab(QWidget *parent, const SettingsModel &refModel);
};

