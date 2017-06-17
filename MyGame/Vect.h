#pragma once
#pragma once
#define gen_T template<int n, typename T>//geneic T class
gen_T class Vect;
#include <cmath>

#pragma region Determination of operators
gen_T inline Vect<n, T> operator+(const Vect<n, T> & v);
gen_T inline Vect<n, T> operator-(const Vect<n, T> & v);
gen_T inline const Vect<n, T> & operator++(Vect<n, T> & v);
gen_T inline const Vect<n, T> & operator++(Vect<n, T> & v, int);
gen_T inline const Vect<n, T> & operator--(Vect<n, T> & v);
gen_T inline const Vect<n, T> & operator--(Vect<n, T> & v, int);
gen_T inline Vect<n, T> operator+=(Vect<n, T> & left, const Vect<n, T> & right);
gen_T inline Vect<n, T> operator+(const Vect<n, T> & left, const Vect<n, T> & right);
gen_T inline Vect<n, T> operator-=(Vect<n, T> & left, const Vect<n, T> & right);
gen_T inline Vect<n, T> operator*=(Vect<n, T> & left, const T & right);
gen_T inline Vect<n, T> operator*=(const T & left, Vect<n, T> & right);
gen_T inline Vect<n, T> operator*(const Vect<n, T> & left, const T & right);
gen_T inline Vect<n, T> operator*(const T & left, const Vect<n, T> & right);
gen_T inline Vect<n, T> operator/=(Vect<n, T> & left, const T & right);
gen_T inline Vect<n, T> operator/(const Vect<n, T> & left, const T & right);
gen_T inline double operator*(const Vect<n, T> & left, const Vect<n, T> & right);
gen_T inline Vect<3, T> operator%(const Vect<3, T> & left, const Vect<3, T> & right);
gen_T inline Vect<3, T> operator%(const Vect<2, T> & left, const Vect<2, T> & right);
#pragma endregion

gen_T class Vect //N-Dementional vector
{
	int count;
	T* ptr;
public:
	Vect();
	Vect(T* p);//x, y, z - coordinates
	Vect(const Vect<n,T>& v);
	~Vect();

	Vect<n,T> operator=(const Vect<n,T>& right);

	T& operator[](const int& i);
	T operator[](const int& i)const;
	/*********Unary operators********/
	//Unary +
	friend Vect<n, T> operator+<>(const Vect<n, T>& v);
	//Unary -		
	friend Vect<n, T> operator-<>(const Vect<n, T>& v);
	//Prefix ++		
	friend const Vect<n, T>& operator++<>(Vect<n, T>& v);
	//Postfix ++	
	friend const Vect<n, T>& operator++<>(Vect<n, T>& v, int);
	//Prefix --		
	friend const Vect<n, T>& operator--<>(Vect<n, T>& v);
	//Postfix --	
	friend const Vect<n, T>& operator--<>(Vect<n, T>& v, int);

	/*********Binary operators********/
	//Binary +=
	friend Vect<n, T> operator+=<>(Vect<n, T>& left, const Vect<n, T>& right);
	//Binary +
	friend Vect<n, T> operator+<>(const Vect<n, T>& left, const Vect<n, T>& right);
	//Binary -=
	friend Vect<n, T> operator-=<>(Vect<n, T>& left, const Vect<n, T>& right);
	//Binary -
	friend Vect<n, T> operator-<>(const Vect<n, T>& left, const Vect<n, T>& right);
	//Binary Vec3 *= scalar
	friend Vect<n, T> operator*=<>(Vect<n, T>& left, const T& right);
	//Binary scalar *= Vec3
	friend Vect<n, T> operator*=<>(const T& left, Vect<n, T>& right);
	//Binary Vec3 * scalar
	friend Vect<n, T> operator*<>(const Vect<n, T>& left, const T& right);
	//Binary scalar * Vec3
	friend Vect<n, T> operator*<>(const T& left, const Vect<n, T>& right);
	//Binary Vec3 /= scalar
	friend Vect<n, T> operator/=<>(Vect<n, T>& left, const T& right);
	//Binary Vec3 / scalar
	friend Vect<n, T> operator/<>(const Vect<n, T>& left, const T& right);

	//dot product
	friend double operator*<>(const Vect<n, T>& left, const Vect<n, T>& right);
	//cross product
	template<int n, int m, typename T>
	friend Vect<n, T> operator%<>(const Vect<m, T>& left, const Vect<m, T>& right);

	/***********Methods*************/
	//returns vector lenght
	int GetCount()const;
	double GetMagnitude() const;
	//normalize vec3
	void Normalize();
	//returns normalized vec3
	static Vect<n,double> GetNomalize(const Vect<n, T>& v);
	//cosinus betwen 2 vectors
	static double GetCos(const Vect<n, T>& left, const Vect<n, T>& right);
	//sinus betwen 2 vectors
	static double GetSin(const Vect<n, T>& left, const Vect<n, T>& right);
	//projection P onto Q
	static Vect<n,double> GetProgection(const Vect<n, T>& P, const Vect<n, T>& Q);
	//perpendicular component P onto Q
	static Vect<n,double> GetPerpendicular(const Vect<n, T>& P, const Vect<n, T>& Q);
};

