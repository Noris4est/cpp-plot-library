#ifndef FRAME_BACKGROUND_H
#define FRAME_BACKGROUND_H

#include <opencv2/opencv.hpp>
#include "../../tools/colors/colors.hpp"

class FigBackground
{
public:
    FigBackground(
        bool needRefresh,
        std::shared_ptr<cv::Mat> frame,
        cv::Scalar color = colors::white);
    void setColor(cv::Scalar color);
    void setVisibility(bool visibility);
    void draw(); //not for users!
private:
    std::shared_ptr<cv::Mat> frame;
    cv::Scalar color;
    bool visibility = true;
    bool &needRefresh;
};
#endif /* FRAME_BACKGROUND_H */