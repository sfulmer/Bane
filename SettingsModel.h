#pragma once

#include "Observable.h"
#include <QJsonObject>
#include <QMap>
#include <QString>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace model
                {
                    class SettingsModel : public Observable
                    {
                    public:
                        enum DisplayType { Borderless, FullScreen, Windowed };
                        enum InterfaceType {Controller = 0, Keyboard};
                        class Language
                        {
                            QString msLanguage, msRegion;
                        public:
                            Language();
                            Language(const QString &sLanguage, const QString &sRegion);
                            Language(const Language &refCopy);
                            ~Language();

                            QString &getLanguage() const;
                            QString &getRegion() const;
                            void setLanguage(const QString &sLanguage);
                            void setRegion(const QString &sRegion);

                            Language &operator=(const SettingsModel::Language &refCopy);
                            bool operator==(const SettingsModel::Language &refOther) const;
                            bool operator!=(const SettingsModel::Language &refOther) const;
                            operator QString() const;

                            QJsonObject toJson() const;
                            QString toString() const;
                        };
                        class VideoResolution
                        {
                            unsigned muiHeight, muiWidth;
                        public:
                            VideoResolution();
                            VideoResolution(const unsigned uiWidth, const unsigned uiHeight);
                            VideoResolution(const VideoResolution &refCopy);
                            ~VideoResolution();

                            unsigned getHeight() const;
                            unsigned getWidth() const;
                            void setHeight(const unsigned uiHeight);
                            void setWidth(const unsigned uiWidth);

                            VideoResolution operator=(const VideoResolution &refCopy);
                            bool operator==(const VideoResolution &refOther) const;
                            bool operator!=(const VideoResolution &refOther) const;
                            operator QString() const;

                            QJsonObject toJson() const;
                            QString toString() const;
                        };
                    private:
                        bool mbPauseWhileInBackground;
                        DisplayType meDisplayType;
                        QMap<InterfaceType, QMap<QString, QString>> mMapControls;
                        Language mObjLanguage;
                        unsigned muiAudioVolume;
                        VideoResolution mObjVideoResolution;
                    public:
                        SettingsModel();
                        SettingsModel(const SettingsModel &refCopy);
                        ~SettingsModel();

                        unsigned getAudioVolume() const;
                        QMap<InterfaceType, QMap<QString, QString>> &getControlMap() const;
                        DisplayType &getDisplayType() const;
                        SettingsModel::Language &getLanguage() const;
                        VideoResolution &getVideoResolution() const;
                        bool isPausedWhileInBackground() const;
                        void load(const QString &sFilename);
                        void save(const QString &sFilename);
                        void setAudioVolume(const unsigned uiAudioVolume);
                        void setControl(const InterfaceType &eInterface, const QString &sControl, const QString &sKey);
                        void setDisplayType(const DisplayType &eDisplayType);
                        void setLanguage(const SettingsModel::Language &refLanguage);
                        void setPauseWhileInBackground(const bool bPauseWhileInBackground);
                        void setVideoResolution(const VideoResolution &refVideoResolution);

                        SettingsModel &operator=(const SettingsModel &refCopy);
                        bool operator==(const SettingsModel &refOther) const;
                        bool operator!=(const SettingsModel &refOther) const;
                    };
                }
            }
        }
    }
}

Q_DECLARE_METATYPE(net::draconia::games::bane::model::SettingsModel::Language);
Q_DECLARE_METATYPE(net::draconia::games::bane::model::SettingsModel::VideoResolution);
