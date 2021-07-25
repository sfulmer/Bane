#include "AudioOutputVolumeObserver.h"
#include "BaneApp.h"
#include "BaneController.h"

using namespace net::draconia::games::bane;
using net::draconia::games::bane::ui::observers::AudioOutputVolumeObserver;

BaneApp &BaneController::getApplication()
{
    return(mRefApp);
}

BaneController::BaneController(BaneApp &refApp)
    :   mRefApp(refApp)
{
    getSettingsModel().addObserver(new AudioOutputVolumeObserver(getAudioOutput()));
}

BaneController::~BaneController()
{ }

void BaneController::exit()
{
    getApplication().exit();
}

QAudioOutput &BaneController::getAudioOutput()
{
    return(mObjAudioOutput);
}

GameModel &BaneController::getModel()
{
    return(mObjModel);
}

QList<GameModel> &BaneController::getSavedGames() const
{
    return(const_cast<BaneController &>(*this).mLstSavedGames);
}

SettingsModel &BaneController::getSettingsModel()
{
    return(mObjSettingsModel);
}
