#ifndef TXT_CV_MAT_READER_HPP
#define TXT_CV_MAT_READER_HPP

#include <opencv2/core.hpp>
#include <string>
#include <fstream>

void readCvMatFromTxt(const std::string &path2srcTxt, cv::Mat &dstMatrix, char sep = ' ', int outMatType = CV_64FC1);

#endif //TXT_CV_MAT_READER_HPP
