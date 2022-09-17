#ifndef COMMONTYPES_H
#define COMMONTYPES_H

namespace cplt
{
    struct OffsetSettings
    {
        double top = 0.1;
        double bottom = 0.15;
        double right = 0.1;
        double left = 0.2;
    };
    using lim_t = std::pair<double,double>;
    using ticks_t = std::vector<double>;
}

#endif //COMMONTYPES_H