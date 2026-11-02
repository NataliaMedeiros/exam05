#include "bigint.hpp"
#include <cstdlib>

bigint::bigint() : _number("0") {}

bigint::bigint(int n) {
	std::string temp;
	if(n == 0)
		_number = "0";
	while(n > 0){
		temp = (n % 10) + '0';
		_number = temp + _number;
		n = n /10;
	}
}

bigint::bigint(const bigint& other) : _number(other._number) {}

bigint& bigint::operator=(const bigint& other){
	if (this != &other)
		_number = other._number;
	return *this;
}

bigint::~bigint(){}

bigint bigint::operator+(const bigint& b) const{
	int carry = 0;
	int sum = 0;
	int len = _number.size() - 1;
	int len_b = b._number.size() - 1;
	std::string temp = "";
	bigint sumN;
	sumN._number = "";

	while(len >= 0 || len_b >= 0){
		sum = carry;
		if (len >= 0)
			sum += _number[len] - '0';
		if (len_b >= 0)
			sum += b._number[len_b] - '0';
		temp = ((sum % 10) + '0');
		sumN._number = temp + sumN._number;
		carry = sum / 10;
		len--;
		len_b--;
	}
	if (carry > 0)
	{
		temp = carry + '0';
		sumN._number = temp + sumN._number;
	}
	return sumN;
}

bigint& bigint::operator+=(const bigint& b){
	*this = *this + b;
	return (*this);
}

bigint& bigint::operator++(){
	bigint one(1);

	*this = *this + one;
	return (*this);
}

bigint bigint::operator++(int){
	bigint temp = *this;
	bigint one(1);

	*this = *this + one;
	return (temp);
}

bigint bigint::operator<<(int n) const{
	bigint temp = *this;
	bigint zero(0);
	if (temp == zero)
		return (temp);
	for(int i = 0; i < n; i++){
		temp._number += '0';
	}
	return (temp);
}

bigint bigint::operator>>(int n) const{
	bigint temp(0);
	if (n >= static_cast<int>(_number.size()))
		return (temp);
	int len = static_cast<int>(_number.size()) - n;
	temp._number = _number.substr(0, len);
	return (temp);
}

bigint& bigint::operator<<=(int n){
	*this = *this << n;
	return (*this);
}

bigint& bigint::operator>>=(int n){
	*this = *this >> n;
	return (*this);
}

bigint& bigint::operator>>=(const bigint& b){
	*this = *this >> std::atoi(b._number.c_str());
	return (*this);
}

bigint& bigint::operator<<=(const bigint& b){
	*this = *this << std::atoi(b._number.c_str());
	return (*this);
}

bool bigint::operator<(const bigint& b) const{
	int len = _number.size();
	int len_b = b._number.size();

	if (len != len_b)
		return len < len_b;
	for(int i = 0; i < len; i++){
		if (_number[i] > b._number[i])
			return false;
		if (_number[i] < b._number[i])
			return (true);
	}
	return (false);
}

bool bigint::operator<=(const bigint& b) const{
	return (*this == b || *this < b);
}

bool bigint::operator>(const bigint& b) const{
	return (!(*this <= b));
}

bool bigint::operator>=(const bigint& b) const{
	return (*this == b || *this > b);
}

bool bigint::operator==(const bigint& b) const{
	int len = _number.size();
	int len_b = b._number.size();

	if (len != len_b)
		return false;
	for(int i = 0; i < len; i++){
		if (_number[i] != b._number[i])
			return (false);
	}
	return (true);
}

bool bigint::operator!=(const bigint& b) const{
	return (!((*this == b)));
}

const std::string& bigint::get_number() const{
	return (_number);
}

std::ostream& operator<<(std::ostream &obj, const bigint& b){
	obj << b.get_number();
	return obj;
}
