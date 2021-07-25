#include "Properties.h"

using namespace net::draconia::util;

Properties::Properties()
{ }

Properties::Properties(const QMap<QString, QMap<QString, QVariant>> &mapValues)
    :   mMapValues(mapValues)
{ }

Properties::Properties(const Properties &refCopy)
    :   Properties(const_cast<Properties &>(refCopy).getValues())
{ }

Properties::~Properties()
{ }

QMap<QString, QMap<QString, QVariant>> &Properties::getValues() const
{
    return(const_cast<QMap<QString, QMap<QString, QVariant>> &>(mMapValues));
}

void Properties::setValues(const QMap<QString, QMap<QString, QVariant>> &mapValues)
{
    mMapValues = mapValue;
}

Properties &Properties::operator=(const Properties &refCopy)
{
    setValues(refCopy.getValues());

    return(*this);
}

bool Properties::operator==(const Properties &refOther) const
{
    return(getValues() == refOther.getValues());
}

bool Properties::operator!=(const Properties &refOther) const
{
    return(!operator==(refOther));
}
