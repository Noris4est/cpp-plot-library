#include "ax.hpp"


namespace cplt
{
    Ax::Ax(
        std::shared_ptr<cv::Mat> frame,
        cv::Rect axRect) 
        : frame(frame)
    {
        this->axRect = std::make_shared<cv::Rect>(axRect);

        xticks = std::make_shared<std::vector<double>>();
        yticks = std::make_shared<std::vector<double>>();

        xlim = std::make_shared<std::pair<double, double>>();
        ylim = std::make_shared<std::pair<double, double>>();

        offsetSettings = std::make_shared<OffsetSettings>();

        ticks = std::make_shared<ax_components::Ticks>(frame, this->axRect, offsetSettings, xlim, ylim, xticks, yticks);
        ticks->register_refresh_handler(this);

        grid = std::make_shared<ax_components::Grid>(frame, this->axRect, offsetSettings, xlim, ylim, xticks, yticks);
        grid->register_refresh_handler(this);

        xlabel = std::make_shared<ax_components::Xlabel>(frame, this->axRect, offsetSettings);
        xlabel->register_refresh_handler(this);

        ylabel = std::make_shared<ax_components::Ylabel>(frame, this->axRect, offsetSettings);
        ylabel->register_refresh_handler(this);

        title = std::make_shared<ax_components::Title>(frame, this->axRect, offsetSettings);
        title->register_refresh_handler(this);

        axBorder = std::make_shared<ax_components::AxBorder>(frame, this->axRect);
        axBorder->register_refresh_handler(this);

        axBackground = std::make_shared<ax_components::AxBackground>(frame, this->axRect, colors::white);
        axBackground->register_refresh_handler(this);


        chartBorder = std::make_shared<ax_components::ChartBorder>(frame, this->axRect, offsetSettings);
        chartBorder->register_refresh_handler(this);

        chartBackground = std::make_shared<ax_components::ChartBackground>(frame, this->axRect, offsetSettings, colors::lightskyblue);
        chartBackground->register_refresh_handler(this);
        
        register_refresh_handler(std::bind(&Ax::refresh, this));
        refresh();
    }
    
    void Ax::refresh()
    {
        axBackground->draw();
        chartBackground->draw();
        
        //здесь отрисовка pipeline plot-ов
        for(auto p : plotsPipeline)
        {
            p->draw();
        }

        chartBorder->draw();
        axBorder->draw();

        ticks->draw();
        grid->draw();
        xlabel->draw();
        ylabel->draw();
        title->draw();
    }

    void Ax::plot(
        const std::vector<double> &x, 
        const std::vector<double> &y,
        cv::Scalar lineColor,
        int lineWidth)
    {
        plotsSettings::PlotSettings settings;
        settings.lineColor = lineColor;
        settings.lineWidth = lineWidth;

        std::shared_ptr<plots::Plot> p = std::make_shared<plots::Plot>(x, y, settings, frame, axRect, offsetSettings, xlim, ylim);
        plotsPipeline.push_back(p);
        refresh();
    }


    void Ax::setXticks(const std::vector<double> &xticks)
    {
        *(this->xticks) = xticks;
        refresh();
    }
    void Ax::setYticks(const std::vector<double> &yticks)
    {
        *(this->yticks) = yticks;
        refresh();
    }

    void Ax::setXlim(double xmin, double xmax)
    {
        *xlim = {xmin, xmax};
        refresh();
    }
    void Ax::setYlim(double ymin, double ymax)
    {
        *ylim = {ymin, ymax};
        refresh();
    }
    void Ax::setXlabel(std::string text)
    {
        xlabel->setLabel(text);
        refresh();
    }
    void Ax::setYlabel(std::string text)
    {
        ylabel->setLabel(text);
        refresh();
    }
    void Ax::setTitle(const std::string &text)
    {
        title->setTitle(text);
        refresh();
    }
    void Ax::setOffsets(double top, double bottom, double right, double left)
    {
        offsetSettings->top = top;
        offsetSettings->bottom = bottom;
        offsetSettings->right = right;
        offsetSettings->left = left;
        refresh();
    }
    std::shared_ptr<ax_components::Grid> Ax::getGrid()
    {
        return grid;
    }
    std::shared_ptr<ax_components::Ticks> Ax::getTicks()
    {
        return ticks;
    }
    std::shared_ptr<ax_components::Xlabel> Ax::getXlabel()
    {
        return xlabel;
    }
    std::shared_ptr<ax_components::Ylabel> Ax::getYlabel()
    {
        return ylabel;
    }
    std::shared_ptr<ax_components::Title> Ax::getTitle()
    {
        return title;
    }
    std::shared_ptr<ax_components::AxBorder> Ax::getAxBorder()
    {
        return axBorder;
    }
    std::shared_ptr<ax_components::ChartBorder> Ax::getChartBorder()
    {
        return chartBorder;
    }
    std::shared_ptr<ax_components::AxBackground> Ax::getAxBackground()
    {
        return axBackground;
    }
    std::shared_ptr<ax_components::ChartBackground> Ax::getChartBackground()
    {
        return chartBackground;
    }

}