#include <bits/stdc++.h>
#include "fraction.h"
using namespace std;

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0){
        throw invalid_argument("Denominator is Negative | Infinite Value Found");
    }
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction Fraction::simplfy(int numerator, int denominator){
    if(numerator == 0){
        return Fraction(0, 1);
    }
    int gcd = __gcd(numerator, denominator);
    gcd *= denominator < 0 ? -1: 1;
    return Fraction(numerator/gcd, denominator/gcd);
}

Fraction Fraction::operator+(Fraction &other ){
    int num = numerator*other.denominator + denominator*other.numerator;
    int den = denominator*other.denominator;
    return simplfy(num, den);
}
Fraction Fraction::operator-(Fraction &other ){
    int num = numerator*other.denominator - denominator*other.numerator;
    int den = denominator*other.denominator;
    return simplfy(num, den);
}
Fraction Fraction::operator*(Fraction &other ){
    int num = numerator*other.numerator;
    int den = denominator*other.denominator;
    return simplfy(num, den);
}
Fraction Fraction::operator/(Fraction &other ){
    int num = numerator*other.denominator;
    int den = denominator*other.numerator;
    return simplfy(num, den);
}
void Fraction::print(){
    cout << numerator << "/" << denominator << endl;
}