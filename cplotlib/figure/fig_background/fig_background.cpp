#include "fig_background.hpp"

FigBackground::FigBackground(
    std::shared_ptr<cv::Mat> frame,
    cv::Scalar color
) 
    : 
    frame(frame),
    color(color)
{
    visibility = true;
}

void FigBackground::setColor(cv::Scalar color)
{
    this->color = color;
}

void FigBackground::setVisibility(bool visibility)
{
    this->visibility = visibility;
}

void FigBackground::draw()
{
    if(visibility)
    {
        *frame = color;
    }
}