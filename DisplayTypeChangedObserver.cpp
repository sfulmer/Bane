#include "DisplayTypeChangedObserver.h"
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QComboBox *DisplayTypeChangedObserver::getDisplayTypeComboBox() const
{
    return(mCboDisplayType);
}

void DisplayTypeChangedObserver::setDisplayTypeComboBox(const QComboBox *cboDisplayType)
{
    mCboDisplayType = const_cast<QComboBox *>(cboDisplayType);
}

DisplayTypeChangedObserver::DisplayTypeChangedObserver(const QComboBox *cboDisplayType)
    :   Observer()
    ,   mCboDisplayType(const_cast<QComboBox *>(cboDisplayType))
{ }

DisplayTypeChangedObserver::DisplayTypeChangedObserver(const DisplayTypeChangedObserver &refCopy)
    :   DisplayTypeChangedObserver(const_cast<DisplayTypeChangedObserver &>(refCopy).getDisplayTypeComboBox())
{ }

DisplayTypeChangedObserver::~DisplayTypeChangedObserver()
{ }

void DisplayTypeChangedObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));
    QMap<int, QVariant> mapValues = getDisplayTypeComboBox()->model()->itemData(QModelIndex());

    if(refModel.getDisplayType() != mapValues[getDisplayTypeComboBox()->currentIndex()])
        getDisplayTypeComboBox()->setCurrentIndex(mapValues.key(refModel.getDisplayType(), -1));
}
