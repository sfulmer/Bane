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

void BaneController::exit()
{
    getApplication().exit();
}

GameModel &BaneController::getModel()
{
    return(mObjModel);
}
