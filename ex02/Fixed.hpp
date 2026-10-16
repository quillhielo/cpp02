#pragma once

#include <iostream>
#include <cmath>

class   Fixed{
    private:
        int _rawBits;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed&  operator=(const Fixed& other);
        Fixed(const int value);
        Fixed(const float value);
        
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;
        Fixed&  operator++(); // Prefix increment
        Fixed   operator++(int); // Postfix increment
        Fixed&  operator--(); // Prefix decrement
        Fixed   operator--(int); // Postfix decrement

        static Fixed&  min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);


        bool    operator>(const Fixed& other)const;
        bool    operator<(const Fixed& other)const;
        bool    operator>=(const Fixed& other)const;
        bool    operator<=(const Fixed& other)const;
        bool    operator==(const Fixed& other)const;
        bool    operator!=(const Fixed& other)const;

        float   toFloat(void)const;
        int     toInt(void)const;

        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        ~Fixed();

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);