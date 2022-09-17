#ifndef AX_BACKGROUND_H
#define AX_BACKGROUND_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../axobject.hpp"
#include "../../../commontypes.h"
#include "../../../tools/colors/colors.hpp"

namespace ax_components
{
    class AxBackground : public AxObject
    {
    public:
        AxBackground(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            cv::Scalar color = colors::deepskyblue
        );
        void draw() override; // not for user
        void setColor(cv::Scalar);
        void setVisibility(bool flag);
    private:
        cv::Scalar color;
        bool visibility;
    };
}
#endif //AX_BACKGROUND_H