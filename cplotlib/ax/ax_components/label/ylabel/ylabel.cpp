#include "ylabel.hpp"

namespace ax_components
{
    Ylabel::Ylabel(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings) 
        : 
        Label(frame, axRect, offsetSettings){};

    void Ylabel::draw()
    {
        cv::Rect chartRect;
        chartRect = createChartRect(); // using frame, axRect, offsetSettings
        int precisionOffset = 4;
        cv::Point ylabelTopCenterCornerPos = cv::Point(
            axRect->x + precisionOffset, 
            chartRect.y + chartRect.height/2);

        frameText::putText(
            *frame,
            label,
            frameText::topCenter,
            ylabelTopCenterCornerPos,
            90,
            fontFace,
            fontScale,
            fontColor,
            lineThickness,
            lineType
        );
    } // --  END draw()
}