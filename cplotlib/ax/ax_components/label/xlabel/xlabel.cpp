#include "xlabel.hpp"

namespace ax_components
{
    Xlabel::Xlabel(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings)
        : Label(frame, axRect, offsetSettings)
        {}

    void Xlabel::draw()
    {
        cv::Rect chartRect;
        chartRect = createChartRect(); // using frame, axRect, offsetSettings
        int precisionOffset = 5;
        cv::Point xlabelBottomCenterCornerPos = cv::Point(
            chartRect.x + chartRect.width/2, 
            axRect->y + axRect->height - precisionOffset);
        
        frameText::putText(
            *frame,
            label,
            frameText::bottomCenter,
            xlabelBottomCenterCornerPos,
            0,
            fontFace,
            fontScale,
            fontColor,
            lineThickness,
            lineType
        );
    } // END -- draw()
}