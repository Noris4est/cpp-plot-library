#ifndef STRING_PROCESSING_H
#define STRING_PROCESSING_H

#include <string>
#include <vector>
#include <opencv2/core/types.hpp>

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
int strip(std::string &str, char ch = ' ');
void deleteRepeatSeries(const std::string &src, std::string &dst, char ch);
void deleteRepeatSeries(std::string &s, char ch);


/*
    Функция парсит строку, заданную в формате a |b   | c|  d||| -> a,b,c,d ; a,b,c,d - целые числа
*/
void intParseUsingCharacter(const std::string &src, std::vector<int> &result, char ch = '|');


cv::Scalar parse_BGR_color(const std::string &src, char ch = '|'); // парсинг цвета с использованием разделителя

#endif //STRING_PROCESSING_H