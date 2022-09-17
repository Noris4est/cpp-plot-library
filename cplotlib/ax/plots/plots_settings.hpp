#ifndef PLOTS_SETTINGS_H
#define PLOTS_SETTINGS_H

#include <opencv2/core.hpp>
#include "../../tools/colors/colors.hpp"

namespace plotsSettings
{
struct PlotSettings
{
    int lineWidth = 1;
    cv::Scalar lineColor = colors::red;
    // далее можно добавить linestyle или что-то такое
    
};// -- END plotSettings

struct BarSettings
{
    double binWidth = 0.8;
    cv::Scalar binColor = colors::blue;
    bool binsIsFilled = true;
}; // -- END barSettings

}

#endif /* PLOTS_SETTINGS_H: */