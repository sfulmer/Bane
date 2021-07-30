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

    QMap<int, QVariant> mapValues = getLanguageComboBox()->model()->itemData(QModelIndex());
    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));

    if(refModel.getLanguage() != mapValues[getLanguageComboBox()->currentIndex()].value<SettingsModel::Language>())
        {
        QVariant toSet;

        toSet.setValue(refModel.getLanguage());

        getLanguageComboBox()->setCurrentIndex(mapValues.key(toSet));
        }
}
