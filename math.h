#ifndef _MATH_H_
#define _MATH_H_

#include <iostream>
#include <cmath>


// Mathematical operations on fractions
namespace frac {
    template <class T1, class T2>
    T1 ceil(const frac::Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::ceil(value);
    }

    
    template <class T1, class T2>
    T1 floor(const frac::Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::floor(value);
    }


    template <class T1, class T2>
    T1 round(frac::Fraction<T1, T2> frac)
    {
        T1 tmp = floor(frac);
        frac::Fraction<T1, T2> diff = frac - tmp;
        T2 value = diff.evaluate();

        if (value < 0.5)
            return tmp;
        else
            return ceil(frac);
    }
}


#endif  /*_MATH_H_*/
