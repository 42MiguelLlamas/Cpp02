#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(Fixed const& a);
        Fixed(int const a);
        Fixed(float const a);
        ~Fixed();

        friend std::ostream& operator<<(std::ostream& os, Fixed const& obj);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;   
        bool operator>=(const Fixed& other) const;  
        bool operator<=(const Fixed& other) const;  
        bool operator==(const Fixed& other) const;  
        bool operator!=(const Fixed& other) const;  

        Fixed &operator=(Fixed const& other);
        Fixed operator+(Fixed const& other) const;
        Fixed operator-(Fixed const& other) const;
        Fixed operator*(Fixed const& other) const;
        Fixed operator/(Fixed const& other) const;

        Fixed& operator++();   
        Fixed operator++(int); 
        Fixed& operator--();    
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif