#pragma once

#include<QImage>
#include<QString>

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class StatusEffect
                {
                    QImage mImgAppearance;
                    QString msName;
                public:
                    StatusEffect();
                    StatusEffect(const QString &sName);
                    StatusEffect(const QString &sName, const QImage &imgAppearance);
                    StatusEffect(const StatusEffect &refCopy);
                    virtual ~StatusEffect();

                    QImage &getAppearance() const;
                    QString &getName() const;
                    void setAppearance(const QImage &imgAppearance);
                    void setName(const QString &sName);

                    StatusEffect &operator=(const StatusEffect &refCopy);
                    bool operator==(const StatusEffect &refOther) const;
                    bool operator!=(const StatusEffect &refOther) const;
                };
            }
        }
    }
}
