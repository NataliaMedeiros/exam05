#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <string>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		int& operator[](int index);
		int operator[](int index) const;

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		vect2 operator+(const vect2& v)const;
		vect2 operator-(const vect2& v)const;
		vect2 operator*(int m)const;

		vect2& operator+=(const vect2& v);
		vect2& operator-=(const vect2& v);
		vect2& operator*=(int m);

		bool operator==(const vect2& b)const;
		bool operator!=(const vect2& b)const;

		vect2 operator-() const;

};

std::ostream& operator<<(std::ostream &obj, const vect2& v);

vect2 operator*(int m, const vect2& v);

#endif
