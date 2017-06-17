#pragma once
#define gen_T template<typename T>//geneic class
gen_T class Vec3;
gen_T class Vec2;
#include <cmath>

#pragma region Determination of operators
gen_T Vec2<T> operator+(const Vec2<T> & v);
gen_T Vec2<T> operator-(const Vec2<T> & v);
gen_T const Vec2<T>& operator++(Vec2<T> & v);
gen_T const Vec2<T>& operator++(Vec2<T> & v, int);
gen_T const Vec2<T>& operator--(Vec2<T> & v);
gen_T const Vec2<T>&operator--(Vec2<T> & v, int);
gen_T Vec2<T> operator+=(Vec2<T> & left, const Vec2<T> & right);
gen_T Vec2<T> operator+(const Vec2<T> & left, const Vec2<T> & right);
gen_T Vec2<T> operator-=(Vec2<T> & left, const Vec2<T> & right);
gen_T Vec2<T> operator*=(Vec2<T> & left, const T & right);
gen_T Vec2<T> operator*=(const T & left, Vec2<T> & right);
gen_T Vec2<T> operator*(const Vec2<T> & left, const T & right);
gen_T Vec2<T> operator*(const T & left, const Vec2<T> & right);
gen_T Vec2<T> operator/=(Vec2<T> & left, const T & right);
gen_T Vec2<T> operator/(const Vec2<T> & left, const T & right);
gen_T double operator*(const Vec2<T> & left, const Vec2<T> & right);
gen_T Vec3<T> operator%(const Vec2<T> & left, const Vec2<T> & right);
#pragma endregion

gen_T class Vec2 //2 - Dementional vector
{

	Vec2();
public:
	T x; //x coordinate
	T y; //y coordinate

	Vec2(T x, T y);
	Vec2(const Vec2<T>& v);
	~Vec2();

	Vec2<T>& operator=(const Vec2<T>& right);

	/*********Unary operators********/
	//Unary +
	friend Vec2<T> operator+<>(const Vec2<T>& v);
	//Unary -
	friend Vec2<T> operator-<>(const Vec2<T>& v);
	//Prefix ++
	friend const Vec2<T>& operator++<>(Vec2<T>& v);
	//Postfix ++
	friend const Vec2<T>& operator++<>(Vec2<T>& v, int);
	//Prefix --
	friend const Vec2<T>& operator--<>(Vec2<T>& v);
	//Postfix --
	friend const Vec2<T>& operator--<>(Vec2<T>& v, int);

	/*********Binary operators********/
	//Binary
	friend Vec2<T> operator+=<>(Vec2<T>& left, const Vec2<T>& right);
	//Binary
	friend Vec2<T> operator+<>(const Vec2<T>& left, const Vec2<T>& right);
	//Binary -=
	friend Vec2<T> operator-=<>(Vec2<T>& left, const Vec2<T>& right);
	//Binary -
	friend Vec2<T> operator-<>(const Vec2<T>& left, const Vec2<T>& right);
	//Binary Vec2 *= scalar
	friend Vec2<T> operator*=<>(Vec2<T>& left, const T& right);
	//Binary scalar *= Vec2
	friend Vec2<T> operator*=<>(const T& left, Vec2<T>& right);
	//Binary Vec2 * scalar
	friend Vec2<T> operator*<>(const Vec2<T>& left, const T& right);
	//Binary scalar * Vec2
	friend Vec2<T> operator*<>(const T& left, const Vec2<T>& right);
	//Binary Vec2 /= scalar
	friend Vec2<T> operator/=<>(Vec2<T>& left, const T& right);
	//Binary Vec2 / scalar
	friend Vec2<T> operator/<>(const Vec2<T>& left, const T& right);

	//dot product
	friend double operator*<>(const Vec2<T>& left, const Vec2<T>& right);
	//cross product
	friend Vec3<T> operator%<>(const Vec2<T>& left, const Vec2<T>& right);
	/***********Methods*************/
	//returns vector lenght
	double GetMagnitude() const;
	//normalize vec2
	void Normalize();
	//returns normalized vec2
	static Vec2<double> GetNomalize(const Vec2<T>& v);
	//cosinus betwen 2 vectors
	static double GetCos(const Vec2<T>& left, const Vec2<T>& right);
	//sinus betwen 2 vectors
	static double GetSin(const Vec2<T>& left, const Vec2<T>& right);
	//projection P onto Q
	static Vec2<double> GetProgection(const Vec2<T>& P, const Vec2<T>& Q);
	//perpendicular component P onto Q
	static Vec2<double> GetPerpendicular(const Vec2<T>& P, const Vec2<T>& Q);
};

