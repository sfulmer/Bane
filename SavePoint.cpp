#include "SavePoint.h"

using namespace net::draconia::games::bane::model;

SavePoint::SavePoint();
SavePoint::SavePoint(const Point *ptrPoint);
SavePoint::SavePoint(const SavePoint &refSavePoint);
SavePoint::~SavePoint();

Point &SavePoint::getPoint() const;
void SavePoint::setPoint(const Point &refPoint);

void SavePoint::render(const QPainter &refPainter);

void SavePoint::save()
