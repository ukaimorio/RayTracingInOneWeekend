#pragma once

class interval
{
public:
    double min, max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    bool contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }

    double clamp(double x) const
    {
        if (x < min)
            return min;
        if (x > max)
            return max;
        return x;
    }

    double size() const
    {
        return max - min;
    }
    interval expand(double detal) const
    {
        auto padding = detal / 2;
        return interval(min - padding, max + padding);
    }

    interval(const interval &a, const interval &b) : min(fmin(a.min, b.min)), max(fmax(a.max, b.max)) {}

    static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);

inline interval operator+(const interval &ival, double displacement)
{
    return interval(ival.min + displacement, ival.max + displacement);
}

inline interval operator+(double displacement, const interval &ival)
{
    return ival + displacement;
}
