#ifndef GRID_H
#define GRID_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../../../tools/colors/colors.hpp"
#include "../axobject.hpp"
#include "../../../commontypes.h"
namespace ax_components
{
    class Grid : public AxObject
    {
    public:
        Grid(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim,
            std::shared_ptr<cplt::ticks_t> xticks,
            std::shared_ptr<cplt::ticks_t> yticks);

        void draw();
        void setThickness(int thickness);
        void setColor(cv::Scalar color);
        void setSpecialBaseXYthickness(int thickness); // особая толщина базовых осей x,y (проходящих через начало координат)
        void setSpecialBaseXYcolor(cv::Scalar color);
        void setVisibility(bool flag); //включить или выключить видимость
    private:
        int genThickness;
        cv::Scalar genColor;
        int specialThickness;
        cv::Scalar specialColor;
        bool visibility;
    };
}


#endif /* GRID_H */
