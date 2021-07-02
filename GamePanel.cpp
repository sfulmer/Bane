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
#include <QDebug>

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
    if(bPressed)
        {
        unsigned uiNewIndex;
        LoadMenuModel &model = getMenu().getModel();

        do
            {
            if(static_cast<int>(model.getSelectedIndex()) >= model.getOptions().length() - 1)
                uiNewIndex = 0;
            else
                uiNewIndex = model.getSelectedIndex() + 1;

            model.setSelectedIndex(uiNewIndex);
            }
        while(!model.getOptions()[uiNewIndex].isEnabled());

        repaint();
        }
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
    if(bPressed)
        {
        if(!isInLoadingMenu())
            setInLoadingMenu(true);
        else
            getModel().setPaused(!getModel().isPaused());
        }
}

void GamePanel::gamepadUpPressed(const bool bPressed)
{
    if(bPressed)
        {
        unsigned uiNewIndex;
        LoadMenuModel &model = getMenu().getModel();

        do
            {
            if(static_cast<int>(model.getSelectedIndex()) <= 0)
                uiNewIndex = model.getOptions().length() - 1;
            else
                uiNewIndex = model.getSelectedIndex() - 1;

            model.setSelectedIndex(uiNewIndex);
            }
        while(!model.getOptions()[uiNewIndex].isEnabled());

        repaint();
        }
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
        case Qt::Key_Enter:
        case Qt::Key_Return:
            if(!isInLoadingMenu())
                setInLoadingMenu(true);
            else
                switch(getMenu().getModel().getSelectedIndex())
                    {
                    case 0:
                        start();
                    case 1:
                    case 2:
                        break;
                    case 3:
                        getController().exit();
                        break;
                    }

            repaint();

            break;
        case Qt::Key_Space:
            if(!isInLoadingMenu())
                setInLoadingMenu(true);
            break;
        case Qt::Key_Up:
            {
            unsigned uiNewIndex;
            LoadMenuModel &model = getMenu().getModel();

            do
                {
                if(static_cast<int>(model.getSelectedIndex()) <= 0)
                    uiNewIndex = model.getOptions().length() - 1;
                else
                    uiNewIndex = model.getSelectedIndex() - 1;

                model.setSelectedIndex(uiNewIndex);
                }
            while(!model.getOptions()[uiNewIndex].isEnabled());

            repaint();
            }
            break;
        case Qt::Key_Down:
            {
            unsigned uiNewIndex;
            LoadMenuModel &model = getMenu().getModel();

            do
                {
                if(static_cast<int>(model.getSelectedIndex()) >= model.getOptions().length() - 1)
                    uiNewIndex = 0;
                else
                    uiNewIndex = model.getSelectedIndex() + 1;

                model.setSelectedIndex(uiNewIndex);
                }
            while(!model.getOptions()[uiNewIndex].isEnabled());

            repaint();
            }
            break;
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

        painter.setPen(QColor(0xF9, 0xF9, 0xF9));
        painter.setFont(getTitleFont());
        painter.drawText(QPoint(uiWidth, uiHeight), "BANE");

        painter.setFont(font);

        if(isInLoadingMenu())
            getMenu().render(painter, QPoint(uiWidth, uiHeight + szTitle.height()));
        }
    else
        painter.drawImage(event->rect(), QImage(":/images/Scene 1.png"));

    painter.restore();
}

void GamePanel::setInLoadingMenu(const bool bInLoadingMenu)
{
    mbInLoadingMenu = bInLoadingMenu;

    getMenu().getModel().getOptions()[1].setEnabled(getController().getSavedGames().length() > 0);

    update();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<BaneApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, BaneController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mbInLoadingMenu(false)
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
