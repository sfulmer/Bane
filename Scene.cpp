#include "Scene.h"

using namespace net::draconia::games::bane::ui;

QList<Party> &Scene::getPartiesInternal() const
{
    return(const_cast<Scene &>(*this).mLstParties);
}

QList<SavePoint> &Scene::getSavePointsInternal() const
{
    return(const_cast<Scene &>(*this).mLstSavePoints);
}

void Scene::setParties(const QList<Party> &lstParties)
{
    mLstParties = lstParties;

    setChanged(true);
    notifyObservers("Parties");
}

void Scene::setSavePoints(const QList<SavePoint> &lstSavePoints)
{
    mLstSavePoints = lstSavePoints;

    setChanged(true);
    notifyObservers("SavePoints");
}

Scene::Scene()
    :   Observable()
{ }

Scene::Scene(const Scene &refCopy)
    :   Observable()
    ,   mImgScene(refCopy.getSceneImage())
    ,   mLstParties(refCopy.getParties())
    ,   mLstSavePoints(refCopy.getSavePoints())
{ }

Scene::~Scene()
{ }

void Scene::addParty(const Party &refParty)
{
    getPartiesInternal().append(refParty);

    setChanged(true);
    notifyObservers("Parties");
}

void Scene::addSavePoint(const SavePoint &refSavePoint)
{
    getSavePointsInternal().append(refSavePoint);

    setChanged(true);
    notifyObservers("SavePoints");
}

const QList<Party> &Scene::getParties() const
{
    return(getPartiesInternal());
}

const QList<SavePoint> &Scene::getSavePoints() const
{
    return(getSavePointsInternal());
}

QImage *Scene::getSceneImage() const
{
    return(mImgScene);
}

void Scene::removeParty(const Party &refParty)
{
    getPartiesInternal().removeOne(refParty);

    setChanged(true);
    notifyObservers("Parties");
}

void Scene::removeSavePoint(const SavePoint &refSavePoint)
{
    getSavePointsInternal().removeOne(refSavePoint);

    setChanged(true);
    notifyObservers("SavePoints");
}

void Scene::setSceneImage(const QImage *imgScene)
{
    mImgScene = const_cast<QImage *>(imgScene);

    setChanged(true);
    notifyObservers("SceneImage");
}
