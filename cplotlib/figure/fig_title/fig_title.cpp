#include "fig_title.hpp"

FigTitle::FigTitle(
    bool needRefresh,
    std::shared_ptr<cv::Mat> frame,
    cplt::OffsetSettings offset) 
    : 
    needRefresh(needRefresh), frame(frame), offset(offset)
{
    titleText = "Default title";
    fontColor = colors::black;
    fontScale = 1;
    visibility = true;

    
    fontFace = cv::FONT_HERSHEY_DUPLEX;
    lineType = cv::LINE_AA;
    lineThickness = 1;
    needRefresh = true;
}
void FigTitle::setTitle(const std::string &titleText)
{
    this->titleText = titleText;
    needRefresh = true;
}
void FigTitle::setFontColor(cv::Scalar fontColor)
{
    this->fontColor = fontColor;
    needRefresh = true;
}
void FigTitle::setVisibility(bool visibilityFlag)
{
    this->visibility = visibilityFlag;
    needRefresh = true;
}
void FigTitle::setFontScale(double fontScale)
{
    this->fontScale = fontScale;
    needRefresh = true;
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