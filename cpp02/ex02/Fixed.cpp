#include "Fixed.hpp"

const int Fixed::_number_of_fractional_bits = 8;

Fixed::Fixed(): _fixed_point_number(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
    _fixed_point_number = number << _number_of_fractional_bits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) {
    _fixed_point_number = (int)roundf(number * (1 << _number_of_fractional_bits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return (_fixed_point_number);
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_number = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_fixed_point_number)/(1 << _number_of_fractional_bits));
}

int Fixed::toInt(void) const {
    return (_fixed_point_number >> _number_of_fractional_bits);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return ((a < b) ? a : b); 
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return ((a < b) ? a : b); 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return ((a > b) ? a : b); 
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->_fixed_point_number > other._fixed_point_number);
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->_fixed_point_number < other._fixed_point_number);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->_fixed_point_number >= other._fixed_point_number);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->_fixed_point_number <= other._fixed_point_number);
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->_fixed_point_number == other._fixed_point_number);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->_fixed_point_number != other._fixed_point_number);
}

Fixed Fixed::operator+(const Fixed& other) const {
    return(Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const {
    return(Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const {
    return(Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const {
    return(Fixed(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void) {
    ++_fixed_point_number;
    return (*this);
}

Fixed& Fixed::operator--(void) {
    --_fixed_point_number;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_fixed_point_number;
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_fixed_point_number;
    return (tmp);
}


std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();
    return (os);
}
