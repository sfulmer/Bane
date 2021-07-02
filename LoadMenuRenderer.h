#pragma once

#include "BaneController.h"
#include "LoadMenuModel.h"
#include <QPainter>

using net::draconia::games::bane::BaneController;
using net::draconia::games::bane::ui::model::LoadMenuModel;

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
                    class LoadMenuRenderer
                    {
                        LoadMenuModel mObjModel;
                    public:
                        LoadMenuRenderer();
                        LoadMenuRenderer(const LoadMenuModel &refModel);
                        LoadMenuRenderer(const LoadMenuRenderer &refCopy);
                        ~LoadMenuRenderer();

                        BaneController &getController() const;
                        LoadMenuModel &getModel() const;
                        void render(QPainter &refPainter, const QPoint &ptTopLeft);
                        void setModel(const LoadMenuModel &refModel);
                    };
                }
            }
        }
    }
}
