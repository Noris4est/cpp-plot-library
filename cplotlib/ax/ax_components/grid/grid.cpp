#include "grid.hpp"

namespace ax_components
{
    Grid::Grid(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim,
        std::shared_ptr<cplt::ticks_t> xticks,
        std::shared_ptr<cplt::ticks_t> yticks)
        :
        AxObject(frame, axRect, offsetSettings, xlim, ylim, xticks, yticks)
    {
        genThickness = 1;
        genColor = colors::gray;
        specialThickness = 2;
        specialColor = colors::blue;
        visibility = true;
    }
    void Grid::setColor(cv::Scalar color)
    {
        genColor = color;
    }
    void Grid::setSpecialBaseXYcolor(cv::Scalar color)
    {
        specialColor = color;
    }
    void Grid::setThickness(int thickness)
    {
        genThickness = thickness;
    }
    void Grid::setSpecialBaseXYthickness(int thickness)
    {
        specialThickness = thickness;
    }

    void Grid::draw()
    {
        cv::Mat chartFrame;
        cv::Rect chartRect;
        chartRect = createChartRect(); // using frame, axRect, offsetSettings
        chartFrame = (*frame)(chartRect);
        delOutsiders(*xticks, *xlim); // удаление значений вне диапазонов xlim, ylim ( и значений, находящихся на границе тоже)
        delOutsiders(*yticks, *ylim);
        std::vector<int> chartXticks, chartYticks;
        scalling(*xticks, chartXticks, xlim->first, xlim->second, 0, chartFrame.cols-1);
        scalling(*yticks, chartYticks, ylim->first, ylim->second, chartFrame.rows-1, 0); // инверсия
        cv::Point p1, p2;
        for (auto xtick : chartXticks)
        {
                p1 = {xtick, 0};
                p2 = {xtick, chartFrame.rows};
                cv::line(chartFrame, p1, p2, this->genColor, this->genThickness);
        }
        for (auto ytick : chartYticks)
        {
                p1 = {0, ytick};
                p2 = {chartFrame.cols, ytick};
                cv::line(chartFrame, p1, p2, this->genColor, this->genThickness);
        }
    }
}