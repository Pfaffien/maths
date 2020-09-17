#ifndef _FRACTION_H_
#define _FRACTION_H_

/**
 * \file fraction.h
 * \author Thomas BAUER
 * \date September 14, 2020
 *
 * Template class implementing rational numbers in frational form
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

/**
 * \brief Shortcut for assertion with a message
 * \def assertm(exp, msg)
 * \param exp Expression to be checked for the assertion
 * \param msg Message to be printed if assertion error
 */
#define assertm(exp, msg) assert((msg, exp))


/**
 * \namespace frac
 * \brief Namespace grouping the class Fraction and mathematical functions on rationals
 */
namespace frac
{
    /******************
     * Instantiations *
     ******************/
    template <class T1, class T2> class Fraction;
    template <class T1, class T2> std::ostream &operator<<(std::ostream&, const Fraction<T1, T2>&);
    template <class T1, class T2> std::istream &operator>>(std::istream&, Fraction<T1, T2>&);



    /***************
     * Declaration *
     ***************/

    /**
     * \class Fraction
     * \brief Template class for rational numbers
     */
    template <class T1, class T2>
    class Fraction
    {
        // Stream operators overloading
        
        /**
         * \brief Overloading of << operator
         * \param[in] o Reference to a std::ostream object
         * \param[in] frac The fraction to be displayed
         * \return A reference to the modified stream 
         */
        friend std::ostream &operator<< <T1, T2>(std::ostream &o, const Fraction<T1, T2> &frac);
        
        /**
         * \brief Overloading of >> operator
         * \param[in] i Reference to a std::istream object
         * \param[in] frac Reference to the fraction in which to insert data
         * \return A reference to the modified stream
         */
        friend std::istream &operator>> <T1, T2>(std::istream &i, Fraction<T1, T2> &frac);

    private:
        T1 numerator;
        T1 denominator;

    public:
        /**
         * \brief Default constructor
         */
        Fraction();

        /**
         * \brief Constructor
         * \param[in] num Integer of type T1
         */
        Fraction(T1 num);

        /**
         * \brief Constructor
         * \param[in] num Numerator of integer type T1
         * \param[in] denom Denominator of integer type T1
         */
        Fraction(T1 num, T1 denom);

        /**
         * \brief Constructor from number of floating type T2
         * \param[in] floating_number The floating number to be converted
         */
        Fraction(T2 floating_number);

        /**
         * \brief Numerator getter
         * \return The numerator of integer type T1
         */
        T1 getNum() const;

        /**
         * \brief Denominator getter
         * \return The denominator of integer type T1
         */
        T1 getDenom() const;

        /**
         * \brief Reduction to an irreductible fraction
         */
        void reduce();

        /**
         * \brief Evaluation of the fraction's value
         * \return The floating value of type T2
         */
        T2 evaluate() const;

