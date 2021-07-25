#include "BaneApp.h"
#include "LoadMenuOption.h"
#include "LoadMenuRenderer.h"

using namespace net::draconia::games::bane::ui;
using net::draconia::games::bane::ui::model::LoadMenuOption;

LoadMenuRenderer::LoadMenuRenderer()
{
    mObjModel.addOption(LoadMenuOption(0,"New Game", true));
    mObjModel.addOption(LoadMenuOption(1, "Load Game", true));
    mObjModel.addOption(LoadMenuOption(3, "Exit", true));
}

LoadMenuRenderer::LoadMenuRenderer(const LoadMenuModel &refModel)
    :   mObjModel(refModel)
{ }

LoadMenuRenderer::LoadMenuRenderer(const LoadMenuRenderer &refCopy)
    :   LoadMenuRenderer(refCopy.getModel())
{ }

LoadMenuRenderer::~LoadMenuRenderer()
{ }

BaneController &LoadMenuRenderer::getController() const
{
    return(static_cast<BaneApp *>(qApp)->getController());
}

LoadMenuModel &LoadMenuRenderer::getModel() const
{
    return(const_cast<LoadMenuRenderer &>(*this).mObjModel);
}

void LoadMenuRenderer::render(QPainter &refPainter, const QPoint &ptTopLeft)
{
    unsigned iY = 50 + ptTopLeft.y(), uiIndex = 0;

    refPainter.save();

    for(LoadMenuOption objOption : getModel().getOptions())
        {
        iY += 20;

        refPainter.setPen(QColor(0xf9, 0xf9, 0xf9));

        if(getModel().getSelectedIndex() == uiIndex++)
            refPainter.drawText(QPoint(ptTopLeft.x() - 15, iY), "►");

        if(!objOption.isEnabled())
            refPainter.setPen(QColor(0x88, 0x88, 0x88));

        refPainter.drawText(QPoint(ptTopLeft.x(), iY), objOption.getName());
        }

    refPainter.restore();
}

void LoadMenuRenderer::setModel(const LoadMenuModel &refModel)
{
    mObjModel = refModel;
}
