#ifndef COMMONTYPES_H
#define COMMONTYPES_H

namespace cplt
{
    struct OffsetSettings
    {
        OffsetSettings()
        {
            top = 0.1;
            bottom = 0.15;
            right = 0.1;
            left = 0.2;
        }
        OffsetSettings(double top, double bottom, double right, double left)
        : top(top), bottom(bottom), right(right), left(left)
        {}
        double top;
        double bottom;
        double right;
        double left;
    };
    using lim_t = std::pair<double,double>;
    using ticks_t = std::vector<double>;
}

#endif //COMMONTYPES_H