#pragma region Realization 
template<int n, typename T> inline Vect<n,T>::Vect()
{
	this->count = n;
	this->ptr = new T[n];
}
template<int n, typename T> inline Vect<n,T>::Vect(T* p)
{
	this->count = n;
	this->ptr = new T[n];
	for (int i = 0; i < n; i++)
		this->ptr[i] = p[i];
}
template<int n, typename T> inline Vect<n,T>::Vect(const Vect<n,T>& v)
{
	if (this != nullptr)
	{
		ptr = nullptr;
	}
	this->count = n;
	this->ptr = new T[n];
	for (int i = 0; i < n; i++)
		this->ptr[i] = v[i];
}
template<int n, typename T> inline Vect<n,T>::~Vect()
{
	delete[] this->ptr;
	this->ptr = nullptr;
}

gen_T inline T& Vect<n, T>::operator[](const int& i)
{
	if (this->ptr != nullptr)
		if (i <= n && i >= 0)
			return this->ptr[i];
		else
			throw "OutOfRangeException";
	throw "NullReferenceEcxeption";
}
gen_T inline T Vect<n, T>::operator[](const int & i) const
{
	if (this->ptr != nullptr)
		if (i <= n && i >= 0)
			return this->ptr[i];
		else
			throw "OutOfRangeException";
	throw "NullReferenceEcxeption";
}

gen_T inline int Vect<n,T>::GetCount() const
{
	return this->count;
}

