#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2& other) : x(other.x), y(other.y) {}

vect2& vect2::operator=(const vect2& other)
{
	x = other.x;
	y = other.y;
	return (*this);
}

vect2::~vect2() {}

int& vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	return (y);
}

int vect2::operator[](int index) const
{
	if (index == 0)
		return (x);
	return (y);
}

vect2& vect2::operator++()
{
	x = x + 1;
	y = y + 1;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp;

	temp = *this;
	x = x + 1;
	y = y + 1;
	return (temp);
}

vect2& vect2::operator--()
{
	x = x - 1;
	y = y - 1;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp;

	temp = *this;
	this->operator--();
	return (temp);
}

vect2 vect2::operator+(const vect2& v) const
{
	vect2 sum;

	sum.x = x + v.x;
	sum.y = y + v.y;
	return (sum);
}

vect2 vect2::operator-(const vect2& v) const
{
	vect2 temp;

	temp.x = x - v.x;
	temp.y = y - v.y;
	return (temp);
}

vect2 vect2::operator*(int m) const
{
	vect2 temp;

	temp.x = x * m;
	temp.y = y * m;
	return (temp);
}

vect2& vect2::operator+=(const vect2& v)
{
	x = x + v.x;
	y = y + v.y;
	return (*this);
}

vect2& vect2::operator-=(const vect2& v)
{
	x = x - v.x;
	y = y - v.y;
	return (*this);
}

vect2& vect2::operator*=(int m)
{
	x = x * m;
	y = y * m;
	return (*this);
}

bool vect2::operator==(const vect2& b) const
{
	if (x == b.x && y == b.y)
		return (true);
	return (false);
}

bool vect2::operator!=(const vect2& b) const
{
	if (x == b.x && y == b.y)
		return (false);
	return (true);
}

vect2 vect2::operator-() const
{
	return (vect2(-x, -y));
}

std::ostream& operator<<(std::ostream &obj, const vect2& v)
{
	obj << "{" << v[0] << ", " << v[1] << "}";
	return (obj);
}

vect2 operator*(int m, const vect2& v)
{
	return (v * m);
}
