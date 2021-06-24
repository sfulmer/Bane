#include "LoadMenuRenderer.h"

using namespace net::draconia::games::bane::ui;

LoadMenuRenderer::LoadMenuRenderer(const LoadMenuModel &refModel)
    :   mObjModel(refModel)
{ }

LoadMenuRenderer::LoadMenuRenderer(const LoadMenuRenderer &refCopy)
    :   LoadMenuRenderer(refCopy.getModel())
{ }

LoadMenuRenderer::~LoadMenuRenderer()
{ }

LoadMenuModel &LoadMenuRenderer::getModel() const
{
    return(const_cast<LoadMenuRenderer &>(*this).mObjModel);
}

void LoadMenuRenderer::render(const QPainter &refPainter)
{

}

void LoadMenuRenderer::setModel(const LoadMenuModel &refModel)
{
    mObjModel = refModel;
}
