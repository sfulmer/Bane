#pragma once

#include "LoadMenuModel.h"
#include <QPainter>

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

                        LoadMenuModel &getModel() const;
                        void render(QPainter &refPainter);
                        void setModel(const LoadMenuModel &refModel);
                    };
                }
            }
        }
    }
}