#pragma region Realization
template<typename T> inline Vec2<T>::Vec2()
{
}
template<typename T> inline Vec2<T>::Vec2(T x, T y)
{
	this->x = x;
	this->y = y;
}
template<typename T> inline Vec2<T>::Vec2(const Vec2<T> & v)
{
	this->x = v.x;
	this->y = v.y;
}
template<typename T> inline Vec2<T>::~Vec2()
{
}

gen_T inline Vec2<T> & Vec2<T>::operator=(const Vec2<T> & right)
{
	if (this == &right)
		return *this;
	x = right.x;
	y = right.y;
	return *this;
}
gen_T inline double Vec2<T>::GetMagnitude()const
{
	return sqrt(x*x + y*y);
}
gen_T inline void Vec2<T>::Normalize()
{
	double magnitude = this->GetMagnitude();
	x /= magnitude;
	y /= magnitude;
}
gen_T inline Vec2<double> Vec2<T>::GetNomalize(const Vec2<T>& v)
{
	T magnitude = v.GetMagnitude();
	return Vec2(v /= magnitude);
}
gen_T inline double Vec2<T>::GetCos(const Vec2<T>& left, const Vec2<T>& right)
{
	return left*right / (left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline double Vec2<T>::GetSin(const Vec2<T>& left, const Vec2<T>& right)
{
	return Vec2<double>::GetMagnitude(left%rignt)/(left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline Vec2<double> Vec2<T>::GetProgection(const Vec2<T>& P, const Vec2<T>& Q)
{
	return P*Q / (Q.GetMagnitude()*Q.GetMagnitude())*Q;
}
gen_T inline Vec2<double> Vec2<T>::GetPerpendicular(const Vec2<T>& P, const Vec2<T>& Q)
{
	return P - Vec2<T>::GetProgection(P, Q);
}

gen_T inline Vec2<T> operator+(const Vec2<T> & v)
{
	return v;
}
gen_T inline Vec2<T> operator-(const Vec2<T> & v)
{
	return Vec2<T>(-v.x, -v.y);
}
gen_T inline const Vec2<T>& operator++(Vec2<T> & v)
{
	v.x++;
	v.y++;
	return v;
}
gen_T inline const Vec2<T>& operator++(Vec2<T> & v, int)
{
	Vec2<T> oldValue(v);
	v.x++;
	v.y++;
	return oldValue;
}
gen_T inline const Vec2<T>& operator--(Vec2<T> & v)
{
	v.x--;
	v.y--;
	return v;
}
gen_T inline const Vec2<T>& operator--(Vec2<T> & v, int)
{
	Vec2<T> oldValue(v);
	v.x--;
	v.y--;
	return Vec2<T>(oldValue);
}
gen_T inline Vec2<T> operator+=(Vec2<T> & left, const Vec2<T> & right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}
gen_T inline Vec2<T> operator+(const Vec2<T> & left, const Vec2<T> & right)
{
	return Vec2<T>(
		left.x + right.x,
		left.y + right.y
		);
}
gen_T inline Vec2<T> operator-=(Vec2<T> & left, const Vec2<T> & right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}
gen_T inline Vec2<T> operator-(const Vec2<T> & left, const Vec2<T> & right)
{
	return Vec2<T>(
		left.x - right.x,
		left.y - right.y
		);
}
gen_T inline Vec2<T> operator*=(Vec2<T> & left, const T & right)
{
	left.x *= right;
	left.y *= right;
	return left;
}
gen_T inline Vec2<T> operator*=(const T & left, Vec2<T> & right)
{
	return right *= left;
}
gen_T inline Vec2<T> operator*(const Vec2<T> & left, const T & right)
{
	return Vec2<T>(left.x*right, left.y*right);
}
gen_T inline Vec2<T> operator*(const T & left, const Vec2<T> & right)
{
	return right*left;
}
gen_T inline Vec2<T> operator/=(Vec2<T> & left, const T & right)
{
	left.x /= right;
	left.y /= right;
	return left;
}
gen_T inline Vec2<T> operator/(const Vec2<T> & left, const T & right)
{
	return Vec2<T>(left.x / right, left.y / right);
}
gen_T inline double operator*(const Vec2<T> & left, const Vec2<T> & right)
{
	return left.x*right.x + left.y*right.y;
}
gen_T inline Vec3<T> operator%(const Vec2<T> & left, const Vec2<T> & right)
{
	return Vec3<T>(0, 0,
		left.x*right.y - left.y*right.x
	);
}
#pragma endregion