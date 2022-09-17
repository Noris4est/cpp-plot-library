#include "ax_background.hpp"

namespace ax_components
{
    AxBackground::AxBackground
    (
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        cv::Scalar color
    )
    :
    AxObject(frame, axRect),
    color(color)
    {
        visibility = true;
    }
    void AxBackground::draw()
    {
        if(visibility)
        {
            cv::rectangle(*frame, *axRect, color, -1);
        }
    }
}