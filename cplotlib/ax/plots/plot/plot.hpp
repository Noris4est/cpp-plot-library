#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include "../plots_settings.hpp"
#include "../../ax_components/axobject.hpp"

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
        void draw() override;
    private:
        plotsSettings::PlotSettings settings;
        std::vector<double> x, y;
    };
}
#endif /* PLOT_H */