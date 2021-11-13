#pragma once

#include "AudioVolumeLabel.h"
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QWidget>
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace ui
                {
                    class GeneralSettingsTab : public QWidget
                    {
                        Q_OBJECT

                        AudioVolumeLabel *mLblAudioVolume;
                        QCheckBox *mChkPauseGame;
                        QComboBox *mCboDisplay, *mCboLanguage, *mCboVideoResolution;
                        QLabel *mLblDisplay, *mLblLanguage, *mLblVideoResolution;
                        QSlider *mObjAudioVolume;
                        SettingsModel *mPtrModel;
                    protected:
                        AudioVolumeLabel *getAudioVolumeLabel();
                        QSlider *getAudioVolumeSlider();
                        QComboBox *getDisplayComboBox();
                        QLabel *getDisplayLabel();
                        QComboBox *getLanguageComboBox();
                        QLabel *getLanguageLabel();
                        QCheckBox *getPauseGameCheckBox();
                        SettingsModel &getSettingsModel();
                        QComboBox *getVideoResolutionComboBox();
                        QLabel *getVideoResolutionLabel();
                        void initControls();
                        void initTab();
                    protected slots:
                        void audioVolumeChanged(const int iVolume);
                        void displayTypeChanged(const int iDisplayType);
                        void languageChanged(const int iLanguage);
                        void pauseClicked();
                        void videoResolutionChanged(const int iVideoResolution);
                    public:
                        GeneralSettingsTab(QWidget *parent);
                        GeneralSettingsTab(QWidget *parent, const SettingsModel &refModel);

                        ~GeneralSettingsTab();
                    };
                }
            }
        }
    }
}
