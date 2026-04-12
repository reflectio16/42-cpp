#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
    
    private:
        int _fixedPointValue;
        static const int _fracBits = 8;
        
    public:
    
        Fixed();
        Fixed(const int value);
        Fixed(const float num);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits ( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
 
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

bool operator<(const Fixed& a, const Fixed& b);
bool operator>(const Fixed& a, const Fixed& b);
bool operator<=(const Fixed& a, const Fixed& b);
bool operator>=(const Fixed& a, const Fixed& b);
bool operator==(const Fixed& a, const Fixed& b);
bool operator!=(const Fixed& a, const Fixed& b);

Fixed operator+(const Fixed&, const Fixed& b);
Fixed operator-(const Fixed&, const Fixed& b);
Fixed operator*(const Fixed&, const Fixed& b);
Fixed operator/(const Fixed&, const Fixed& b);

#endif