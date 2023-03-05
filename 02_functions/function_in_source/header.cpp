#include "header.h"

template<class T>
T Max(const T &a, const T &b)
{
    return a > b ? a : b ;
};

// explicit instantiations
template int Max<int>(const int &a, const int &b);
template char Max<char>(const char &a, const char &b);
template float Max<float>(const float &a, const float &b);
template double Max<double>(const double &a, const double &b);
