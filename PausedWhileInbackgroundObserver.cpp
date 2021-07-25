#include "PausedWhileInBackgroundObserver.h"
#include "SettingsModel.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QCheckBox *PausedWhileInBackgroundObserver::getPausedWhileInBackgroundCheckBox() const
{
    return(mChkPausedWhileInBackground);
}

void PausedWhileInBackgroundObserver::setPausedWhileInBackgroundCheckBox(const QCheckBox *chkPausedWhileInBackround)
{
    mChkPausedWhileInBackground = const_cast<QCheckBox *>(chkPausedWhileInBackround);
}

PausedWhileInBackgroundObserver::PausedWhileInBackgroundObserver(const QCheckBox *chkPausedWhileInBackground)
    :   Observer()
    ,   mChkPausedWhileInBackground(const_cast<QCheckBox *>(chkPausedWhileInBackground))
{ }

PausedWhileInBackgroundObserver::PausedWhileInBackgroundObserver(const PausedWhileInBackgroundObserver &refCopy)
    :   PausedWhileInBackgroundObserver(const_cast<PausedWhileInBackgroundObserver &>(refCopy).getPausedWhileInBackgroundCheckBox())
{ }

PausedWhileInBackgroundObserver::~PausedWhileInBackgroundObserver()
{ }

void PausedWhileInBackgroundObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));

    if(refModel.isPausedWhileInBackground() != getPausedWhileInBackgroundCheckBox()->isChecked())
        getPausedWhileInBackgroundCheckBox()->setChecked(refModel.isPausedWhileInBackground());
}
