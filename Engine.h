#pragma once

#include "Observable.h"
#include <QList>
#include "Scene.h"

using net::draconia::games::bane::ui::Scene;
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
                    namespace model
                    {
                        class Engine : public Observable
                        {
                            QList<Scene> mLstScenes;
                            Scene *mPtrCurrentScene;
                        protected:
                            QList<Scene> getSceneListInternal() const;
                        public:
                            Engine();
                            Engine(const QList<Scene> &lstScenes);
                            Engine(const Engine &refCopy);
                            ~Engine();

                            void addScene(const Scene &refScene);
                            void addScenes(const QList<Scene> &lstScenes);
                            Scene &getCurrentScene() const;
                            const QList<Scene> &getScenes() const;
                            void removeScene(const Scene &refScene);
                            void removeScenes(const QList<Scene> &lstScenes);

                            virtual void run();
                        };
                    }
                }
            }
        }
    }
}
