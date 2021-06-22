#pragma once

#include "GameModel.h"

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
                protected:
                    BaneApp &getApplication();
                public:
                    BaneController(BaneApp &refApp);
                    void exit();
                    GameModel &getModel();
                };
            }
        }
    }
}
