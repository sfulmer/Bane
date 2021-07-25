#pragma once

#include "Properties.h"
#include<QFile>
#include<QString>

using namespace std;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class PropertyFileLoader
            {
                QFile mFileProperties;
            protected:
                QFile &getPropertiesFile();
            public:
                PropertyFileLoader(const QString &sFilename);

                Properties load();
                static Properties load(const QString &sFilename);
                void save(const Properties &refProperties);
                static void save(const QString &sFilename, const Properties &refProperties);
            };
        }
    }
}
