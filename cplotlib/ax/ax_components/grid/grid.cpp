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
        specialColor = colors::black;
        visibility = true;
    }
    void Grid::setColor(cv::Scalar color)
    {
        genColor = color;
        run_refresh_handlers();
    }
    void Grid::setSpecialBaseXYcolor(cv::Scalar color)
    {
        specialColor = color;
        run_refresh_handlers();
    }
    void Grid::setThickness(int thickness)
    {
        genThickness = thickness;
        run_refresh_handlers();
    }
    void Grid::setSpecialBaseXYthickness(int thickness)
    {
        specialThickness = thickness;
        run_refresh_handlers();
    }

    void Grid::draw()
    {
        cv::Mat chartFrame;
        cv::Rect chartRect;
        chartRect = createChartRect(); // using frame, axRect, offsetSettings
        chartFrame = (*frame)(chartRect);
        
        cplt::ticks_t xticks_grid, yticks_grid;
        std::copy(xticks->begin(), xticks->end(), std::back_inserter(xticks_grid));
        std::copy(yticks->begin(), yticks->end(), std::back_inserter(yticks_grid));

        delOutsiders(xticks_grid, *xlim, true); // удаление значений вне диапазонов xlim, ylim ( и значений, находящихся на границе тоже)
        delOutsiders(yticks_grid, *ylim, true);
        std::vector<int> chartXticks, chartYticks;
        scalling(*xticks, chartXticks, xlim->first, xlim->second, 0, chartFrame.cols-1);
        scalling(*yticks, chartYticks, ylim->first, ylim->second, chartFrame.rows-1, 0); // инверсия
        cv::Point p1, p2;
        int izerox = -1, izeroy = -1;
        auto itr = std::find(xticks->begin(), xticks->end(), 0);
        if(itr != xticks->end())
        {
            izerox = itr - xticks->begin();
            p1 = {chartXticks[izerox], 0};
            p2 = {chartXticks[izerox], chartFrame.rows};
            cv::line(chartFrame, p1, p2, this->specialColor, this->specialThickness);
        }

        itr = std::find(yticks->begin(), yticks->end(), 0);
        if(itr != yticks->end())
        {
            izeroy = itr - yticks->begin();
            p1 = {0, chartYticks[izeroy]};
            p2 = {chartFrame.cols, chartYticks[izeroy]};
            cv::line(chartFrame, p1, p2, this->specialColor, this->specialThickness);
        }

        for (auto xtick : chartXticks)
        {
            if(izerox != -1 && xtick != chartXticks[izerox])
            {
                p1 = {xtick, 0};
                p2 = {xtick, chartFrame.rows};
                cv::line(chartFrame, p1, p2, this->genColor, this->genThickness);
            }
        }
        for (auto ytick : chartYticks)
        {
            if(izeroy != -1 && ytick != chartYticks[izeroy])
            {
                p1 = {0, ytick};
                p2 = {chartFrame.cols, ytick};
                cv::line(chartFrame, p1, p2, this->genColor, this->genThickness);
            }
        }



    }
}