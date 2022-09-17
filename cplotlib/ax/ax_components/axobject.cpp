#include "axobject.hpp"

namespace ax_components
{
    AxObject::AxObject(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim,
        std::shared_ptr<cplt::ticks_t> xticks,
        std::shared_ptr<cplt::ticks_t> yticks
        )
        :
        frame(frame),
        axRect(axRect),
        offsetSettings(offsetSettings),
        xlim(xlim),
        ylim(ylim),
        xticks(xticks),
        yticks(yticks)
    {}

    AxObject::AxObject(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim
        )
        :
        frame(frame),
        axRect(axRect),
        offsetSettings(offsetSettings),
        xlim(xlim),
        ylim(ylim)
    {
        xticks = nullptr;
        yticks = nullptr;
    }

    AxObject::AxObject(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings
        )
        :
        frame(frame),
        axRect(axRect),
        offsetSettings(offsetSettings)
    {
        xlim = nullptr;
        ylim = nullptr;
        xticks = nullptr;
        yticks = nullptr;
    }
    AxObject::AxObject(
    std::shared_ptr<cv::Mat> frame,
    std::shared_ptr<cv::Rect> axRect
    )
    :
    frame(frame),
    axRect(axRect)
    {
        offsetSettings = nullptr;
        xlim = nullptr;
        ylim = nullptr;
        xticks = nullptr;
        yticks = nullptr;
    }
    void AxObject::draw()
    {
        throw "method \"draw\" is not overload!";
    }
    cv::Rect AxObject::createChartRect()
    {
        double xOffset, yOffset; // for chartRect
        cv::Rect chartRect;
        xOffset = offsetSettings->left * axRect->width;
        yOffset = offsetSettings->top * axRect->height;
        chartRect.x = round(axRect->x + xOffset);
        chartRect.y = round(axRect->y + yOffset);
        chartRect.width = round((1 - offsetSettings->left - offsetSettings->right) * axRect->width);
        chartRect.height = round((1 - offsetSettings->top - offsetSettings->bottom) * axRect->height);
        return chartRect;
    }
}