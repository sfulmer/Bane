#pragma once

#include "Observable.h"
#include "Point.h"
#include <QFile>
#include "Renderable.h"

using net::draconia::games::bane::ui::Renderable;
using net::draconia::util::Observable;

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
                    class SavePoint : public Observable, public Renderable
                    {
                        Point mPtPoint;
                    protected:
                        static QFile &getFile();
                    public:
                        SavePoint();
                        SavePoint(const Point &refPoint);
                        SavePoint(const SavePoint &refSavePoint);
                        ~SavePoint();

                        Point &getPoint() const;
                        void setPoint(const Point &refPoint);

                        virtual void render(const QPainter &refPainter);

                        void save();
                    };
                }
            }
        }
    }
}
