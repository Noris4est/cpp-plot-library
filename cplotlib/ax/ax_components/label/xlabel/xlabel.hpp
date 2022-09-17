#ifndef XLABEL_H
#define XLABEL_H

#include <opencv2/opencv.hpp>
#include "../label.hpp"
#include "../../../../tools/frametext/frametext.hpp"
namespace ax_components
{
    class Xlabel : public Label
    {
    public:
        Xlabel(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings);
        void draw() override;
    };
}

#endif /* XLABEL_H */