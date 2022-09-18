#ifndef AXESMANAGER_H
#define AXESMANAGER_H

#include <map>
#include "../ax/ax.hpp"

namespace cplt
{
    /*
    Для сортировке ключей в ассоциативном контейнере по ключу нестандартного типа (cv::Point), 
    нужно определить оператор сравнения - компаратор (cmpPoint)
    */
    struct cmpPoint {
        bool operator()(const cv::Point& a, const cv::Point& b) const 
        {
            return (a.x < b.x) || (a.x == b.x && a.y < b.y);
        }
    }; // -- END cmpPoint

    class AxesManager
    {
    public:
        AxesManager(
            int nRows, 
            int nCols, 
            cv::Rect axesRect,
            std::shared_ptr<cv::Mat> frame);
        std::shared_ptr<Ax> get(int row, int column);
        void set(const std::shared_ptr<Ax> &ax, int row, int column);
        void refreshAll();
        void refreshChanged();
    private:
        std::map<cv::Point, std::shared_ptr<Ax>, cmpPoint> axes;
        int nRows, nCols; // subplots grid
        cv::Rect axesRect;
        std::shared_ptr<cv::Mat> frame;
    }; // -- END AxesManager
};

#endif /* AXESMANAGER_H: */