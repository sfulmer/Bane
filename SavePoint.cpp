#include "BeanRepository.h"
#include "SavePoint.h"

using net::draconia::games::bane::BeanRepository;
using namespace net::draconia::games::bane::model;

QFile &SavePoint::getFile()
{
    return(BeanRepository::getInstance().getSaveFile());
}

SavePoint::SavePoint()
    :   Observable()
{ }

SavePoint::SavePoint(const Point &refPoint)
    :   Observable()
    ,   mPtPoint(const_cast<Point &>(refPoint))
{ }

SavePoint::SavePoint(const SavePoint &refSavePoint)
    :   SavePoint(refSavePoint.getPoint())
{ }

SavePoint::~SavePoint()
{ }

Point &SavePoint::getPoint() const
{
    return(const_cast<SavePoint &>(*this).mPtPoint);
}

void SavePoint::setPoint(const Point &refPoint)
{
    mPtPoint = refPoint;

    setChanged();
    notifyObservers("Point");
}

void SavePoint::render(const QPainter &refPainter)
{

}

void SavePoint::save()
{
    //TODO: Get List of save files within the one save file on disk
    //TODO: Prompt for selection which one is wanted and default at start to the last one loaded/saved
    //TODO: Close save file
    //TODO: Clear screen to game again
}
