#ifndef AX_BORDER
#define AX_BORDER

#include <memory>
#include <opencv2/opencv.hpp>
#include "../axobject.hpp"
#include "../../../commontypes.h"
#include "../../../tools/colors/colors.hpp"

namespace ax_components
{
    class AxBorder : public AxObject
    {
    public:
        AxBorder(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect
        );
        void draw() override;
    private:
        cv::Scalar color;
        bool visibility;
        int thickness;
    };
}
#endif //AX_BORDER