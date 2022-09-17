#include "axesManager.hpp"

namespace cplt
{
    AxesManager::AxesManager(
        int nRows, 
        int nCols, 
        cv::Rect axesRect,
        std::shared_ptr<cv::Mat> frame) 
        : nRows(nRows),
        nCols(nCols),
        frame(frame), 
        axesRect(axesRect)
    {
        int axHeight = std::floor(axesRect.height / nRows); // строчек в одном ax-е
        int axWidth = std::floor(axesRect.width / nCols);

        cv::Size axSize(axWidth, axHeight);
        double xTopLeft, yTopLeft;
        cv::Rect currentAxRect;
        for(int i = 0; i < nRows; i++)
        {
            for(int j = 0; j < nCols; j++)
            {
                xTopLeft = axesRect.x + axWidth * j;
                yTopLeft = axesRect.y + axHeight * i;
                currentAxRect = cv::Rect(xTopLeft, yTopLeft, axSize.width, axSize.height);
                auto currentAx = std::make_shared<cplt::Ax>(frame, currentAxRect);
                set(currentAx,i,j);
            }
        }
    } // -- END AxesManager

    void AxesManager::set(const std::shared_ptr<Ax> &ax, int row, int column)
    {
        axes[cv::Point(row, column)] = ax;
    }
    std::shared_ptr<Ax> AxesManager::get(int row, int column)
    {
        return axes[cv::Point(row, column)];
    }

}