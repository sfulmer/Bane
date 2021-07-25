#pragma once

#include <QMap>
#include <QString>
#include <QVariant>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Properties
            {
                QMap<QString, QMap<QString, QVariant>> mMapValues;
            public:
                Properties();
                Properties(const QMap<QString, QMap<QString, QVariant>> &mapValues);
                Properties(const Properties &refCopy);
                ~Properties();

                QMap<QString, QMap<QString, QVariant>> &getValues() const;
                void setValues(const QMap<QString, QMap<QString, QVariant>> &mapValues);

                Properties &operator=(const Properties &refCopy);
                bool operator==(const Properties &refOther) const;
                bool operator!=(const Properties &refOther) const;
            };
        }
    }
}
