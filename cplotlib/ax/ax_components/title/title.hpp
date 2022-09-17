#ifndef TITLE_H
#define TITLE_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../../../tools/colors/colors.hpp"
#include "../../../tools/frametext/frametext.hpp"
#include <sstream>
#include "../axobject.hpp"

namespace ax_components
{
    class Title : public AxObject
    {
    public:
        Title(std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings);
        void setTitle(const std::string &titleText);
        void setFontScale(double fontScale);
        void setFontColor(cv::Scalar fontColor);
        void setVisibility(bool visibility);
        void draw() override; //not for user
    protected:
        std::string titleText;
        cv::Scalar fontColor;
        double fontScale;
        bool visibility;
        int fontFace;//шрифт-тип (cv::FONT_HERSHEY_DUPLEX)
        int lineType;//cv::LINE_AA
        int lineThickness;//thisckness = 1
    };
}
#endif /* TITLE_H */