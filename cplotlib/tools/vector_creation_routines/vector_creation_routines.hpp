#ifndef VECTOR_CREATION_ROUTINES_HPP
#define VECTOR_CREATION_ROUTINES_HPP

#include <vector>
#include <cmath>
#include <stdexcept>

namespace cplt
{
    std::vector<double> linspace(double start, double end, int num);
    std::vector<double> arange(double start, double end, double step);
    std::vector<double> geomspace(double start, double end, int num);
}

#endif // VECTOR_CREATION_ROUTINES_HPP
