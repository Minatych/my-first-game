#pragma once
#define gen_T template<typename T>//geneic T class
gen_T class Vec3;
gen_T class Vec2;
#include <cmath>

#pragma region Determination of operators
gen_T Vec3<T> operator+(const Vec3<T> & v);
gen_T Vec3<T> operator-(const Vec3<T> & v);
gen_T const Vec3<T> & operator++(Vec3<T> & v);
gen_T const Vec3<T> & operator++(Vec3<T> & v, int);
gen_T const Vec3<T> & operator--(Vec3<T> & v);
gen_T const Vec3<T> & operator--(Vec3<T> & v, int);
gen_T Vec3<T> operator+=(Vec3<T> & left, const Vec3<T> & right);
gen_T Vec3<T> operator+(const Vec3<T> & left, const Vec3<T> & right);
gen_T Vec3<T> operator-=(Vec3<T> & left, const Vec3<T> & right);
gen_T Vec3<T> operator*=(Vec3<T> & left, const T & right);
gen_T Vec3<T> operator*=(const T & left, Vec3<T> & right);
gen_T Vec3<T> operator*(const Vec3<T> & left, const T & right);
gen_T Vec3<T> operator*(const T & left, const Vec3<T> & right);
gen_T Vec3<T> operator/=(Vec3<T> & left, const T & right);
gen_T Vec3<T> operator/(const Vec3<T> & left, const T & right);
gen_T double operator*(const Vec3<T> & left, const Vec3<T> & right);
gen_T Vec3<T> operator%(const Vec3<T> & left, const Vec3<T> & right);
#pragma endregion

gen_T class Vec3 // 3-Dementional vector
	: public Vec2<T> 
{
	Vec3();
public:
	T z; // z coordinate
	Vec3(T x, T y, T z);//x, y, z - coordinates
	Vec3(const Vec3<T>& v);
	~Vec3();

	Vec3<T>& operator=(const Vec3<T>& right);

	/*********Unary operators********/
	//Unary +
	friend Vec3<T> operator+<>(const Vec3<T>& v);
	//Unary -		
	friend Vec3<T> operator-<>(const Vec3<T>& v);
	//Prefix ++		
	friend const Vec3<T>& operator++<>(Vec3<T>& v);
	//Postfix ++	
	friend const Vec3<T>& operator++<>(Vec3<T>& v, int);
	//Prefix --		
	friend const Vec3<T>& operator--<>(Vec3<T>& v);
	//Postfix --	
	friend const Vec3<T>& operator--<>(Vec3<T>& v, int);

	/*********Binary operators********/
	//Binary +=
	friend Vec3<T> operator+=<>(Vec3<T>& left, const Vec3<T>& right);
	//Binary +
	friend Vec3<T> operator+<>(const Vec3<T>& left, const Vec3<T>& right);
	//Binary -=
	friend Vec3<T> operator-=<>(Vec3<T>& left, const Vec3<T>& right);
	//Binary -
	friend Vec3<T> operator-<>(const Vec3<T>& left, const Vec3<T>& right);
	//Binary Vec3 *= scalar
	friend Vec3<T> operator*=<>(Vec3<T>& left, const T& right);
	//Binary scalar *= Vec3
	friend Vec3<T> operator*=<>(const T& left, Vec3<T>& right);
	//Binary Vec3 * scalar
	friend Vec3<T> operator*<>(const Vec3<T>& left, const T& right);
	//Binary scalar * Vec3
	friend Vec3<T> operator*<>(const T& left, const Vec3<T>& right);
	//Binary Vec3 /= scalar
	friend Vec3<T> operator/=<>(Vec3<T>& left, const T& right);
	//Binary Vec3 / scalar
	friend Vec3<T> operator/<>(const Vec3<T>& left, const T& right);

	//dot product
	friend double operator*<>(const Vec3<T>& left, const Vec3<T>& right);
	//cross product
	friend Vec3<T> operator%<>(const Vec3<T>& left, const Vec3<T>& right);

	/***********Methods*************/
	//returns vector lenght
	double GetMagnitude() const;
	//normalize vec3
	void Normalize();
	//returns normalized vec3
	static Vec3<double> GetNomalize(const Vec3<T>& v);
	//cosinus betwen 2 vectors
	static double GetCos(const Vec3<T>& left, const Vec3<T>& right);
	//sinus betwen 2 vectors
	static double GetSin(const Vec3<T>& left, const Vec3<T>& right);
	//projection P onto Q
	static Vec3<double> GetProgection(const Vec3<T>& P, const Vec3<T>& Q);
	//perpendicular component P onto Q
	static Vec3<double> GetPerpendicular(const Vec3<T>& P, const Vec3<T>& Q);
};

