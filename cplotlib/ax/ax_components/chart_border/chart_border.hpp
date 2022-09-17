#ifndef CHART_BORDER_H
#define CHART_BORDER_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../axobject.hpp"
#include "../../../commontypes.h"
#include "../../../tools/colors/colors.hpp"

namespace ax_components
{
    class ChartBorder : public AxObject
    {
    public:
        ChartBorder(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings
        );
        void draw() override;
    private:
        cv::Scalar color;
        bool visibility;
        int thickness;
    };
}
#endif //CHART_BORDER_H