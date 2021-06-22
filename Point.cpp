#include "Point.h"

using namespace net::draconia::games::bane::model;

Point::Point()
    :   Point(0, 0)
{ }

Point::Point(const int iX, const int iY, const int iZ, const Point *ptrSubPoint)
    :   miX(iX), miY(iY), miZ(iZ), mPtrSubPoint(const_cast<Point *>(ptrSubPoint))
{ }

Point::Point(const Point &refCopy)
    :   Point(refCopy.getX(), refCopy.getY(), refCopy.getZ(), refCopy.getSubPoint())
{ }

Point::~Point()
{
    if(mPtrSubPoint != nullptr)
        {
        delete mPtrSubPoint;

        mPtrSubPoint = nullptr;
        }
}

Point *Point::getSubPoint() const
{
    return(mPtrSubPoint);
}

int Point::getX() const
{
    return(miX);
}

int Point::getY() const
{
    return(miY);
}

int Point::getZ() const
{
    return(miZ);
}

void Point::setSubPoint(const Point *ptrSubPoint)
{
    mPtrSubPoint = const_cast<Point *>(ptrSubPoint);
}

void Point::setX(const int iX)
{
    miX = iX;
}

void Point::setY(const int iY)
{
    miY = iY;
}

void Point::setZ(const int iZ)
{
    miZ = iZ;
}

Point &Point::operator=(const Point &refCopy)
{
    setX(refCopy.getX());
    setY(refCopy.getY());
    setZ(refCopy.getZ());
    setSubPoint(refCopy.getSubPoint());

    return(*this);
}

bool Point::operator==(const Point &refOther) const
{
    if(getSubPoint() == nullptr)
        if(refOther.getSubPoint() == nullptr)
            return  (   (getX() == refOther.getX())
                    &&  (getY() == refOther.getY())
                    &&  (getZ() == refOther.getZ()));
        else
            return(false);
    else
        return  (   (getX() == refOther.getX())
                &&  (getY() == refOther.getY())
                &&  (getZ() == refOther.getZ())
                &&  (*getSubPoint() == *refOther.getSubPoint()));
}

bool Point::operator!=(const Point &refOther) const
{
    return(!operator==(refOther));
}
