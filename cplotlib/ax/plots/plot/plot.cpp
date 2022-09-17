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
        x(x),
        y(y) {}
    void Plot::draw()
    {
        if(x.empty() || y.empty())
        {
            return; // ничего не рисует
        }
        if(x.size() != y.size())
        {
            throw "Ax::plot - размер векторов x и y должен быть одинаков";
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
        std::cout << inputPoints.empty();
        for(int i = 0; i < inputPoints.size() - 1; i++)
        {
            p1 = inputPoints[i];
            p2 = inputPoints[i+1];
            cv::line(chartFrame, p1, p2, settings.lineColor, settings.lineWidth, cv::LINE_AA);
        }
        
    }
}