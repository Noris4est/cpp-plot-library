#include "frametext.hpp"


void frameText::putText(
    cv::Mat &img, 
    const cv::String& text,
    int cornerType, 
    cv::Point cornPos, 
    double angle, 
    int fontFace, 
    double fontScale, 
    cv::Scalar color, 
    int thickness, 
    int lineType
)
{
    cv::Point bottomLeftPos;// потому что в стандартный cv::putText подается bottomLeft
    int baseline = 0;
    cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
    int textWidth = textSize.width;
    int textHeight = textSize.height;
    switch (cornerType)
    {
    case bottomLeft:
        {
            bottomLeftPos = cornPos;
        }
        break;
    case bottomRight:
        {
            bottomLeftPos = {cornPos.x - textWidth, cornPos.y};
        }
        break;
    case bottomCenter:
        {
            bottomLeftPos = {cornPos.x - textWidth/2, cornPos.y};
        }
        break;
    case topLeft:
        {
            bottomLeftPos = {cornPos.x, cornPos.y + textHeight};
        }
        break;
    case topRight:
        {
            bottomLeftPos = {cornPos.x - textWidth, cornPos.y + textHeight};
        }
        break;
    case topCenter:
        {
            bottomLeftPos = {cornPos.x - textWidth/2, cornPos.y + textHeight};
        }
        break;
    case centerLeft:
        {
            bottomLeftPos = {cornPos.x, cornPos.y + textHeight/2};
        }
        break;
    case centerRight:
        {
            bottomLeftPos = {cornPos.x - textWidth, cornPos.y + textHeight/2};
        }
        break;
    case center:
        {
            bottomLeftPos = {cornPos.x - textWidth/2, cornPos.y + textHeight/2};
        }
    default:
        break;
    }
    if(angle!= 0)
    {
        cv::Mat text_image_color(img.size()*2,img.type());
        text_image_color = cv::Scalar(0, 0, 0);
        cv::Mat text_image_white = text_image_color.clone();
        cv::Point offset(img.cols/2, img.rows/2); //необходимо, чтобы не обрезало надписи
        cv::putText(text_image_color,
            text,
            bottomLeftPos + offset,
            fontFace,
            fontScale,
            color,
            thickness,
            lineType);
        cv::putText(text_image_white,
            text,
            bottomLeftPos + offset,
            fontFace,
            fontScale,
            cv::Scalar(255,255,255),
            thickness,
            lineType);
        // Вращение осуществляется вокруг cornPos
        cv::Mat rotationMatrix = cv::getRotationMatrix2D(cornPos + offset, angle, 1.0);//couter clockwise rotation
        cv::warpAffine(text_image_color, text_image_color, rotationMatrix, text_image_color.size());
        cv::warpAffine(text_image_white, text_image_white, rotationMatrix, text_image_white.size());
        text_image_color = text_image_color(cv::Rect(offset, img.size()));
        text_image_white = text_image_white(cv::Rect(offset, img.size()));
        img -= text_image_white;
        img += text_image_color;
    }
    else
    {
        //angle == 0
        cv::putText(img,
        text,
        bottomLeftPos,
        fontFace,
        fontScale,
        color,
        thickness,
        lineType);
    }
}