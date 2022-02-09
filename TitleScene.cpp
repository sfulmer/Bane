#include "TitleScene.h"

using namespace net::draconia::games::bane::ui;

QFont TitleScene::getTitleFont()
{
    return(mFontTitle);
}

QImage TitleScene::getTitleImage()
{
    return(mImgTitle);
}

LoadMenu &TitleScene::getLoadMenu()
{
    return(mMnuLoad);
}

TitleScene::TitleScene()
    :   Scene()
{ }

TitleScene::TitleScene(const TitleScene &refCopy)
    :   Scene(refCopy)
    ,   mFontTitle(const_cast<TitleScene &>(refCopy).getTitleFont())
    ,   mImgTitle(const_cast<TitleScene &>(refCopy).getTitleImage())
    ,   mMnuLoad(const_cast<TitleScene &>(refCopy).getLoadMenu())
{ }

TitleScene::~TitleScene()
{ }

void TitleScene::render(const QPainter &refPainter)
{
    QPainter &painter = const_cast<QPainter &>(refPainter);

    painter.save();
    painter.restore();
}
