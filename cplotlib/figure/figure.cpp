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
        figBackground = std::make_shared<FigBackground>(needRefresh, frame, colors::brown);
        figTitle = std::make_shared<FigTitle>(needRefresh, frame, offsetSettings);
        refresh();
    }

    void Figure::refresh()
    {
        if(needRefresh)
        {
            figBackground->draw();
            figTitle->draw();
            needRefresh = false;
            if(axesManager != nullptr)
                axesManager->refreshAll();
        }
        else
        {
            if(axesManager != nullptr)
                axesManager->refreshChanged();
        }
    }
    std::shared_ptr<cplt::AxesManager> Figure::addSubplots(int nRows,int nCols)
    {
        if (nRows < 1 || nCols < 1)
            throw std::runtime_error("Error: rRows < 0 or nCols < 0");
        cv::Rect axesRect = getAxesRect();
        axesManager = std::make_shared<cplt::AxesManager>(nRows, nCols, getAxesRect(), frame);
        return axesManager;
    }

    void Figure::show(const std::string &winName)
    {
        refresh();
        cv::imshow(winName, *frame);
    }

    void Figure::save(const std::string &path)
    {
        refresh();
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
