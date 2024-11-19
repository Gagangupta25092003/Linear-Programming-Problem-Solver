#ifndef FRACTION_CLASS
#define FRACTION_CLASS

class Fraction{
    private:
        int numerator;
        int denominator;
        Fraction simplfy(int numerator, int denominator);
    
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction operator+(Fraction &other);
        Fraction operator-(Fraction &other);
        Fraction operator/(Fraction &other);
        Fraction operator*(Fraction &other);
        void print();
};
#endif