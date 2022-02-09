#pragma once

#include <QFile>

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace bane
            {
                class BeanRepository
                {
                    static BeanRepository msObjRepository;

                    QFile mFileConfiguration, mFileSave;
                protected:
                    BeanRepository();
                public:
                    ~BeanRepository();

                    static BeanRepository &getInstance();

                    QFile &getConfigurationFile();
                    QFile &getSaveFile();
                };
            }
        }
    }
}
