#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int n) : _rawBits(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _rawBits(static_cast<int>(roundf(f * (1 << _fractionalBits)))) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed& rhs) const {
	return this->_rawBits > rhs._rawBits;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->_rawBits < rhs._rawBits;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->_rawBits >= rhs._rawBits;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->_rawBits <= rhs._rawBits;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->_rawBits == rhs._rawBits;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->_rawBits != rhs._rawBits;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->_rawBits + rhs._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->_rawBits - rhs._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	long long product = static_cast<long long>(this->_rawBits) * static_cast<long long>(rhs._rawBits);
	result.setRawBits(static_cast<int>(product >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	if (rhs._rawBits != 0) {
		long long dividend = static_cast<long long>(this->_rawBits) << _fractionalBits;
		result.setRawBits(static_cast<int>(dividend / rhs._rawBits));
	}
	return result;
}

Fixed& Fixed::operator++() {
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_rawBits++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs) {
	out << rhs.toFloat();
	return out;
}
