#include "vector_creation_routines.hpp"

std::vector<double> cplt::linspace(double start, double end, int num)
{
    if(num <= 0)
        throw std::runtime_error("Error: argument \"num\" is not correct");
    std::vector<double> result;
    result.reserve(num);
    if(num == 1)
    {
        result.push_back(start);
        return result;
    }
    double step = (end - start) / (num - 1);
    double current_item = start;
    for(int i = 1; i < num; i++)
    {
        result.push_back(current_item);
        current_item += step;
    }
    return result;
}
std::vector<double> cplt::arange(double start, double end, double step)
{
    std::vector<double> result;
    if(step == 0)
        throw std::runtime_error("Error: step = 0. This value is not valid");
    int size = std::ceil(std::abs(end - start) / step);

    result.reserve(size);
    result.push_back(start);
    if(size  == 1)
    {
        return result;
    }
    for(int i = 1; i < size; i++)
    {
        result.push_back(step + result[i-1]);
    }
    return result; // some action for test "initial commit" 
}