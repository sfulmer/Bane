#pragma once

#include <QList>
#include "Renderable.h"
#include "Party.h"
#include "SavePoint.h"

using net::draconia::games::bane::model::Party;
using net::draconia::games::bane::model::SavePoint;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace ui
                {
                    class Scene : public Renderable
                    {
                        QImage *mImgScene;
                        QList<Party> mLstParties;
                    public:
                        virtual ~Scene() = 0;

                        QImage *getSceneImage() const;
                        void setSceneImage(const QImage *imgScene);
                    };
                }
            }
        }
    }
}
