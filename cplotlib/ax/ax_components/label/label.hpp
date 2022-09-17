#ifndef LABEL_H
#define LABEL_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../../../tools/colors/colors.hpp"
#include "../axobject.hpp"

namespace ax_components
{
    class Label : public AxObject
    {
    public:
        Label(std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings);
        virtual void draw();
        void setLabel(const std::string &label);
        void setFontScale(double fontScale);
        void setFontColor(cv::Scalar fontColor);
        void setVisibility(bool visibility);
    protected:
        std::string label;
        cv::Scalar fontColor;
        double fontScale;
        bool visibility;

        int fontFace;//шрифт-тип (cv::FONT_HERSHEY_DUPLEX)
        int lineType;//cv::LINE_AA
        int lineThickness;//thisckness = 1
    };
}
#endif /* LABEL_H */