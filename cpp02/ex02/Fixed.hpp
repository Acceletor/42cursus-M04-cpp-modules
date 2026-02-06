#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int _fixed_point_number;
        static const int _number_of_fractional_bits;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed& a, Fixed&b);
        static Fixed& max(Fixed& a, Fixed&b);
        static const Fixed& min(const Fixed& a, const Fixed&b);
        static const Fixed& max(const Fixed& a, const Fixed&b);

        //overload operator
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++(void); //++x
        Fixed& operator--(void); //--x
        Fixed operator++(int);  //x++
        Fixed operator--(int); //x--
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);


#endif