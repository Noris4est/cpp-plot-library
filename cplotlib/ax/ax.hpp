#ifndef AX_HPP
#define AX_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp> //на время тестов
#include <memory>
#include <tuple>
#include <vector>
#include <iostream>
#include "../commontypes.h"
#include "../tools/colors/colors.hpp"
#include "../tools/frametext/frametext.hpp"
#include "ax_components/ticks/ticks.hpp"
#include "ax_components/grid/grid.hpp"
#include "ax_components/label/xlabel/xlabel.hpp"
#include "ax_components/label/ylabel/ylabel.hpp"
#include "ax_components/title/title.hpp"
#include "ax_components/chart_background/chart_background.hpp"
#include "ax_components/chart_border/chart_border.hpp"

#include "ax_components/ax_background/ax_background.hpp"
#include "ax_components/ax_border/ax_border.hpp"


#include "plots/plots_settings.hpp"
#include "plots/plot/plot.hpp"
#include "ax_components/axobject.hpp"

#include "../refresh_handler/refresh_handler.hpp"
namespace cplt
{
    class Ax : public IRefreshHandler
    {
    public:
        Ax(std::shared_ptr<cv::Mat> frame,
        cv::Rect axRect);

        std::shared_ptr<plots::Plot> plot(
            const std::vector<double> &x, 
            const std::vector<double> &y,
            cv::Scalar lineColor = colors::red,
            int lineWidth = 1);

        void setXticks(const std::vector<double> &xticks);
        void setYticks(const std::vector<double> &yticks);

        void setXlim(double xmin, double xmax);
        void setYlim(double ymin, double ymax);
        
        void setXlabel(std::string text);
        void setYlabel(std::string text);

        void setTitle(const std::string &text);
        void setOffsets(double top, double bottom, double right, double left);
        
        std::shared_ptr<ax_components::Grid> getGrid();
        std::shared_ptr<ax_components::Ticks> getTicks();
        std::shared_ptr<ax_components::Xlabel> getXlabel();
        std::shared_ptr<ax_components::Ylabel> getYlabel();
        std::shared_ptr<ax_components::Title> getTitle();
        std::shared_ptr<ax_components::AxBorder> getAxBorder();
        std::shared_ptr<ax_components::ChartBorder> getChartBorder();
        std::shared_ptr<ax_components::AxBackground> getAxBackground();
        std::shared_ptr<ax_components::ChartBackground> getChartBackground();
        
        std::shared_ptr<plots::Plot> getPlot(int number);
        void refresh(); // Может вызываться как внутри Ax, так через методы axesManager
        bool getNeedRefresh();

    private:
        std::shared_ptr<cv::Mat> frame; //изображение конкретного ax-а
        std::shared_ptr<cv::Rect> axRect;
        std::shared_ptr<OffsetSettings> offsetSettings;
        
        std::shared_ptr<std::vector<double>> xticks, yticks;; //объект эксплуатируется одновременно grid и ticks (как минимум)->нужна синхронизация
        std::shared_ptr<std::pair<double, double>> xlim, ylim;

        std::shared_ptr<ax_components::Ticks> ticks; 
        std::shared_ptr<ax_components::Grid> grid;
        std::shared_ptr<ax_components::Xlabel> xlabel;
        std::shared_ptr<ax_components::Ylabel> ylabel;
        std::shared_ptr<ax_components::Title> title;
        std::shared_ptr<ax_components::AxBorder> axBorder;
        std::shared_ptr<ax_components::ChartBorder> chartBorder;
        std::shared_ptr<ax_components::AxBackground> axBackground;
        std::shared_ptr<ax_components::ChartBackground> chartBackground;

        
        std::vector<std::shared_ptr<ax_components::AxObject>> plotsPipeline;
        bool needRefresh; // флаг необходимости произвести перерисовку. Требуется не при всех изменениях.
        void needRefreshOn(); // установка флага необходимости перерисовки в true
    };
}
#endif /* AX_HPP: */