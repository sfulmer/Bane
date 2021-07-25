#pragma once

#include "GameModel.h"
#include <QAudioOutput>
#include <QList>
#include "SettingsModel.h"

using net::draconia::games::bane::model::GameModel;
using net::draconia::games::bane::model::SettingsModel;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class BaneApp;

                class BaneController : public QObject
                {
                    Q_OBJECT

                    GameModel mObjModel;
                    BaneApp &mRefApp;
                    QAudioOutput mObjAudioOutput;
                    QList<GameModel> mLstSavedGames;
                    SettingsModel mObjSettingsModel;
                protected:
                    BaneApp &getApplication();
                public:
                    BaneController(BaneApp &refApp);
                    ~BaneController();

                    void exit();
                    QAudioOutput &getAudioOutput();
                    GameModel &getModel();
                    QList<GameModel> &getSavedGames() const;
                    SettingsModel &getSettingsModel();
                };
            }
        }
    }
}
