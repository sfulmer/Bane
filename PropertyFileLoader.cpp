#include "PropertyFileLoader.h"
#include <QTextStream>

using namespace net::draconia::util;

QFile &PropertyFileLoader::getPropertiesFile()
{
    return(mFileProperties);
}

PropertyFileLoader::PropertyFileLoader(const QString &sFilename)
    :   mFileProperties(sFilename)
{ }

Properties PropertyFileLoader::load()
{
    Properties objProperties;
    QString line;

    if(!getPropertiesFile().open(QIODevice::ReadOnly | QIODevice::Text))
        return(objProperties);

    QTextStream in(&getPropertiesFile());

    line = in.readLine();

    while(!line.isNull())
        {
        QStringList parts = line.split("=");

        objProperties.getValues().insert(parts[0], parts[1]);

        line = in.readLine();
        }

    getPropertiesFile().close();

    return(objProperties);
}

Properties PropertyFileLoader::load(const QString &sFilename)
{
    return(PropertyFileLoader(sFilename).load());
}

void PropertyFileLoader::save(const Properties &refProperties)
{
    QList<QString> lstKeys = refProperties.getValues().keys();

    if(!getPropertiesFile().open(QIODevice::ReadWrite))
        return;

    for(QString &sKey : lstKeys)
        {
        QString sToWrite = QString("%1").arg(sKey) + "=" + QString("%1").arg(const_cast<QVariant &>(refProperties.getValues()[sKey]).toString());

        getPropertiesFile().write(sToWrite.toUtf8());
        }

    getPropertiesFile().flush();
    getPropertiesFile().close();
}

void PropertyFileLoader::save(const QString &sFilename, const Properties &refProperties)
{
    PropertyFileLoader(sFilename).save(refProperties);
}
