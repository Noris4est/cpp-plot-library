#include "chart_background.hpp"

namespace ax_components
{
    ChartBackground::ChartBackground
    (
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        cv::Scalar color = colors::white
    )
    :
    AxObject(frame, axRect, offsetSettings),
    color(color)
    {
        visibility = true;
    }
    void ChartBackground::draw()
    {
        if(visibility)
        {
            cv::Rect chartRect = createChartRect();
            cv::rectangle(*frame, chartRect, color, -1);
        }
    }
    void ChartBackground::setColor(cv::Scalar color)
    {
        this->color = color;
    }
}