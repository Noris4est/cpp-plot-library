#include "ax_border.hpp"

namespace ax_components
{
    AxBorder::AxBorder
    (
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect
    )
    :
    AxObject(frame, axRect)
    {
        visibility = true;
        color = colors::black;        
        thickness = 1;
    }
    void AxBorder::draw()
    {
        if(visibility)
        {
            cv::rectangle(*frame, *axRect, color, thickness);
        }
    }
}