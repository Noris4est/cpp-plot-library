#include "frame_border.hpp"

FrameBorder::FrameBorder(
    std::shared_ptr<cv::Mat> frame,
    std::shared_ptr<cv::Rect> rect) 
    :
    frame(frame),
    rect(rect)
{
    color = colors::black;
    thickness = 1;
};

void FrameBorder::setColor(cv::Scalar color)
{
    this->color = color;
}

void FrameBorder::setThickness(int thickness)
{
    this->thickness = thickness;
}

void FrameBorder::setVisibility(bool visibility)
{
    this->visibility = visibility;
}

void FrameBorder::draw()
{
    if(visibility)
    {
        cv::rectangle(*frame, *rect, color, thickness);
    }
}

