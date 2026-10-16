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
        float   toFloat(void)const;
        int     toInt(void)const;
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        ~Fixed();

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);