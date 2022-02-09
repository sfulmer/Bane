#include "BeanRepository.h"

using namespace net::draconia::games::bane;

BeanRepository BeanRepository::msObjRepository;

BeanRepository::BeanRepository()
    :   mFileConfiguration("Bane.conf")
    ,   mFileSave("Save.json")
{ }

BeanRepository::~BeanRepository()
{ }

BeanRepository &BeanRepository::getInstance()
{
    return(msObjRepository);
}

QFile &BeanRepository::getConfigurationFile()
{
    return(mFileConfiguration);
}

QFile &BeanRepository::getSaveFile()
{
    return(mFileSave);
}
