#pragma once

#include<QPainter>

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
                    class Renderable
                    {
                    public:
                        virtual ~Renderable() = 0;

                        virtual void render(const QPainter &refPainter) = 0;
                    };
                }
            }
        }
    }
}
