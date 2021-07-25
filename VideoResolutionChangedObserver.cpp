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

    QMap<int, QVariant> mapValues = getVideoResolutionsComboBox()->model()->itemData(QModelIndex());
    SettingsModel &refModel = static_cast<SettingsModel &>(const_cast<Observable &>(refObservable));

    if(refModel.getVideoResolution() != ((SettingsModel::VideoResolution &)(mapValues[getVideoResolutionsComboBox()->currentIndex()])))
        getVideoResolutionsComboBox()->setCurrentIndex(mapValues.key((QVariant &)(refModel.getVideoResolution())));
}
