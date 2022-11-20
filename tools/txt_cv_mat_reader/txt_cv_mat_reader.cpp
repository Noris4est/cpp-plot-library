#include "txt_cv_mat_reader.hpp"
#include <iostream>
#include "../string_processing/string_processing.hpp"
#include <vector>
#include <opencv2/core/mat.hpp>


void readCvMatFromTxt(const std::string &path2srcTxt, cv::Mat &dstMatrix, char sep, int outMatType)
{
    // открытие файла
    std::ifstream file;
    file.open(path2srcTxt);
    assert(file.is_open());

    // определение числа строк и столбцов
    std::vector<int> cols;
    std::string strtmp;
    std::vector<std::string> strs;
    while(std::getline(file, strtmp))
    {
        strip(strtmp, ' ');
        deleteRepeatSeries(strtmp, sep);
        split(strtmp, strs, sep);
        cols.push_back(strs.size());
    }
    if(cols.size() == 0)
        throw std::runtime_error("Error: empty file");
    int n_cols = *std::max_element(cols.begin(), cols.end());
    int n_rows = cols.size();

    dstMatrix = cv::Mat(cv::Size(n_cols, n_rows), outMatType);

    file.clear();
    file.seekg (0, std::ios::beg);

    int i = 0;
    int j = 0;
    while(std::getline(file, strtmp))
    {
        strip(strtmp, ' ');
        deleteRepeatSeries(strtmp, sep);
        split(strtmp, strs, sep);
        j = 0;
        for(auto s : strs)
        {
            std::replace(s.begin(), s.end(), ',', '.');
            switch (outMatType)
            {
            case CV_32F:
                dstMatrix.at<float>(i,j) = std::stof(s);
                break;
            case CV_64F:
                dstMatrix.at<double>(i,j) = std::stod(s);
                break;
            case CV_32S:
                dstMatrix.at<int32_t>(i,j) = std::stoi(s);
                break;
            default:
                throw("Error: not support outMatrixType!");
                break;
            }
            j++;
        }
        i++;
    }
}

