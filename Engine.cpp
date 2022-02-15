#include "Engine.h"

using namespace net::draconia::games::bane::ui::model;

QList<Scene> Engine::getSceneListInternal() const
{
    return(mLstScenes);
}

Engine::Engine()
    :   Observable()
{ }

Engine::Engine(const QList<Scene> &lstScenes)
    :   Observable()
    ,   mLstScenes(lstScenes)
{ }

Engine::Engine(const Engine &refCopy)
    :   Observable(refCopy)
    ,   mLstScenes(refCopy.getScenes())
{ }

Engine::~Engine()
{ }

void Engine::addScene(const Scene &refScene)
{
    getSceneListInternal().append(refScene);

    setChanged(true);
    notifyObservers("Scenes");
}

void Engine::addScenes(const QList<Scene> &lstScenes)
{
    getSceneListInternal().append(lstScenes);

    setChanged(true);
    notifyObservers("Scenes");
}

Scene &Engine::getCurrentScene() const
{
    if(mPtrCurrentScene == nullptr)
        throw "No Current Scene";

    return(*mPtrCurrentScene);
}

const QList<Scene> &Engine::getScenes() const
{
    return(mLstScenes);
}

void Engine::removeScene(const Scene &refScene)
{
    getSceneListInternal().removeOne(refScene);

    setChanged(true);
    notifyObservers("Scenes");
}

void Engine::removeScenes(const QList<Scene> &lstScenes)
{
    for(const Scene &refScene : lstScenes)
        getSceneListInternal().removeOne(refScene);

    setChanged(true);
    notifyObservers("Scenes");
}

void Engine::run()
{
    QPainter painter;

    painter.save();

    for(Scene &refScene : getSceneListInternal())
        refScene.showScene(painter);

    painter.restore();
}
