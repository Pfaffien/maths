#ifndef _FRACTION_H_
#define _FRACTION_H_

// TODO: amélioration des opérations (comparaisons et autres) après avoir créé
// une fonction qui convertit un flottant en fraction

#include <iostream>
#include <cmath>
#include <cassert>

#define assertm(exp, msg) assert((msg, exp))


using namespace std;


namespace frac {
    // Instantiations
    template <class T1, class T2> class Fraction;
    template <class T1, class T2> ostream &operator<<(ostream&, const Fraction<T1, T2>&);
    template <class T1, class T2> istream &operator>>(istream&, Fraction<T1, T2>&);


    // Declaration
    template <class T1, class T2>
    class Fraction
    {
        // Stream operators overloading
        friend ostream &operator<< <T1, T2>(ostream&, const Fraction<T1, T2>&);
        friend istream &operator>> <T1, T2>(istream&, Fraction<T1, T2>&);

    private:
        T1 numerator;
        T1 denominator;

    public:
        /*
         * Default constructor
         */
        Fraction();

        /*
         * Constructor with T input
         */
        Fraction(T1);

        /*
         * Constructor
         */
        Fraction(T1, T1);

        /*
         * Constructor from type T2 to fraction
         */
        Fraction(T2);

        /*
         * Numerator getter
         */
        T1 getNum() const;

        /*
         * Denominator getter
         */
        T1 getDenom() const;

        /*
         * Reduction to an irreductible fraction
         */
        void reduce();

        /*
         * Evaluate the decimal value of the fraction
         */
        T2 evaluate() const;

        /*
         * Equal operator
         */
        Fraction<T1, T2> &operator=(const Fraction<T1, T2>&);

        /*
         * Addition with a number of type T1
         */
        Fraction<T1, T2> operator+(T1);

        /*
         * Addition with a fraction
         */
        Fraction<T1, T2> operator+(const Fraction<T1, T2>&);

        /*
         * Increment postfix version
         */
        void operator++(int);

        /*
         * Addition shortcut with a number of type T1
         */
        void operator+=(T1);

        /*
         * Adition shortcut with a fraction
         */
        void operator+=(const Fraction<T1, T2>&);
        
        /*
         * Subtraction with a number of type T1
         */
        Fraction<T1, T2> operator-(T1);

        /*
         * Subtraction with a fraction
         */
        Fraction<T1, T2> operator-(const Fraction<T1, T2>&);

        /*
         * Decrement postfix version
         */
        void operator--(int);

        /*
         * Subtraction shortcut with a number of type T1
         */
        void operator-=(T1);

        /*
         * Subtraction shortcut with a fraction
         */
        void operator-=(const Fraction<T1, T2>&);

        /*
         * Product with a number of type T1
         */
        Fraction<T1, T2> operator*(T1);

        /*
         * Product with a fraction
         */
        Fraction<T1, T2> operator*(const Fraction<T1, T2>&);

        /*
         * Product shortcut with a number of type T1
         */
        void operator*=(T1);

        /*
         * Product shortcut with a fraction
         */
        void operator*=(const Fraction<T1, T2>&);

        /*
         * Division by a number of type T1
         */
        Fraction<T1, T2> operator/(T1);

        /*
         * Division by a fraction
         */
        Fraction<T1, T2> operator/(const Fraction<T1, T2>&);

        /*
         * Division shortcut with a number of type T1
         */
        void operator/=(T1);

        /*
         * Division shortcut with a fraction
         */
        void operator/=(const Fraction<T1, T2>&);

        /*
         * Equality check with a fraction
         */
        bool operator==(const Fraction<T1, T2>&);

        /*
         * Greater check
         */
        bool operator>(const Fraction<T1, T2>&);

        /*
         * Greater or equal check
         */
        bool operator>=(const Fraction<T1, T2>&);

        /*
         * Less check
         */
        bool operator<(const Fraction<T1, T2>&);

        /*
         * Less or equal check
         */
        bool operator<=(const Fraction<T1, T2>&);
    };



    // Implementation
    template <class T1, class T2>
    ostream &operator<<(ostream &o, const Fraction<T1, T2> &frac)
    {
        // More convenient display for integers
        if (frac.denominator == 1)
            o << frac.numerator;
        else
            o << frac.numerator << "/" << frac.denominator ;

        return o;
    }


    template <class T1, class T2>
    istream &operator>>(istream &i, Fraction<T1, T2> &frac)
    {
        T1 num, denom;

        cout << "Numerator: ";
        i >> num;
        cout << "Denominator: ";
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


    template <class T1, class T2>
    Fraction<T1, T2>::Fraction(T2 floating_number)
    {
        // TODO;
        Fraction();
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
    void Fraction<T1, T2>::operator++(int n)
    {
        numerator += denominator;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator+=(T1 number)
    {
        numerator += denominator * number;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator+=(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            numerator += frac.numerator;
        else {
            numerator = numerator * frac.denominator + denominator * frac.numerator;
            denominator *= frac.denominator;
        }
        
        this->reduce();
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
    void Fraction<T1, T2>::operator--(int n)
    {
        numerator -= denominator;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator-=(T1 number)
    {
        numerator -= denominator * number;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator-=(const Fraction<T1, T2> &frac)
    {
        if (denominator == frac.denominator)
            numerator -= frac.numerator;
        else {
            numerator = numerator * frac.denominator - denominator * frac.numerator;
            denominator *= frac.denominator;
        }

        this->reduce();
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
    void Fraction<T1, T2>::operator*=(T1 number)
    {
        numerator *= number;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator*=(const Fraction<T1, T2> &frac)
    {
        numerator *= frac.numerator;
        denominator *= frac.denominator;

        this->reduce();
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
    void Fraction<T1, T2>::operator/=(T1 number)
    {
        assertm(number != 0, "Error: division by zero");
        denominator *= number;
        this->reduce();
    }


    template <class T1, class T2>
    void Fraction<T1, T2>::operator/=(const Fraction<T1, T2> &frac)
    {
        assertm(frac.numerator != 0, "Error: division by zero");
        numerator *= frac.denominator;
        denominator *= frac.numerator;

        this->reduce();
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


    // Mathematical operations
    template <class T1, class T2>
    T1 ceil(const Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::ceil(value);
    }

    
    template <class T1, class T2>
    T1 floor(const Fraction<T1, T2> &frac)
    {
        T2 value = frac.evaluate();
        return std::floor(value);
    }


    template <class T1, class T2>
    T1 round(Fraction<T1, T2> frac)
    {
        T1 tmp = floor(frac);
        Fraction<T1, T2> diff = frac - tmp;
        T2 value = diff.evaluate();

        if (value < 0.5)
            return tmp;
        else
            return ceil(frac);
    }

}   /*end namespace frac*/


// Type shortcuts
typedef frac::Fraction<int, float> FractionIF;
typedef frac::Fraction<int, double> FractionID;
typedef frac::Fraction<long int, float> FractionLF;
typedef frac::Fraction<long int, double> FractionLD;


#endif  /*_FRACTION_H_*/
