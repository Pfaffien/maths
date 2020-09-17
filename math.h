#ifndef _MATH_H_
#define _MATH_H_

/**
 * \file math.h
 * \author Thomas BAUER
 * \date September 15, 2020
 *
 * Implementation of some mathematical functions on rationals
 */


#include <iostream>
#include <cmath>


/**
 * \namespace frac
 * \brief Namespace grouping the class Fraction and mathematical functions on rationals
 */
namespace frac
{
    /** 
     * \fn T1 ceil(const frac::Fraction<T1, T2> &frac);
     * \brief Ceil function extended to fractions
     * \param frac The fraction to find the ceil value of
     * \return The smallest integer greater than or equal to frac
     */
    template <class T1, class T2>
    T1 ceil(const frac::Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::ceil(value);
    }


    /** 
     * \fn T1 floor(const frac::Fraction<T1, T2> &frac);
     * \brief Floor function extended to fractions
     * \param frac The fraction to find the floor value of
     * \return The biggest integer less than or equal to frac
     */
    template <class T1, class T2>
    T1 floor(const frac::Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::floor(value);
    }


    /** 
     * \fn T1 round(frac::Fraction<T1, T2> frac);
     * \brief Round function extended to fractions
     * \param frac The fraction to round
     * \return The nearest integer to frac
     */
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
