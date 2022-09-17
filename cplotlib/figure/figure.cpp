#include "figure.hpp"

namespace cplt
{
    Figure::Figure(cv::Size figsize)
    {
        frame = std::make_shared<cv::Mat>(figsize, CV_8UC3);
        this->figsize = std::make_shared<cv::Size>(figsize);
        // *frame = colors::white;
        offsetSettings.top = 0.1;
        offsetSettings.bottom = 0.01;
        offsetSettings.right = 0.01;
        offsetSettings.left = 0.01;
        figBackground = std::make_shared<FigBackground>(frame, colors::brown);
        figBackground->draw();
        // if(figSettings.figureTitleShowOn)
        // {
        //     double standartSymbolWidth = 18.4;
        //     int titleWidth = round(figSettings.title.size()*standartSymbolWidth*figSettings.titleFontScale);
        //     double standartSymbolHeight = 30;
        //     int titleHeight = round(standartSymbolHeight*figSettings.titleFontScale);
        //     cv::Point titleCenterPosition = cv::Point(figSettings.figsize.width/2, figSettings.figsize.height * 0.5 * figSettings.topOffset);
        //     cv::Point titleTopLeftPos = titleCenterPosition + cv::Point(-titleWidth/2, titleHeight/2);
        //     cv::putText(*frame, figSettings.title, titleTopLeftPos, cv::FONT_HERSHEY_DUPLEX, figSettings.titleFontScale, figSettings.titleColor,1,cv::LINE_AA);
        // }
    }

    std::shared_ptr<cplt::AxesManager> Figure::addSubplots(int nRows,int nCols)
    {
        cv::Rect axesRect = getAxesRect();
        axesManager = std::make_shared<cplt::AxesManager>(nRows, nCols, getAxesRect(), frame);
        return axesManager;
    }

    void Figure::show(const std::string &winName)
    {
        cv::imshow(winName, *frame);
    }

    void Figure::save(const std::string &path)
    {
        cv::imwrite(path, *frame);
    }

    cv::Rect Figure::getAxesRect()
    {
        cv::Rect axesRect;
        double xOffset, yOffset;
        xOffset = round(offsetSettings.left * figsize->width);
        yOffset = round(offsetSettings.top * figsize->height);
        axesRect.x = xOffset;
        axesRect.y = yOffset;
        axesRect.width = round( (1 - offsetSettings.left - offsetSettings.right) * figsize->width);
        axesRect.height = round( (1 - offsetSettings.top - offsetSettings.bottom) * figsize->height);
        return axesRect;
    }
}
