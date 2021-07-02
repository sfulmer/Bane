#pragma once

#include "GameModel.h"
#include <QList>

using net::draconia::games::bane::model::GameModel;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class BaneApp;

                class BaneController
                {
                    GameModel mObjModel;
                    BaneApp &mRefApp;
                    QList<GameModel> mLstSavedGames;
                protected:
                    BaneApp &getApplication();
                public:
                    BaneController(BaneApp &refApp);
                    ~BaneController();

                    void exit();
                    GameModel &getModel();
                    QList<GameModel> &getSavedGames() const;
                };
            }
        }
    }
}
