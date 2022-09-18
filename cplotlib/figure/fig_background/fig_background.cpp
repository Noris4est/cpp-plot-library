#include "fig_background.hpp"

FigBackground::FigBackground(
    bool needRefresh,
    std::shared_ptr<cv::Mat> frame,
    cv::Scalar color
) 
    :
    needRefresh(needRefresh),
    frame(frame),
    color(color)
{
    visibility = true;
    needRefresh = true;
}

void FigBackground::setColor(cv::Scalar color)
{
    this->color = color;
    needRefresh = true;
}

void FigBackground::setVisibility(bool visibility)
{
    this->visibility = visibility;
    needRefresh = true;
}

void FigBackground::draw()
{
    if(visibility)
    {
        *frame = color;
    }
}