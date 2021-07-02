#include "BaneApp.h"
#include "BaneController.h"

using namespace net::draconia::games::bane;

BaneApp &BaneController::getApplication()
{
    return(mRefApp);
}

BaneController::BaneController(BaneApp &refApp)
    :   mRefApp(refApp)
{ }

BaneController::~BaneController()
{ }

void BaneController::exit()
{
    getApplication().exit();
}

GameModel &BaneController::getModel()
{
    return(mObjModel);
}

QList<GameModel> &BaneController::getSavedGames() const
{
    return(const_cast<BaneController &>(*this).mLstSavedGames);
}
