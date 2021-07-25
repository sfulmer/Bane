QT       += core gui sql gamepad multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Armor.cpp \
    Attachable.cpp \
    AudioOutputVolumeObserver.cpp \
    AudioVolumeLabel.cpp \
    AudioVolumeObserver.cpp \
    BaneApp.cpp \
    BaneController.cpp \
    Character.cpp \
    ControlsTab.cpp \
    DisplayTypeChangedObserver.cpp \
    Enemy.cpp \
    GameModel.cpp \
    GamePanel.cpp \
    GameWindow.cpp \
    GeneralSettingsTab.cpp \
    Item.cpp \
    LanguageChangedObserver.cpp \
    LoadMenuModel.cpp \
    LoadMenuOption.cpp \
    LoadMenuRenderer.cpp \
    Menu.cpp \
    MenuOption.cpp \
    Observable.cpp \
    Party.cpp \
    PausedWhileInbackgroundObserver.cpp \
    Point.cpp \
    Properties.cpp \
    PropertyFileLoader.cpp \
    SettingsDialog.cpp \
    SettingsModel.cpp \
    Spell.cpp \
    Spelled.cpp \
    StagingPanel.cpp \
    StagingWindow.cpp \
    StatusEffect.cpp \
    Target.cpp \
    VideoResolutionChangedObserver.cpp \
    VideoResolutionItemModel.cpp \
    Weapon.cpp \
    main.cpp \
    BaneMainWindow.cpp

HEADERS += \
    Armor.h \
    Attachable.h \
    AudioOutputVolumeObserver.h \
    AudioVolumeLabel.h \
    AudioVolumeObserver.h \
    BaneApp.h \
    BaneController.h \
    BaneMainWindow.h \
    Character.h \
    ControlsTab.h \
    DisplayTypeChangedObserver.h \
    Enemy.h \
    GameModel.h \
    GamePanel.h \
    GameWindow.h \
    GeneralSettingsTab.h \
    Item.h \
    LanguageChangedObserver.h \
    LoadMenuModel.h \
    LoadMenuOption.h \
    LoadMenuRenderer.h \
    Menu.h \
    MenuOption.h \
    Observable.h \
    Party.h \
    PausedWhileInBackgroundObserver.h \
    Point.h \
    Properties.h \
    PropertyFileLoader.h \
    SettingsDialog.h \
    SettingsModel.h \
    Spell.h \
    Spelled.h \
    StagingPanel.h \
    StagingWindow.h \
    StatusEffect.h \
    Target.h \
    VideoResolutionChangedObserver.h \
    VideoResolutionItemModel.h \
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
