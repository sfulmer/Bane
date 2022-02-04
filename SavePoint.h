#pragma once

#include "Point.h"
#include "Renderable.h"

using net::draconia::games::bane::ui::Renderable;

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
                    class SavePoint : public Renderable
                    {
                        Point *mPtrPoint;
                    public:
                        SavePoint();
                        SavePoint(const Point *ptrPoint);
                        SavePoint(const SavePoint &refSavePoint);
                        ~SavePoint();

                        virtual void render(const QPainter &refPainter);

                        void save();
                    };
                }
            }
        }
    }
}
