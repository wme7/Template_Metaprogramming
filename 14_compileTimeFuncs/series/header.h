#pragma once

namespace series {

    const long double PI = 3.14159265358979323f;

    // FACTORIAL

    template <int N> 
    struct factorial
    {
        static const long long value = N * factorial<N-1>::value;
    };
    template <> 
    struct factorial<1>
    {
        static const long long value = 1L;
    };

    // EXPONENTS

    template <class X, int N> 
    struct power
    {
        static const long double value;
    };
    template <class X, int N> 
    const long double power<X, N>::value = X::value * power<X, N-1>::value;

    template <class X> 
    struct power<X, 0>
    {
        static const long double value;
    };
    template <class X> 
    const long double power<X, 0>::value = 1.0f;

    // SIMPLIFY RADIAN TO INTERVAL [-2π, 2π]

    template <class X> 
    struct SimplifyRad
    {
        static const long double value;
    };

    template <class X> 
    const long double SimplifyRad<X>::value =

        X::value - (2 * PI * (double) (int) (X::value/(2*PI))); // float modulo?

    // COSINE

    template <class X, int N> 
    struct cos
    {
        static const long double value;
    };
    template <class X, int N> 
    const long double cos<X, N>::value = 

        (((N % 2 == 0 ? 1 : -1) * power<SimplifyRad<X>, 2*N>::value) / ((long double) factorial<2*N>::value)) + cos<X, N-1>::value;

    template <class X> 
    struct cos<X, 0>
    {
        static const long double value;
    };
    template <class X> 
    const long double cos<X, 0>::value = 1.0f;

    // SINE

    template <class X, int N> 
    struct sin
    {
        static const long double value;
    };
    template <class X, int N> 
    const long double sin<X, N>::value = 

        (((N % 2 == 0 ? -1 : 1) * power<SimplifyRad<X>, 2*N-1>::value) / 
        ((long double) factorial<2*N-1>::value)) + sin<X, N-1>::value;

    template <class X> 
    struct sin<X, 0>
    {
        static const long double value;
    };
    template <class X> 
    const long double sin<X, 0>::value = 0.0f;

    // TANGENT

    template <class X, int N> 
    struct tan
    {
        static const long double value;
    };
    template <class X, int N> 
    const long double tan<X, N>::value = sin<X, N>::value / cos<X, N>::value;

}