#pragma region Realization 
template<typename T> inline Vec3<T>::Vec3() :Vec3<T>(0, 0)
{
}
template<typename T> inline Vec3<T>::Vec3(T x, T y, T z) : Vec2<T>(x, y)
{
	this->z = z;
}
template<typename T> inline Vec3<T>::Vec3(const Vec3<T>& v) : Vec2<T>(v)
{
	this->z = v.z;
}
template<typename T> inline Vec3<T>::~Vec3()
{
}

gen_T inline  double Vec3<T>::GetMagnitude() const
{
	return sqrt(x*x + y*y + z*z);
}
gen_T inline void Vec3<T>::Normalize()
{
	double magnitude = this->GetMagnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}
gen_T inline Vec3<double> Vec3<T>::GetNomalize(const Vec3<T>& v)
{
	T magnitude = v.GetMagnitude();
	return Vec3(v /= magnitude);
}
gen_T inline double Vec3<T>::GetCos(const Vec3<T>& left, const Vec3<T>& right)
{
	return left*right / (left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline double Vec3<T>::GetSin(const Vec3<T>& left, const Vec3<T>& right)
{
	return Vec2<double>::GetMagnitude(left%rignt) / (left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline Vec3<double> Vec3<T>::GetProgection(const Vec3<T>& P, const Vec3<T>& Q)
{
	return Vec3(P*Q /(Q.GetMagnitude()*Q.GetMagnitude())*Q);
}
gen_T inline Vec3<double> Vec3<T>::GetPerpendicular(const Vec3<T>& P, const Vec3<T>& Q)
{
	return P - Vec3<T>::GetProgection(P, Q);
}

gen_T inline Vec3<T> & Vec3<T>::operator=(const Vec3<T> & right)
{
	if (this == &right)
		return *this;
	x = right.x;
	y = right.y;
	z = right.z;
	return *this;
}
gen_T inline Vec3<T> operator+(const Vec3<T> & v)
{
	return v;
}
gen_T inline Vec3<T> operator-(const Vec3<T> & v)
{
	return Vec2(-v.x, -v.y, -v.z);
}
gen_T inline const Vec3<T> & operator++(Vec3<T> & v)
{
	v.x++;
	v.y++;
	v.z++;
	return v;
}
gen_T inline const Vec3<T> & operator++(Vec3<T> & v, int)
{
	Vec3<T> oldValue(v);
	v.x++;
	v.y++;
	v.z++;
	return oldValue;
}
gen_T inline const Vec3<T> & operator--(Vec3<T> & v)
{
	v.x--;
	v.y--;
	v.z--;
	return v;
}
gen_T inline const Vec3<T> & operator--(Vec3<T> & v, int)
{
	Vec3<T> oldValue(v);
	v.x--;
	v.y--;
	v.z--;
	return Vec2(oldValue);
}
gen_T inline Vec3<T> operator+=(Vec3<T> & left, const Vec3<T> & right)
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	return left;
}
gen_T inline Vec3<T> operator+(const Vec3<T> & left, const Vec3<T> & right)
{
	return Vec3<T>(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z
		);
}
gen_T inline Vec3<T> operator-=(Vec3<T> & left, const Vec3<T> & right)
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	return left;
}
gen_T inline Vec3<T> operator-(const Vec3<T> & left, const Vec3<T> & right)
{
	return Vec3<T>(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z
		);
}
gen_T inline Vec3<T> operator*=(Vec3<T> & left, const T & right)
{
	left.x *= right;
	left.y *= right;
	left.z *= right;
	return left;
}
gen_T inline Vec3<T> operator*=(const T & left, Vec3<T> & right)
{
	return right *= left;
}
gen_T inline Vec3<T> operator*(const Vec3<T> & left, const T & right)
{
	return Vec3<T>(left.x*right, left.y*right, left.z*right);
}
gen_T inline Vec3<T> operator*(const T & left, const Vec3<T> & right)
{
	return right*left;
}
gen_T inline Vec3<T> operator/=(Vec3<T> & left, const T & right)
{
	left.x /= right;
	left.y /= right;
	left.y /= right;
	return left;
}
gen_T inline Vec3<T> operator/(const Vec3<T> & left, const T & right)
{
	return Vec3<T>(left.x / right, left.y / right, left.z / right);
}
gen_T inline double operator*(const Vec3<T> & left, const Vec3<T> & right)
{
	return left.x*right.x + left.y*right.y + left.z*right.z;
}
gen_T inline Vec3<T> operator%(const Vec3<T> & left, const Vec3<T> & right)
{
	return Vec3<T>(
		left.y*right.z - left.z*right.y, 
		left.x*right.z - left.z*right.x,
		left.x*right.y - left.y*right.x
	);
}
#pragma endregion