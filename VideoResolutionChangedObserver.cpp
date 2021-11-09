#include "SettingsModel.h"
#include "VideoResolutionChangedObserver.h"

using net::draconia::games::bane::model::SettingsModel;
using namespace net::draconia::games::bane::ui::observers;

QComboBox *VideoResolutionChangedObserver::getVideoResolutionsComboBox() const
{
    return(mCboVideoResolutions);
}

void VideoResolutionChangedObserver::setVideoResolutionsComboBox(const QComboBox *cboVideoResolutions)
{
    mCboVideoResolutions = const_cast<QComboBox *>(cboVideoResolutions);
}

VideoResolutionChangedObserver::VideoResolutionChangedObserver(const QComboBox *cboVideoResolutions)
    :   Observer()
    ,   mCboVideoResolutions(const_cast<QComboBox *>(cboVideoResolutions))
{ }

VideoResolutionChangedObserver::VideoResolutionChangedObserver(const VideoResolutionChangedObserver &refCopy)
    :   VideoResolutionChangedObserver(const_cast<VideoResolutionChangedObserver &>(refCopy).getVideoResolutionsComboBox())
{ }

VideoResolutionChangedObserver::~VideoResolutionChangedObserver()
{ }

void VideoResolutionChangedObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));
    const QList<SettingsModel::VideoResolution> &lstAvailableVideoResolutions = refModel.getAvailableVideoResolutions();
    const SettingsModel::VideoResolution &refComboBoxValue = lstAvailableVideoResolutions[getVideoResolutionsComboBox()->currentIndex()];

    if(refModel.getVideoResolution() != refComboBoxValue)
        {
        SettingsModel::VideoResolution &refVideoResolutionToSet = refModel.getVideoResolution();

        getVideoResolutionsComboBox()->setCurrentIndex(lstAvailableVideoResolutions.indexOf(refVideoResolutionToSet));
        }
}
