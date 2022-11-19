#ifndef FIGURE_H
#define FIGURE_H

#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"

#include "../tools/colors/colors.hpp"
#include "../axesManager/axesManager.hpp"


#include "../commontypes.h"

#include "fig_background/fig_background.hpp"
#include "fig_title/fig_title.hpp"

namespace cplt
{
    class Figure
    {
    public:
        Figure(cv::Size figsize = cv::Size(800,600));
        std::shared_ptr<AxesManager> addSubplots(int nRows, int nCols);
        void show(const std::string &winName);
        void save(const std::string &path);
        std::shared_ptr<FigBackground> getBackground();
        std::shared_ptr<FigTitle> getTitle();
    private:
        cv::Rect getAxesRect();
        void refresh();
        std::shared_ptr<cv::Size> figsize;
        cplt::OffsetSettings offsetSettings;
        std::shared_ptr<FigBackground> figBackground;
        std::shared_ptr<FigTitle> figTitle;
        std::shared_ptr<AxesManager> axesManager = nullptr;
        std::shared_ptr<cv::Mat> frame;
        bool needRefresh = true;
    }; /// -- END Figure
}

#endif /* FIGURE_H: */
