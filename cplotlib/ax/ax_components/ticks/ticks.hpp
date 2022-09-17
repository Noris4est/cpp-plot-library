#ifndef TICKS_H
#define TICKS_H


#include <memory>
#include <opencv2/opencv.hpp>
#include "../../../tools/colors/colors.hpp"
#include "../../frametext/frametext.hpp"
#include <sstream>
#include "../axobject.hpp"
#include "../../../commontypes.h"
namespace ax_components
{
    class Ticks : public AxObject
    {
    public:
        Ticks(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim,
            std::shared_ptr<cplt::ticks_t> xticks,
            std::shared_ptr<cplt::ticks_t> yticks);
        void draw() override;
        void setXticks(const std::vector<double> &xticks);
        void setYticks(const std::vector<double> &yticks);
        void setVisibility(bool flag);
        void setFontScale(double fontScale);
        void setFontColor(cv::Scalar fontColor);
    private:
        bool visibility;
        double fontScale;
        cv::Scalar fontColor;
        int fontFace;//шрифт-тип (cv::FONT_HERSHEY_DUPLEX)
        int lineType;//cv::LINE_AA
        int lineThickness;//thisckness = 1
        int numDigitsAfterDot;
    };
}

#endif /* TICKS_HPP */