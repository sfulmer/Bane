#include "LanguageChangedObserver.h"
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QComboBox *LanguageChangedObserver::getLanguageComboBox() const
{
    return(mCboLanguage);
}

void LanguageChangedObserver::setLanguageComboBox(const QComboBox *cboLanguage)
{
    mCboLanguage = const_cast<QComboBox *>(cboLanguage);
}

LanguageChangedObserver::LanguageChangedObserver(const QComboBox *cboLanguage)
    :   Observer()
    ,   mCboLanguage(const_cast<QComboBox *>(cboLanguage))
{ }

LanguageChangedObserver::LanguageChangedObserver(const LanguageChangedObserver &refCopy)
    :   LanguageChangedObserver(const_cast<LanguageChangedObserver &>(refCopy).getLanguageComboBox())
{ }

LanguageChangedObserver::~LanguageChangedObserver()
{ }

void LanguageChangedObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));
    const QList<SettingsModel::Language> &lstAvailableLanguages = refModel.getAvailableLanguages();
    const SettingsModel::Language &refComboBoxValue = lstAvailableLanguages[getLanguageComboBox()->currentIndex()];

    if(refModel.getLanguage() != refComboBoxValue)
        {
        SettingsModel::Language &refLanguageToSet = refModel.getLanguage();

        getLanguageComboBox()->setCurrentIndex(lstAvailableLanguages.indexOf(refLanguageToSet));
        }
}
