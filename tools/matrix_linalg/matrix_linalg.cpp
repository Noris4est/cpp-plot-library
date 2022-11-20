#include "matrix_linalg.hpp"

double norm_L1(const cv::Mat &src);
double norm_L2(const cv::Mat &src);
double norm_inf(const cv::Mat &src);
double norm_Frobenius(const cv::Mat &src);


double matAccess(const cv::Mat &src, int i, int j)
{
    switch (src.type())
        {
        case CV_32F:
            return src.at<float>(i,j);
            break;
        case CV_64F:
            return src.at<double>(i,j);
            break;
        case CV_32S:
            return src.at<int32_t>(i,j);
            break;
        default:
            throw("Error: not support outMatrixType!");
            break;
        }
}

double cv::linalg::norm(const cv::Mat &src, int normType)
{
    switch (normType)
    {
    case cv::linalg::NormTypes::NORM_L1:
        return norm_L1(src);
        break;
    case cv::linalg::NormTypes::NORM_L2:
        return norm_L2(src);
        break;
    case cv::linalg::NormTypes::NORM_INF:
        return norm_inf(src);
        break;
    case cv::linalg::NormTypes::NORM_FROBENIUS:
        return norm_Frobenius(src);
        break;
    default:
        throw std::runtime_error("Error: not support norm type");
        break;
    }
}

double cv::linalg::cond(const cv::Mat &src, int normType)
{
    switch (normType)
    {
     case cv::linalg::NormTypes::NORM_L1:
        return norm_L1(src) * norm_L1(src.inv());
        break;
    case cv::linalg::NormTypes::NORM_L2:
        return norm_L2(src) * norm_L2(src.inv());
        break;
    case cv::linalg::NormTypes::NORM_INF:
        return norm_inf(src) * norm_inf(src.inv());
        break;
    case cv::linalg::NormTypes::NORM_FROBENIUS:
        return norm_Frobenius(src) * norm_Frobenius(src.inv());
        break;
    default:
        throw std::runtime_error("Error: not support norm type");
        break;
    }
}

void cv::linalg::matRow2vector(const cv::Mat &src, std::vector<double> &dst, int i_row)
{
    assert(i_row >= 0 && i_row <src.rows);
    dst.clear();
    dst.reserve(src.cols);
    for(int j = 0; j < src.cols; ++j)
    {
        dst.push_back(matAccess(src, i_row, j));
    }
}

double norm_L1(const cv::Mat &src)
{
    
    double colsum;
    double maxsum;
    for(int j = 0; j < src.cols; ++j)
    {
        colsum = 0;
        for(int i = 0; i < src.rows; ++i)
        {
            colsum += std::abs(matAccess(src, i, j));
        }
        if(j == 0)
        {
            maxsum = colsum;
        }
        else
        {
            maxsum = colsum > maxsum ? colsum : maxsum;
        }
    }
    return maxsum;
}

double norm_inf(const cv::Mat &src)
{
    
    double rowsum;
    double maxsum;
    for(int i = 0; i < src.rows; ++i)
    {
        rowsum = 0;
        for(int j = 0; j < src.cols; ++j)
        {
            rowsum += std::abs(matAccess(src, i, j));
        }
        if(i == 0)
        {
            maxsum = rowsum;
        }
        else
        {
            maxsum = rowsum > maxsum ? rowsum : maxsum;
        }
    }
    return maxsum;
}

double norm_L2(const cv::Mat &src)
{
    cv::Mat product = src.t() * src;
    cv::Mat eigvals, eigvectors;
    cv::eigen(product, eigvals, eigvectors);
    double minVal, maxVal;
    cv::minMaxLoc(eigvals, &minVal, &maxVal);
    return std::sqrt(maxVal);
}

double norm_Frobenius(const cv::Mat &src)
{
    return std::sqrt(cv::trace(src.t() * src)[0]);
}
