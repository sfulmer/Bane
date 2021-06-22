#pragma once

#include "Observable.h"
#include <QImage>
#include <QString>

using net::draconia::util::Observable;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                namespace model
                {
                    class Item : public Observable
                    {
                        QImage mImgThumbnail;
                        QString msName;
                        int miCost;
                    public:
                        Item();
                        Item(const QString sName, const int iCost);
                        Item(const QString sName, const int iCost, const QImage &imgThumbnail);
                        Item(const Item &refCopy);
                        ~Item();

                        int getCost() const;
                        QString &getName() const;
                        QImage &getThumbnail() const;
                        void setCost(const int iCost);
                        void setName(const QString sName);
                        void setThumbnail(const QImage &imgThumbnail);

                        Item &operator=(const Item &refCopy);
                        bool operator==(const Item &refOther) const;
                        bool operator!=(const Item &refOther) const;
                    };
                }
            }
        }
    }
}
