#pragma once

#include <iostream>
#include <string>

class bigint{
	private:
		std::string _number;
	public:
		bigint();
		bigint(int n);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		bigint operator+(const bigint& b) const;
		bigint& operator+=(const bigint& b);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(int n) const;
		bigint operator>>(int n) const;
		bigint& operator<<=(int n);
		bigint& operator>>=(int n);

		bigint& operator>>=(const bigint& b);
		bigint& operator<<=(const bigint& b);

		bool operator<(const bigint& b) const;
		bool operator<=(const bigint& b) const;
		bool operator>(const bigint& b) const;
		bool operator>=(const bigint& b) const;

		bool operator==(const bigint& b) const;
		bool operator!=(const bigint& b) const;

		const std::string& get_number() const;
};

std::ostream& operator<<(std::ostream &obj, const bigint& b);
