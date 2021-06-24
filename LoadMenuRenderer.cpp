#include "LoadMenuRenderer.h"

using namespace net::draconia::games::bane::ui;

LoadMenuRenderer::LoadMenuRenderer()
{
    mObjModel.addOption("New Game");
    mObjModel.addOption("Load Game");
    mObjModel.addOption("Options/Settings");
}

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

void LoadMenuRenderer::render(QPainter &refPainter)
{
    unsigned iY = 50;

    refPainter.save();

    for(QString sOption : getModel().getOptions())
        refPainter.drawText(QPoint(50, iY *= 50), sOption);

    refPainter.restore();
}

void LoadMenuRenderer::setModel(const LoadMenuModel &refModel)
{
    mObjModel = refModel;
}
