#ifndef FRAMETEXT_HPP
#define FRAMETEXT_HPP

#include <opencv2/opencv.hpp>

namespace frameText
{
    void putText(
        cv::Mat &img, 
        const cv::String& text,
        int cornerType, 
        cv::Point cornPos, 
        double angle = 0, 
        int fontFace = cv::FONT_HERSHEY_DUPLEX, 
        double fontScale = 1, 
        cv::Scalar color = cv::Scalar(), 
        int thickness = 1, 
        int lineType = cv::LINE_AA
        );
    static int standartSymbolWidth = 18;
    static int standartSymbolHeight = 30;
    enum corner
    {
        bottomLeft,
        bottomRight,
        bottomCenter,
        topLeft,
        topRight,
        topCenter,
        centerLeft,
        centerRight,
        center
    };
}

#endif /* FRAMETEXT_HPP */