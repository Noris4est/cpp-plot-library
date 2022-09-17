#ifndef YLABEL_H
#define YLABEL_H

#include <opencv2/opencv.hpp>
#include "../label.hpp"
#include "../../../frametext/frametext.hpp"
namespace ax_components
{
    class Ylabel : public Label
    {
    public:
        Ylabel(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings);
        void draw() override;
    };
}

#endif /* YLABEL_H */