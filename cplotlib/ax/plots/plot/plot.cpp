#include "plot.hpp"

namespace plots
{
    Plot::Plot(
        const std::vector<double> &x,
        const std::vector <double> &y,
        plotsSettings::PlotSettings plotSettings,
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim)
        : AxObject(frame, axRect, offsetSettings, xlim, ylim),
        settings(plotSettings),
        x(x),
        y(y) 
    {}
    Plot::Plot(std::function<double(double)> func,
        plotsSettings::PlotSettings plotSettings,
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim)
        : AxObject(frame, axRect, offsetSettings, xlim, ylim),
        settings(plotSettings),
        plottingFunc(func)
    {
        usingFunc = true;
    }
    void Plot::draw()
    {
        if(usingFunc)
        {
            x.clear();
            y.clear();
            x =  cplt::arange(xlim->first, xlim->second + funcStep, funcStep);
            for (auto x_el : x)
            {
                y.push_back(plottingFunc(x_el));
            }
        }
        useVectorsDraw(); // построение графика Plot по точкам из векторов x, y;
    }
    void Plot::useVectorsDraw()
    {
        if(x.empty() || y.empty())
        {
            return; // ничего не рисует
        }
        if(x.size() != y.size())
        {
            throw std::runtime_error("Ax::plot - размер векторов x и y должен быть одинаков");
        }
    
        std::vector<cv::Point2d> inputPoints;
        inputPoints.reserve(x.size());
        auto xPtr = x.begin();
        auto yPtr = y.begin();
        for(int i = 0; i < x.size(); i++)
        {
            inputPoints.push_back(cv::Point2d(*xPtr++, *yPtr++));
        }

        double xMinIn = xlim->first;
        double xMaxIn = xlim->second;

        double yMinIn = ylim->first;
        double yMaxIn = ylim->second;
        cv::Rect chartRect = createChartRect();
        cv::Mat chartFrame = (*frame)(chartRect);
        /*
        Несмотря на то, что некоторые значения могут выходить за границы xlim и ylim для непрервыности графика вблизи границы отрисовываются все
        это корректно, потому что изменения chartFrame могут влиять на frame только внутри области chartRect
        */

        auto rect = cv::Rect(0, 0, chartFrame.cols, chartFrame.rows);
        auto xScalling = [xMinIn, xMaxIn, rect](double x)
        {
            return ax_components::scalling(xMinIn, xMaxIn, 0, rect.width - 1, x);
        };
        auto yScalling = [yMinIn, yMaxIn, rect](double y)
        {
            return ax_components::scalling(yMinIn, yMaxIn, rect.height - 1, 0, y);
        };
        auto pointScaling = [xScalling, yScalling](cv::Point2d &p)
        {
            double x_new = xScalling(p.x);
            double y_new = yScalling(p.y);
            return cv::Point2d(x_new, y_new);
        };
        for (auto &p : inputPoints)
        {
            p = pointScaling(p);
        }
        cv::Point2d p1, p2;
        for(int i = 0; i < inputPoints.size() - 1; i++)
        {
            p1 = inputPoints[i];
            p2 = inputPoints[i+1];
            cv::line(chartFrame, p1, p2, settings.lineColor, settings.lineWidth, cv::LINE_AA);
        }
    }

    void Plot::addPointToTail(double x, double y)
    {
        this->x.push_back(x);
        this->y.push_back(y);
        run_refresh_handlers();
    }
    void Plot::addPointToTail(cv::Point2d p)
    {
        addPointToTail(p.x, p.y);
    }
    void Plot::addPointToBegin(double x, double y)
    {
        this->x.insert(this->x.begin(), x);
        this->y.insert(this->y.begin(), y);
        run_refresh_handlers();
    }
    void Plot::addPointToBegin(cv::Point2d p)
    {
        addPointToBegin(p.x, p.y);
    }
    Plot* Plot::setLabel(const std::string label)
    {
        this->label = label;
        return this;
    }
    const std::string& Plot::getLabel()
    {
        return label;
    }
}