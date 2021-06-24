QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Armor.cpp \
    Attachable.cpp \
    BaneApp.cpp \
    BaneController.cpp \
    Character.cpp \
    Enemy.cpp \
    GameModel.cpp \
    GamePanel.cpp \
    GameWindow.cpp \
    Item.cpp \
    LoadMenuModel.cpp \
    LoadMenuRenderer.cpp \
    Menu.cpp \
    MenuOption.cpp \
    Observable.cpp \
    Party.cpp \
    Point.cpp \
    Spell.cpp \
    Spelled.cpp \
    StatusEffect.cpp \
    Target.cpp \
    Weapon.cpp \
    main.cpp \
    BaneMainWindow.cpp

HEADERS += \
    Armor.h \
    Attachable.h \
    BaneApp.h \
    BaneController.h \
    BaneMainWindow.h \
    Character.h \
    Enemy.h \
    GameModel.h \
    GamePanel.h \
    GameWindow.h \
    Item.h \
    LoadMenuModel.h \
    LoadMenuRenderer.h \
    Menu.h \
    MenuOption.h \
    Observable.h \
    Party.h \
    Point.h \
    Spell.h \
    Spelled.h \
    StatusEffect.h \
    Target.h \
    Weapon.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Shadow of the Deads.ttf \
    Shadow of the Deads.ttf \
    Shadow of the Deads.ttf

RESOURCES += \
    Bane.qrc
