#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include "../plots_settings.hpp"
#include "../../ax_components/axobject.hpp"
#include "../../../tools/vector_creation_routines/vector_creation_routines.hpp"

namespace plots 
{
    class Plot : public ax_components::AxObject
    {
    public:
        Plot(
            const std::vector<double> &x,
            const std::vector <double> &y,
            plotsSettings::PlotSettings plotSettings,
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim);
        Plot(std::function<double(double)> func,
            plotsSettings::PlotSettings plotSettings,
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim);
        void draw() override; //not for users

        //usingFunc == false
        void addPointToBegin(cv::Point2d p);
        void addPointToBegin(double x, double y);
        void addPointToTail(cv::Point2d p);
        void addPointToTail(double x, double y);
        int getTotalPoints(); // Возвращает общее число точек графика
        void insertPoint(int position, cv::Point2d point); //встав. точку в согласно position
    private:
        void useVectorsDraw(); // Построение графика на основании содержания векторов x, y;
        plotsSettings::PlotSettings settings;
        std::vector<double> x, y;

        bool usingFunc = false;
        std::function <double(double)> plottingFunc;
        double funcStep = 0.01;
    };
}
#endif /* PLOT_H */