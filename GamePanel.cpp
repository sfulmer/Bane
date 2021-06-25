#include "BaneApp.h"
#include "GamePanel.h"
#include "GameWindow.h"
#include "LoadMenuRenderer.h"
#include <QDebug>
#include <QFontDatabase>
#include <QFontMetrics>
#include <QPaintEvent>
#include <QPainter>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadManager>

using net::draconia::games::bane::BaneController;
using namespace net::draconia::games::bane::model;
using namespace net::draconia::games::bane::ui;

void GamePanel::connectedGamepadsChanged()
{
    if(getGamePad() != nullptr)
        {
        connect(getGamePad(), &QGamepad::axisLeftXChanged, this, &GamePanel::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::axisLeftYChanged, this, &GamePanel::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::buttonDownChanged, this, &GamePanel::gamepadDownPressed);
        connect(getGamePad(), &QGamepad::buttonLeftChanged, this, &GamePanel::gamepadLeftPressed);
        connect(getGamePad(), &QGamepad::buttonRightChanged, this, &GamePanel::gamepadRightPressed);
        connect(getGamePad(), &QGamepad::buttonStartChanged, this, &GamePanel::gamepadStartPressed);
        connect(getGamePad(), &QGamepad::buttonUpChanged, this, &GamePanel::gamepadUpPressed);
        }
}

void GamePanel::gamepadLeftXAxisTilted(double dValue)
{
    Q_UNUSED(dValue);
}

void GamePanel::gamepadLeftYAxisTilted(double dValue)
{
    Q_UNUSED(dValue);
}

void GamePanel::gamepadDownPressed(const bool bPressed)
{
    Q_UNUSED(bPressed);
}

void GamePanel::gamepadLeftPressed(const bool bPressed)
{
    Q_UNUSED(bPressed);
}

void GamePanel::gamepadRightPressed(const bool bPressed)
{
    Q_UNUSED(bPressed);
}

void GamePanel::gamepadStartPressed(const bool bPressed)
{
    Q_UNUSED(bPressed);
}

void GamePanel::gamepadUpPressed(const bool bPressed)
{
    Q_UNUSED(bPressed);
}

BaneController &GamePanel::getController()
{
    return(mRefController);
}

QTimer *GamePanel::getEventTimer()
{
    if(mTimerEvents == nullptr)
        mTimerEvents = new QTimer(this);

    return(mTimerEvents);
}

QGamepad *GamePanel::getFirstConnectedGamePad()
{
    if(getGamePadManager()->connectedGamepads().length() > 0)
        return(new QGamepad(getGamePadManager()->connectedGamepads()[0]));
    else
        return(nullptr);
}

qint64 GamePanel::getFrame()
{
    return(miFrame);
}

QGamepad *GamePanel::getGamePad()
{
    if(mPtrGamepad == nullptr)
        mPtrGamepad = getFirstConnectedGamePad();

    return(mPtrGamepad);
}

QGamepadManager *GamePanel::getGamePadManager()
{
    if(mPtrManager == nullptr)
        {
        mPtrManager = QGamepadManager::instance();

        connect(mPtrManager, &QGamepadManager::connectedGamepadsChanged, this, &GamePanel::connectedGamepadsChanged);
        }

    return(mPtrManager);
}

LoadMenuRenderer &GamePanel::getMenu()
{
    return(mObjMenu);
}

GameModel &GamePanel::getModel()
{
    return(getController().getModel());
}

QFont &GamePanel::getTitleFont()
{
    if(mPtrTitleFont.isNull())
        {
        int iId = QFontDatabase::addApplicationFont(":/fonts/Shadow of the Deads.ttf");
        QString sFamily = QFontDatabase::applicationFontFamilies(iId).at(0);
        mPtrTitleFont.reset(new QFont(sFamily, 36));
        }

    return(*mPtrTitleFont);
}

void GamePanel::initControls()
{ }

void GamePanel::initInput()
{
    if(getGamePad() != nullptr)
        {
        connect(getGamePad(), &QGamepad::axisLeftXChanged, this, &GamePanel::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::axisLeftYChanged, this, &GamePanel::gamepadLeftXAxisTilted);
        connect(getGamePad(), &QGamepad::buttonDownChanged, this, &GamePanel::gamepadDownPressed);
        connect(getGamePad(), &QGamepad::buttonLeftChanged, this, &GamePanel::gamepadLeftPressed);
        connect(getGamePad(), &QGamepad::buttonRightChanged, this, &GamePanel::gamepadRightPressed);
        connect(getGamePad(), &QGamepad::buttonStartChanged, this, &GamePanel::gamepadStartPressed);
        connect(getGamePad(), &QGamepad::buttonUpChanged, this, &GamePanel::gamepadUpPressed);
        }
}

void GamePanel::initPanel()
{
    initControls();
}

bool GamePanel::isInLoadingMenu() const
{
    return(mbInLoadingMenu);
}

void GamePanel::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
        {
        default:
            break;
        }
}

void GamePanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    const QFont &font = painter.font();

    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    painter.save();

    painter.fillRect(event->rect(), QColor(0, 0, 0));

    if(getFrame() <= 0)
        {
        QFontMetrics metrics(getTitleFont());
        QSize szTitle = metrics.size(Qt::TextSingleLine, "BANE");
        unsigned uiWidth = event->rect().width(), uiHeight = event->rect().height();

        uiWidth = (uiWidth - szTitle.width()) / 2;
        uiHeight = (uiHeight - szTitle.height()) / 2;

        painter.setPen(QColor(0xf9, 0xf9, 0xf9));
        painter.setFont(getTitleFont());
        painter.drawText(QPoint(uiWidth, uiHeight), "BANE");
        }

    painter.setFont(font);

    if(isInLoadingMenu())
        getMenu().render(painter);

    painter.restore();
}

void GamePanel::setInLoadingMenu(const bool bInLoadingMenu)
{
    mbInLoadingMenu = bInLoadingMenu;

    update();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, BaneController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   miFrame(-1)
    ,   mPtrTitleFont(nullptr)
    ,   mTimerEvents(nullptr)
{
    initPanel();
}

void GamePanel::doFrame()
{
    miFrame++;

    repaint();
}

QSize GamePanel::sizeHint() const
{
    return(QSize(512, 650));
}

void GamePanel::start()
{
    getModel().setStarted(true);

    connect(getEventTimer(), &QTimer::timeout, this, &GamePanel::doFrame);
    getEventTimer()->start(500);
}
