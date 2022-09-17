#ifndef CHART_BACKGROUND_H
#define CHART_BACKGROUND_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../axobject.hpp"
#include "../../../commontypes.h"
#include "../../../tools/colors/colors.hpp"

namespace ax_components
{
    class ChartBackground : public AxObject
    {
    public:
        ChartBackground(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            cv::Scalar color
        );
        void draw() override;
        void setColor(cv::Scalar color);
    private:
        cv::Scalar color;
        bool visibility = true;
    };
}
#endif //CHART_BACKGROUND_H