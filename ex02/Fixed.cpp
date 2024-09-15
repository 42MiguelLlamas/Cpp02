#include "Fixed.hpp"

Fixed::Fixed () : value(0)
{

};

Fixed::Fixed (Fixed const& a) 
{

    this->value = a.getRawBits();
};

Fixed::Fixed (int const a)
{

    this->value = a * 256;
}

Fixed::Fixed(float const a)
{

    this->value = roundf(a *  256);
}

Fixed& Fixed::operator=(Fixed const& other)
{
    if (this == &other)
        return *this;
    this->value = other.getRawBits();
    return *this;
};

int Fixed::getRawBits(void) const
{
    return this->value;
};

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
};

Fixed::~Fixed ()
{
};

std::ostream& operator<<(std::ostream& os, Fixed const& obj)
{
    os << static_cast<float>(obj.getRawBits()) / 256.00;
    return os;
}

int Fixed::toInt(void) const
{
    return (static_cast<int>(roundf(this->getRawBits() / 256)));
}

float Fixed::toFloat(void) const
{
    return (roundf(this->getRawBits() / 256.00));
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.value = this->value + other.value;
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.value = this->value - other.value;
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.value = (this->value * other.value) / 256;
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.value = (this->value / other.value) ;
    return result;
}

bool Fixed::operator>(const Fixed& other) const
{
    return value > other.value;
};

bool Fixed::operator<(const Fixed& other) const
{
    return value < other.value;
};

bool Fixed::operator>=(const Fixed& other) const
{
    return value >= other.value;
}; 

bool Fixed::operator<=(const Fixed& other) const
{
    return value <= other.value;
};

bool Fixed::operator==(const Fixed& other) const
{
    return value == other.value;
};

bool Fixed::operator!=(const Fixed& other) const
{
    return value != other.value;
};

Fixed& Fixed::operator++()
{
    ++value;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}
Fixed& Fixed::operator--()
{
    --value;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}