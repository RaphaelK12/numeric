/*****************************************************************************
 *
 * AM utilities
 *
 * released under MIT license
 *
 * 2008-2017 André Müller
 *
 *****************************************************************************/


#include  "../include/bounded.h"

#include <stdexcept>
#include <cstdint>
#include <iostream>


using namespace am;
using namespace am::num;


//-------------------------------------------------------------------
int main()
{
    using std::abs;
    constexpr auto eps = 0.01;

    auto a = clipped<int,interval<int>>{ 5, {-2,8}};
    auto b = clipped<int,interval<int>>{ 6, {-2,8}};
    auto c = clipped<int,interval<int>>{10, {-2,8}};
    auto d = clipped<int,interval<int>>{-5, {-2,8}};

    auto d0 = clipped<double,unit_interval<double>>{-0.12};
    auto d1 = clipped<double,unit_interval<double>>{0.02};
    auto d2 = clipped<double,unit_interval<double>>{0.25};
    auto d3 = clipped<double,unit_interval<double>>{0.50};
    auto d4 = clipped<double,unit_interval<double>>{0.75};
    auto d5 = clipped<double,unit_interval<double>>{0.98};
    auto d6 = clipped<double,unit_interval<double>>{1.23};

    if( //double values, compile-time bounds
        (abs(d0 - 0.00) < eps) &&
        (abs(d1 - 0.02) < eps) &&
        (abs(d2 - 0.25) < eps) &&
        (abs(d3 - 0.50) < eps) &&
        (abs(d4 - 0.75) < eps) &&
        (abs(d5 - 0.98) < eps) &&
        (abs(d6 - 1.00) < eps) &&

        (abs((d0 + d1) - 0.02) < eps) &&
        (abs((d1 + d2) - 0.27) < eps) &&
        (abs((d2 + d3) - 0.75) < eps) &&
        (abs((d3 + d4) - 1.25) < eps) &&
        (abs((d5 + d4) - 1.73) < eps) &&
        (abs((d4 - d5) + 0.23) < eps) &&

        (abs((d0 + d1 + d2) - 0.27) < eps) &&
        (abs((d3 + d4 + d5) - 2.23) < eps) &&

        //integral values, runtime bounds
        (a == 5) && (b == 6) && (c == 8) && (d == -2) &&
        ((a+b) == 11) &&
        ((a+c) == 13) &&
        ((a+d) == 3) &&
        ((a-b) == -1) &&
        ((a-c) == -3) &&
        ((a-d) == 7) &&
        ((b-a) == 1) &&
        ((b-c) == -2) &&
        ((b-d) == 8) &&
        ((c-a) == 3) &&
        ((c-b) == 2) &&
        ((c-d) == 10) &&
        ((d-a) == -7) &&
        ((d-b) == -8) &&
        ((d-c) == -10) &&
        (make_clipped(a+b, make_interval(-1,5)) == 5) &&
        (make_clipped(a+c, make_interval(-1,5)) == 5) &&
        (make_clipped(a+d, make_interval(-1,5)) == 3) &&
        (make_clipped(a-b, make_interval(-1,5)) == -1) &&
        (make_clipped(a-c, make_interval(-1,5)) == -1) &&
        (make_clipped(a-d, make_interval(-1,5)) == 5) &&
        (make_clipped(b-a, make_interval(-1,5)) == 1) &&
        (make_clipped(b-c, make_interval(-1,5)) == -1) &&
        (make_clipped(b-d, make_interval(-1,5)) == 5) &&
        (make_clipped(c-a, make_interval(-1,5)) == 3) &&
        (make_clipped(c-b, make_interval(-1,5)) == 2) &&
        (make_clipped(c-d, make_interval(-1,5)) == 5) &&
        (make_clipped(d-a, make_interval(-1,5)) == -1) &&
        (make_clipped(d-b, make_interval(-1,5)) == -1) &&
        (make_clipped(d-c, make_interval(-1,5)) == -1) &&
        true
    )
    {
        return 0;
    }
    return 1;
}

