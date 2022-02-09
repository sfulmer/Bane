#pragma once

#include <QList>
#include "Observable.h"
#include "Renderable.h"
#include "Party.h"
#include "SavePoint.h"

using net::draconia::games::bane::model::Party;
using net::draconia::games::bane::model::SavePoint;
using net::draconia::util::Observable;

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
                    class Scene : public Observable, public Renderable
                    {
                        QImage *mImgScene;
                        QList<Party> mLstParties;
                        QList<SavePoint> mLstSavePoints;
                    protected:
                        QList<Party> &getPartiesInternal() const;
                        QList<SavePoint> &getSavePointsInternal() const;
                        void setParties(const QList<Party> &lstParties);
                        void setSavePoints(const QList<SavePoint> &lstSavePoints);
                    public:
                        Scene();
                        Scene(const Scene &refCopy);
                        virtual ~Scene() = 0;

                        void addParty(const Party &refParty);
                        void addSavePoint(const SavePoint &refSavePoint);
                        const QList<Party> &getParties() const;
                        const QList<SavePoint> &getSavePoints() const;
                        QImage *getSceneImage() const;
                        void removeParty(const Party &refParty);
                        void removeSavePoint(const SavePoint &refSavePoint);
                        void setSceneImage(const QImage *imgScene);
                    };
                }
            }
        }
    }
}
