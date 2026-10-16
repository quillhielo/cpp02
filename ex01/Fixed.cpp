#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return (*this);
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}
float   Fixed::toFloat(void)const
{
    return((static_cast<float>(_rawBits))/ (1 << _fractionalBits));
}

int     Fixed::toInt(void)const
{
    return(static_cast<int>(toFloat()));
}

std::ostream&   operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return (out);
}

int Fixed::getRawBits(void) const
{
    return(_rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}