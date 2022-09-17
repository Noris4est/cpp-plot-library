#include "fig_title.hpp"

FigTitle::FigTitle(std::shared_ptr<cv::Mat> frame,
        cplt::OffsetSettings offset) : frame(frame), offset(offset)
{
    titleText = "Default title";
    fontColor = colors::black;
    fontScale = 1;
    visibility = true;

    
    fontFace = cv::FONT_HERSHEY_DUPLEX;
    lineType = cv::LINE_AA;
    lineThickness = 1;
}
void FigTitle::setTitle(const std::string &titleText)
{
    this->titleText = titleText;
}
void FigTitle::setFontColor(cv::Scalar fontColor)
{
    this->fontColor = fontColor;
}
void FigTitle::setVisibility(bool visibilityFlag)
{
    this->visibility = visibilityFlag;
}
void FigTitle::setFontScale(double fontScale)
{
    this->fontScale = fontScale;
}
void FigTitle::draw()
{
    int precisionOffset = 0;
    cv::Point titleCenterPos = {frame->cols/2, + frameText::standartSymbolHeight/2 + precisionOffset};
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