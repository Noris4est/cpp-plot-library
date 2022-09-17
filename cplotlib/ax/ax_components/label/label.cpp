#include "label.hpp"

namespace ax_components
{
    Label::Label(std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings)
        :
        AxObject(frame, axRect, offsetSettings)
    {
        label = "X/Y";
        fontColor = colors::black;
        fontScale = 0.7;
        visibility = true;

        
        fontFace = cv::FONT_HERSHEY_DUPLEX;
        lineType = cv::LINE_AA;
        lineThickness = 1;
    }
    void Label::draw()
    {
        throw "not override method draw()!";
    }
    void Label::setLabel(const std::string &label)
    {
        this->label = label;
        run_refresh_handlers();
    }
    void Label::setFontColor(cv::Scalar fontColor)
    {
        this->fontColor = fontColor;
        run_refresh_handlers();
    }
    void Label::setFontScale(double fontScale)
    {
        this->fontScale = fontScale;
        run_refresh_handlers();
    }
    void Label::setVisibility(bool visibility)
    {
        this->visibility = visibility;
        run_refresh_handlers();
    }
}