gen_T inline  double Vect<n, T>::GetMagnitude() const
{
	double a = 0;
	for (int i = 0; i < n; i++)
		a += this->ptr[i] * this->ptr[i];
	return sqrt(a);
}
gen_T inline void Vect<n, T>::Normalize()
{
	double magnitude = this->GetMagnitude();
	for (int i = 0; i < n; i++)
		this->ptr[i] / magnitude;
}
gen_T inline Vect<n,double> Vect<n, T>::GetNomalize(const Vect<n, T>& v)
{
	T magnitude = v.GetMagnitude();
	return Vect(v /= magnitude);
}
gen_T inline double Vect<n, T>::GetCos(const Vect<n, T>& left, const Vect<n, T>& right)
{
	return left*right / (left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline double Vect<n, T>::GetSin(const Vect<n, T>& left, const Vect<n, T>& right)
{
	return Vec2<double>::GetMagnitude(left%rignt) / (left.GetMagnitude()*right.GetMagnitude());
}
gen_T inline Vect<n,double> Vect<n, T>::GetProgection(const Vect<n, T>& P, const Vect<n, T>& Q)
{
	return Vec3(P*Q / (Q.GetMagnitude()*Q.GetMagnitude())*Q);
}
gen_T inline Vect<n,double> Vect<n, T>::GetPerpendicular(const Vect<n, T>& P, const Vect<n, T>& Q)
{
	return P - Vect<n, T>::GetProgection(P, Q);
}

gen_T inline Vect<n, T> Vect<n,T>::operator=(const Vect<n,T> & right)
{
	if (this == &right)
		return *this;
	for (int i = 0; i < n; i++)
		this->ptr[i] = right[i];
	return *this;
}
gen_T inline Vect<n, T> operator+(const Vect<n, T> & v)
{
	return v;
}
gen_T inline Vect<n, T> operator-(const Vect<n, T> & v)
{
	Vect<n, T> tv = v;
	for (int i = 0; i < n; i++)
		tv[i] = -v[i];
	return tv;
}
gen_T inline const Vect<n, T> & operator++(Vect<n, T> & v)
{
	for (int i = 0; i < n; i++)
		v[i]++;
	return v;
}
gen_T inline const Vect<n, T> & operator++(Vect<n, T> & v, int)
{
	Vect<n, T> oldValue(v);
	for (int i = 0; i < n; i++)
		v[i]++;
	return oldValue;
}
gen_T inline const Vect<n, T> & operator--(Vect<n, T> & v)
{
	for (int i = 0; i < n; i++)
		v[i]--;
	return v;
}
gen_T inline const Vect<n, T> & operator--(Vect<n, T> & v, int)
{
	Vect<n, T> oldValue(v);
	for (int i = 0; i < n; i++)
		v[i]--;
	return Vec2(oldValue);
}
gen_T inline Vect<n, T> operator+=(Vect<n, T> & left, const Vect<n, T> & right)
{
	for (int i = 0; i < n; i++)
		left[i] += right[i];
	return left;
}
gen_T inline Vect<n, T> operator+(const Vect<n, T> & left, const Vect<n, T> & right)
{
	return Vect<n, T> tv(left) += right;
}
gen_T inline Vect<n, T> operator-=(Vect<n, T> & left, const Vect<n, T> & right)
{
	for (int i = 0; i < n; i++)
		left[i] -= right[i];
	return left;
}
gen_T inline Vect<n, T> operator-(const Vect<n, T> & left, const Vect<n, T> & right)
{
	return Vect<n, T> tv(left) -= right;
}
gen_T inline Vect<n, T> operator*=(Vect<n, T> & left, const T & right)
{
	for (int i = 0; i < n; i++)
		left[i] *= right;
	return left;
}
gen_T inline Vect<n, T> operator*=(const T & left, Vect<n, T> & right)
{
	return right *= left;
}
gen_T inline Vect<n, T> operator*(const Vect<n, T> & left, const T & right)
{
	return Vect<n, T> tv(left) *= right;
}
gen_T inline Vect<n, T> operator*(const T & left, const Vect<n, T> & right)
{
	return right*left;
}
gen_T inline Vect<n, T> operator/=(Vect<n, T> & left, const T & right)
{
	for (int i = 0; i < n; i++)
		left[i] /= right;
	return left;
}
gen_T inline Vect<n, T> operator/(const Vect<n, T> & left, const T & right)
{
	return Vect<n, T> tv(left) /= right;
}
gen_T inline double operator*(const Vect<n, T> & left, const Vect<n, T> & right)
{
	double ret = 0;
	for (int i = 0; i < n; i++)
		ret += left[i] * right[i];
	return ret;
}
gen_T inline Vect<3, T> operator%(const Vect<3, T> & left, const Vect<3, T> & right)
{
	Vect<3, T> v3;
	v[0] = left[1] * right[2] - left[2] * right[1];
	v[1] = left[0] * right[2] - left[2] * right[0];
	v[2] = left[0] * right[1] - left[1] * right[0]
		return v3;
}//Only 3-Demential vectors
gen_T inline Vect<3, T> operator%(const Vect<2, T> & left, const Vect<2, T> & right)
{
	Vect<3, T> v2;
	v[0] = 0; v[1] = 0;
	v[2] = left[1] * right[2] - left[2] * right[1];
	return v2;
}//Only 2-Demential vectors
#pragma endregion