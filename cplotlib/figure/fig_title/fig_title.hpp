#ifndef FIG_TITLE_H
#define FIG_TITLE_H

#include <opencv2/opencv.hpp>
#include "../../commontypes.h"
#include <memory>
#include "../../tools/colors/colors.hpp"
#include "../../tools/frametext/frametext.hpp"

class FigTitle
{
public:
    FigTitle(std::shared_ptr<cv::Mat> frame,
        cplt::OffsetSettings offset);
    void setTitle(const std::string &titleText);
    void setFontScale(double fontScale);
    void setFontColor(cv::Scalar fontColor);
    void setVisibility(bool visibility);
    void draw(); //not for user
private:
    std::shared_ptr<cv::Mat> frame;
    cplt::OffsetSettings offset;
    
    std::string titleText;
    cv::Scalar fontColor;
    double fontScale;
    bool visibility;
    int fontFace;//шрифт-тип (cv::FONT_HERSHEY_DUPLEX)
    int lineType;//cv::LINE_AA
    int lineThickness;//thisckness = 1
};

#endif // FIG_TITLE_H