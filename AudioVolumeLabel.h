#pragma once

#include <QLabel>
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
                    class AudioVolumeLabel : public QWidget
                    {
                        Q_OBJECT

                        QLabel *mLblDisplay, *mLblMainLable;
                        QWidget *mPtrBuddy;
                        SettingsModel &mRefModel;
                    protected:
                        SettingsModel &getModel() const;
                        void initControls();
                        void initPanel();
                    public:
                        AudioVolumeLabel(const QWidget *parent);
                        AudioVolumeLabel(const QWidget *parent, const SettingsModel &refModel);

                        QWidget *buddy() const;
                        QLabel *getDisplayLabel();
                        QLabel *getMainLabel();
                        void setBuddy(const QWidget *ptrBuddy);
                    };
                }
            }
        }
    }
}
