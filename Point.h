#pragma once

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace model
                {
                    class Point
                    {
                        int miX, miY, miZ;
                        Point *mPtrSubPoint;
                    public:
                        Point();
                        Point(const int iX, const int iY, const int iZ = 0, const Point *ptrSubPoint = nullptr);
                        Point(const Point &refCopy);
                        ~Point();

                        Point *getSubPoint() const;
                        int getX() const;
                        int getY() const;
                        int getZ() const;
                        void setSubPoint(const Point *ptrSubPoint);
                        void setX(const int iX);
                        void setY(const int iY);
                        void setZ(const int iZ);

                        Point &operator=(const Point &refCopy);
                        bool operator==(const Point &refOther) const;
                        bool operator!=(const Point &refOther) const;
                    };
                }
            }
        }
    }
}
