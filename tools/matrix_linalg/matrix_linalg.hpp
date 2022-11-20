#ifndef MATRIX_LINALG_HPP
#define MATRIX_LINALG_HPP

#include <opencv2/opencv.hpp>

/*
Стандартный метод OpenCV cv::norm(...)
не позволяет корректно рассчитывать норму матрицы с 
позиции линейной алгебры, так как узкоспециализирован
для работы с изображениями.
Данное расширение добавляет функции 
линейной алгебры для работы с матрицами cv::Mat
*/
namespace cv::linalg
{
    enum NormTypes
    {
        NORM_L1,
        NORM_L2,
        NORM_INF,
        NORM_FROBENIUS
    };

    //норма матрицы
    double norm(const cv::Mat &src, int normType);

    //число обусловленности матрицы
    double cond(const cv::Mat &src, int normType);

    //Вспомогательные операции
    void matRow2vector(const cv::Mat &src, std::vector<double> &dst, int i_row);
}
#endif //MATRIX_LINALG_HPP