        /**
         * \brief Assignment operator
         * \param[in] frac The fraction to be assigned
         * \return The fraction assigned
         */
        Fraction<T1, T2> &operator=(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of + operator
         * \param[in] number An integer of type T1
         * \return The new fraction
        */
        Fraction<T1, T2> operator+(T1 number);

        /**
         * \brief Overloading of + operator
         * \param[in] frac The fraction to be added
         * \return The new fraction
         */
        Fraction<T1, T2> operator+(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of += operator
         * \param[in] number An integer of type T1
         * \return A reference to the modified fraction
         */
        Fraction<T1, T2> &operator+=(T1 number);

        /**
         * \brief Overloading of += operator
         * \param[in] frac The fraction to be added
         * \return A reference to the modified fraction
         */
        Fraction<T1, T2> &operator+=(const Fraction<T1, T2> &frac);
        
        /**
         * \brief Overloading of - operator
         * \param[in] number An integer of type T1
         * \return The new fraction
         */
        Fraction<T1, T2> operator-(T1 number);

        /**
         * \brief Overloading of - operator
         * \param[in] frac The fraction to subtract
         * \return The new fraction
         */
        Fraction<T1, T2> operator-(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of unary - operator
         * \return The opposite of the fraction
         */
        Fraction<T1, T2> operator-();

        /**
         * \brief Overloading of -= operator
         * \param[in] number An integer of type T1
         * \return A reference to the modified fraction
         */
        Fraction<T1, T2> &operator-=(T1 number);

        /**
         * \brief Overloading of -= operator
         * \param[in] frac The fraction to subtract
         * \return A reference to the modified fraction
         */
        Fraction<T1, T2> &operator-=(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of * operator
         * \param[in] number An integer of type T1
         * \return The fraction multiplied by T1
         */
        Fraction<T1, T2> operator*(T1);

        /**
         * \brief Overloading of * operator
         * \param[in] frac The fraction to multiply with
         * \return The fraction multiplied by frac
         */
        Fraction<T1, T2> operator*(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of *= operator
         * \param[in] number An integer of type T1
         * \return A reference to the new fraction
         */
        Fraction<T1, T2> &operator*=(T1 number);

        /**
         * \brief Overloading of *= operator
         * \param[in] frac The fraction to multiply with
         * \return A reference to the new fraction
         */
        Fraction<T1, T2> &operator*=(const Fraction<T1, T2> &frac);

        /**
         * Overloading of / operator
         * \param[in] number An integer of type T1
         * \return The fraction divided by number
         */
        Fraction<T1, T2> operator/(T1 number);

        /**
         * \brief Overloading of / operator
         * \param[in] frac The fraction to divide by
         * \return The fraction divided by frac
         */
        Fraction<T1, T2> operator/(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of /= operator
         * \param[in] number An integer of type T1
         * \return A reference to the new fraction
         */
        Fraction<T1, T2> &operator/=(T1 number);

        /**
         * \brief Overloading of /= operator
         * \param[in] frac The fraction to divide by
         * \return A reference to the new fraction
         */
        Fraction<T1, T2> &operator/=(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of == operator
         * \param[in] frac The fraction to be check
         * \return True if both fractions are equal, else False
         */
        bool operator==(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of > operator
         * \param[in] frac The fraction to be checked
         * \return True if fraction greater than frac, else False
         */
        bool operator>(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading or >= operator
         * \param[in] frac The fraction to be checked
         * \return True if fraction greater than or equa to frac, else False
         */
        bool operator>=(const Fraction<T1, T2> &frac);

        /**
         * Overloading of < operator
         * \param[in] frac The fraction to be checked
         * \return True if fraction less than frac, else False
         */
        bool operator<(const Fraction<T1, T2> &frac);

        /**
         * \brief Overloading of <= operator
         * \param[in] frac The fraction to be checked
         * \return True if fraction less than or equal to frac, else False
         */
        bool operator<=(const Fraction<T1, T2> &frac);
    };



    /******************
     * Implementation *
     ******************/
    template <class T1, class T2>
    std::ostream &operator<<(std::ostream &o, const Fraction<T1, T2> &frac)
    {
        // More convenient display for integers
        if (frac.denominator == 1)
            o << frac.numerator;
        else
            o << frac.numerator << "/" << frac.denominator ;

        return o;
    }


    template <class T1, class T2>
    std::istream &operator>>(std::istream &i, Fraction<T1, T2> &frac)
    {
        T1 num, denom;

        std::cout << "Numerator: ";
        i >> num;
        std::cout << "Denominator: ";
        i >> denom;

        frac = Fraction<T1, T2>(num, denom);

        return i;
    }


    template <class T1, class T2>
    Fraction<T1, T2>::Fraction()
    {
        numerator = 0;
        denominator = 1;
    }


    template <class T1, class T2>
    Fraction<T1, T2>::Fraction(T1 num)
    {
        numerator = num;
        denominator = 1;

        this->reduce();
    }

    
    template <class T1, class T2>
    Fraction<T1, T2>::Fraction(T1 num, T1 denom)
    {
        assertm(denom != 0, "Denominator should not be zero");

        // Normalization of the sign of the fraction
        if ((num >= 0 && denom <= 0) || (num <= 0 && denom <= 0))
        {
            numerator = -num;
            denominator = -denom;
        } else {
            numerator = num;
            denominator = denom;
        }

        this->reduce();
    }


    // TODO: add some assertion to check if out of bound
    // to avoid being stuck in an infinite loop
    // Or add a max_iter number or check if there is a change of sign
    // of the numerator or denominator
    template <class T1, class T2>
    Fraction<T1, T2>::Fraction(T2 floating_number)
    {
        // Continued fractions
        T2 alpha(floating_number), theta(0), tmp(0);
        std::vector<T1> p = {0, 1, 0};   // Sequence for the numerator
        std::vector<T1> q = {1, 0, 0};   // Sequence for the denominator
        bool complete = false;
        
        while (!complete)
        {
            // Computation of the continued fraction
            tmp = floor(alpha);
            theta = alpha - tmp;
            if (theta > 1e-9)   // Precision for theta to be zero
                alpha = 1 / theta;
            else
                complete = true;

            // Computation of the numerator and denominator
            p[2] = tmp * p[1] + p[0];
            q[2] = tmp * q[1] + q[0];

            // Shifting the terms of the sequence (recurring of order 2)
            p[0] = p[1];
            p[1] = p[2];
            q[0] = q[1];
            q[1] = q[2];
        }

        // Normalization of the sign of the fraction
        if ((p[2] >= 0 && q[2] <= 0) || (p[2] <= 0 && q[2] <= 0))
        {
            numerator = -p[2];
            denominator = -q[2];
        } else {
            numerator = p[2];
            denominator = q[2];
        }
    }


    template <class T1, class T2>
    T1 Fraction<T1, T2>::getNum() const
    {
        return numerator;
    }


    template <class T1, class T2>
    T1 Fraction<T1, T2>::getDenom() const
    {
        return denominator;
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::reduce()
    {
        // Using Euclide's algorithm
        T1 a(abs(numerator)), b(abs(denominator));

        if (a > 0 && b > 0) {
            while (a != b)
            {
                if (a > b)  a -= b;
                else        b -= a;
            }

            numerator /= a;
            denominator /= a;
        }
    }


    template <class T1, class T2>
    T2 Fraction<T1, T2>::evaluate() const
    {
        return (T2) numerator / denominator;
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator=(const Fraction<T1, T2> &frac)
    {
        if (this != &frac)
        {
            numerator = frac.numerator;
            denominator = frac.denominator;
        }

        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator+(T1 number)
    {
        return Fraction(numerator + number * denominator, denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator+(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            return Fraction(numerator + frac.numerator, denominator);
        else
            return Fraction(numerator * frac.denominator + denominator * frac.numerator, denominator * frac.denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator+=(T1 number)
    {
        numerator += denominator * number;
        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator+=(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            numerator += frac.numerator;
        else {
            numerator = numerator * frac.denominator + denominator * frac.numerator;
            denominator *= frac.denominator;
        }
        
        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator-(T1 number)
    {
        return Fraction(numerator - number * denominator, denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator-(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            return Fraction(numerator - frac.numerator, denominator);
        else
            return Fraction(numerator * frac.denominator - denominator * frac.numerator, denominator * frac.denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator-()
    {
        return Fraction(-numerator, denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator-=(T1 number)
    {
        numerator -= denominator * number;
        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator-=(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            numerator -= frac.numerator;
        else {
            numerator = numerator * frac.denominator - denominator * frac.numerator;
            denominator *= frac.denominator;
        }

        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator*(T1 number)
    {
        return Fraction(number * numerator, denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator*(const Fraction<T1, T2> &frac)
    {
        return Fraction(numerator * frac.numerator,
                        denominator * frac.denominator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator*=(T1 number)
    {
        numerator *= number;
        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator*=(const Fraction<T1, T2> &frac)
    {
        numerator *= frac.numerator;
        denominator *= frac.denominator;

        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator/(T1 number)
    {
        assertm(number != 0, "Error: division by zero");
        return Fraction(numerator, denominator * number);
    }


    template <class T1, class T2>
    Fraction<T1, T2> Fraction<T1, T2>::operator/(const Fraction<T1, T2> &frac)
    {
        assertm(frac.numerator != 0, "Error: division by zero");
        return Fraction(numerator * frac.denominator,
                        denominator * frac.numerator);
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator/=(T1 number)
    {
        assertm(number != 0, "Error: division by zero");
        denominator *= number;

        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    Fraction<T1, T2> &Fraction<T1, T2>::operator/=(const Fraction<T1, T2> &frac)
    {
        assertm(frac.numerator != 0, "Error: division by zero");
        numerator *= frac.denominator;
        denominator *= frac.numerator;

        this->reduce();

        return *this;
    }


    template <class T1, class T2>
    bool Fraction<T1, T2>::operator==(const Fraction<T1, T2> &frac)
    {
        return (numerator == frac.numerator) && (denominator == frac.denominator);
    }


    template <class T1, class T2>
    bool Fraction<T1, T2>::operator>(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            return numerator > frac.numerator;
        else {
            Fraction tmp1(numerator * frac.denominator,
                          denominator * frac.denominator);
            Fraction tmp2(frac.numerator * denominator,
                          frac.denominator * denominator);
            return tmp1.numerator > tmp2.denominator;
        }
    }


    template <class T1, class T2>
    bool Fraction<T1, T2>::operator>=(const Fraction<T1, T2> &frac)
    {
        return (*this > frac) || (*this == frac);
    }


    template <class T1, class T2>
    bool Fraction<T1, T2>::operator<(const Fraction<T1, T2> &frac)
    {
        return !(*this >= frac);
    }


    template <class T1, class T2>
    bool Fraction<T1, T2>::operator<=(const Fraction<T1, T2> &frac)
    {
        return !(*this > frac);
    }
}



/******************
 * Type shortcuts *
 ******************/
typedef frac::Fraction<int, float> FractionIF;          /*!< Fraction of int whose value is evaluated in float precision*/
typedef frac::Fraction<int, double> FractionID;         /*!< Fraction of int whose value is evaluated in double precision */
typedef frac::Fraction<long int, float> FractionLF;     /*!< Fraction of long int whose value is evaluated in float precision */
typedef frac::Fraction<long int, double> FractionLD;    /*!< Fraction of long int whose value is evaluated in double precision */


#endif  /*_FRACTION_H_*/
