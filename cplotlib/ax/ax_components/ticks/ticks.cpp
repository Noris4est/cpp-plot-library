#include "ticks.hpp"

namespace ax_components
{
    Ticks::Ticks(
        std::shared_ptr<cv::Mat> frame,
        std::shared_ptr<cv::Rect> axRect,
        std::shared_ptr<cplt::OffsetSettings> offsetSettings,
        std::shared_ptr<cplt::lim_t> xlim,
        std::shared_ptr<cplt::lim_t> ylim,
        std::shared_ptr<cplt::ticks_t> xticks,
        std::shared_ptr<cplt::ticks_t> yticks)
        :
        AxObject(frame, axRect, offsetSettings, xlim, ylim, xticks, yticks)
    {
        visibility = true;
        fontScale = 0.4;
        fontColor = colors::black;
        numDigitsAfterDot = 1;
        int fontFace = cv::FONT_HERSHEY_DUPLEX;//шрифт-тип (cv::FONT_HERSHEY_DUPLEX)
        int lineType = cv::LINE_AA;//cv::LINE_AA
        int lineThickness = 1;//thisckness = 1
    }
    void Ticks::setXticks(const std::vector<double> &xticks)
    {
        *(this->xticks) = xticks;
        run_refresh_handlers();
    }
    void Ticks::setYticks(const std::vector<double> &yticks)
    {
        *(this->yticks) = yticks;
        run_refresh_handlers();
    }
    void Ticks::setVisibility(bool flag)
    {
        this->visibility = flag;
        run_refresh_handlers();
    }
    void Ticks::setFontScale(double fontScale)
    {
        this->fontScale = fontScale;
        run_refresh_handlers();
    }
    void Ticks::setFontColor(cv::Scalar fontColor)
    {
        this->fontColor = fontColor;
        run_refresh_handlers();
    }

    void Ticks::draw()
    {
        cv::Rect chartRect = createChartRect();
        delOutsiders(*xticks, *xlim); // удаление значений вне диапазонов xlim, ylim
        delOutsiders(*yticks, *ylim);

        std::vector<int> chartXticks, chartYticks;
        scalling(*xticks, chartXticks, xlim->first, xlim->second, 0, chartRect.width - 1);
        scalling(*yticks, chartYticks, ylim->first, ylim->second, chartRect.height - 1, 0);
        cv::Point p1, p2;
        int xTickHeight = 10;
        std::stringstream stream;
        std::string s;
        // непосредственно отрисовка штрихов и численных значений отсчетов 
        double tick;
        int chartTick;
        for (int i = 0; i < chartXticks.size(); i++)
        {
            tick = (*xticks)[i];// *((*xticks).begin() + i)
            chartTick = chartXticks[i];
            p1 = {chartRect.x + chartTick, chartRect.y + chartRect.height - xTickHeight/2};
            p2 = {chartRect.x + chartTick, chartRect.y + chartRect.height + xTickHeight/2};
            cv::line(*frame, p1, p2, fontColor);
            stream << std::fixed << std::setprecision(numDigitsAfterDot) << tick;//одна цифра после запятой
            s = stream.str();
            frameText::putText(
                *frame, 
                s,
                frameText::corner::topCenter,
                p2,
                0,
                fontFace,
                fontScale,
                fontColor,
                lineThickness,
                lineType);
            stream.str("");
        }

        int yTickWidth = 10;
        for (int i = 0; i < chartYticks.size(); i++)
        {
            tick = (*yticks)[i];// *((*xticks).begin() + i)
            chartTick = chartYticks[i];
            p1 = {chartRect.x - yTickWidth/2, chartRect.y + chartTick};
            p2 = {chartRect.x + yTickWidth/2, chartRect.y + chartTick};
            cv::line(*frame, p1, p2, fontColor);
            stream << std::fixed << std::setprecision(numDigitsAfterDot) << tick;
            s = stream.str();
            frameText::putText(
                *frame, 
                s,
                frameText::corner::centerRight,
                p1,
                0,
                fontFace,
                fontScale,
                fontColor,
                lineThickness,
                lineType);
            stream.str("");
        }
    }
}
