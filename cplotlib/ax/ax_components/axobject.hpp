#ifndef AXOBJECT_H
#define AXOBJECT_H

#include <memory>
#include <opencv2/opencv.hpp>
#include "../../commontypes.h"

namespace ax_components
{
    class AxObject
    {
    public:
        AxObject(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim,
            std::shared_ptr<cplt::ticks_t> xticks,
            std::shared_ptr<cplt::ticks_t> yticks
            );
        AxObject(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings,
            std::shared_ptr<cplt::lim_t> xlim,
            std::shared_ptr<cplt::lim_t> ylim
            );
        AxObject(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect,
            std::shared_ptr<cplt::OffsetSettings> offsetSettings
            );
        AxObject(
            std::shared_ptr<cv::Mat> frame,
            std::shared_ptr<cv::Rect> axRect
            );
        virtual void draw();
    protected:
        cv::Rect createChartRect();
        std::shared_ptr<cv::Mat> frame;
        std::shared_ptr<cv::Rect> axRect;
        std::shared_ptr<cplt::OffsetSettings> offsetSettings;
        std::shared_ptr<cplt::lim_t> xlim, ylim;
        std::shared_ptr<cplt::ticks_t> xticks, yticks;
    };

    template <typename Ta, typename Tb>    
    void delOutsiders(std::vector<Ta> &v,const std::pair<Tb, Tb> &lim)
    {
        auto cond = [lim](double value){return value <= lim.first || value >= lim.second;};
        auto it = std::remove_if(v.begin(), v.end(), cond);
        v.erase(it, v.end());
    } // -- END delOutsiders

    template <typename Ta, typename Tb, typename Tc>
    Tc scalling(Ta inMin, Ta inMax, Tb outMin, Tb outMax, Tc value)
    {
        return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
    }
    template <typename Ta, typename Tb, typename Tc, typename Td>
    void scalling(const std::vector<Ta> &src, std::vector<Tb> &dst, Tc inMin, Tc inMax, Td outMin, Td outMax)
    {
        dst.clear();
        dst.reserve(src.size());
        for(auto it = src.begin(); it != src.end(); it++)
        {
            dst.push_back(scalling(inMin, inMax, outMin, outMax, *it));
        }
    }


}
#endif //AXOBJECT_H