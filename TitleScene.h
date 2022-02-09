#pragma once

#include "LoadMenu.h"
#include <QFont>
#include "Scene.h"

using net::draconia::games::bane::ui::model::LoadMenu;

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
                    class TitleScene : public Scene
                    {
                        QFont mFontTitle;
                        QImage mImgTitle;
                        LoadMenu mMnuLoad;
                    protected:
                        QFont getTitleFont();
                        QImage getTitleImage();
                        LoadMenu &getLoadMenu();
                    public:
                        TitleScene();
                        TitleScene(const TitleScene &refCopy);
                        ~TitleScene();

                        virtual void render(const QPainter &refPainter);
                    };
                }
            }
        }
    }
}
