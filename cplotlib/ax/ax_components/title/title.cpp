#include "title.hpp"

namespace ax_components
{
    Title::Title(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings)
        :
        AxObject(frame, axRect, offsetSettings)
    {
        titleText = "Default title";
        fontColor = colors::black;
        fontScale = 0.7;
        visibility = true;

        
        fontFace = cv::FONT_HERSHEY_DUPLEX;
        lineType = cv::LINE_AA;
        lineThickness = 1;
    }
    void Title::setTitle(const std::string &titleText)
    {
        this->titleText = titleText;
    }
    void Title::setFontColor(cv::Scalar fontColor)
    {
        this->fontColor = fontColor;
    }
    void Title::setVisibility(bool visibilityFlag)
    {
        this->visibility = visibilityFlag;
    }
    void Title::setFontScale(double fontScale)
    {
        this->fontScale = fontScale;
    }
    void Title::draw()
    {
        int precisionOffset = 0;
        cv::Point titleCenterPos = {axRect->x + axRect->width/2, axRect->y + frameText::standartSymbolHeight/2 + precisionOffset};
        frameText::putText(
            *frame,
            titleText,
            frameText::center,
            titleCenterPos,
            0,
            fontFace,
            fontScale,
            fontColor,
            lineThickness,
            lineType
        );
    }
}