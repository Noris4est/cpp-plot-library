#ifndef FRAME_BORDER_H
#define FRAME_BORDER_H

#include <opencv2/opencv.hpp>
#include "../tools/colors/colors.hpp"

class FrameBorder
{
public:
    FrameBorder(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> rect);
    void setThickness(int thickness);
    void setColor(cv::Scalar color);
    void setVisibility(bool visibility);
    void draw(); //not for users!
private:
    std::shared_ptr<cv::Mat> frame;
    std::shared_ptr<cv::Rect> rect;
    
    int thickness;
    cv::Scalar color;
    bool visibility = true;
};
#endif /* FRAME_BORDER_H */