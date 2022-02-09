QT       += core gui sql gamepad multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

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
    BeanRepository.cpp \
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
    LoadMenu.cpp \
    LoadMenuRenderer.cpp \
    Menu.cpp \
    MenuOption.cpp \
    Observable.cpp \
    Party.cpp \
    PausedWhileInbackgroundObserver.cpp \
    Point.cpp \
    Renderable.cpp \
    SavePoint.cpp \
    Scene.cpp \
    SettingsDialog.cpp \
    SettingsModel.cpp \
    Spell.cpp \
    Spelled.cpp \
    StagingPanel.cpp \
    StagingWindow.cpp \
    StatusEffect.cpp \
    Target.cpp \
    TitleScene.cpp \
    VideoResolutionChangedObserver.cpp \
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
    BeanRepository.h \
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
    LoadMenu.h \
    LoadMenuRenderer.h \
    Menu.h \
    MenuOption.h \
    Observable.h \
    Party.h \
    PausedWhileInBackgroundObserver.h \
    Point.h \
    Renderable.h \
    SavePoint.h \
    Scene.h \
    SettingsDialog.h \
    SettingsModel.h \
    Spell.h \
    Spelled.h \
    StagingPanel.h \
    StagingWindow.h \
    StatusEffect.h \
    Target.h \
    TitleScene.h \
    VideoResolutionChangedObserver.h \
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
