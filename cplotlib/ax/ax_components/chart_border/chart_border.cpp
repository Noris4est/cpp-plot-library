#include "chart_border.hpp"

namespace ax_components
{
    ChartBorder::ChartBorder
    (
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings
    )
    :
    AxObject(frame, axRect, offsetSettings)
    {
        visibility = true;
        color = colors::black;
        thickness = 1;
    }
    void ChartBorder::draw()
    {
        if(visibility)
        {
            cv::Rect chartRect = createChartRect();
            cv::rectangle(*frame, chartRect, color, thickness);
        }
    }
}