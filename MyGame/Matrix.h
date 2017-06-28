#pragma once
#include <stdexcept>
#include "MathExceptions.h"
#define matrix_T template<int n, int m, typename T>//geneic class
matrix_T class Matrix;
template<int n, typename T> class Vect;
#pragma region Determination of operators
matrix_T inline Matrix<m, n, T> operator~(const Matrix<n, m, T>& mx);
matrix_T inline Matrix<n, m, T> operator+(const Matrix<n, m, T> & mx);
matrix_T inline Matrix<n, m, T> operator-(const Matrix<n, m, T> & mx);
matrix_T inline const Matrix<n, m, T>& operator++(Matrix<n, m, T>& mx);
matrix_T inline Matrix<n, m, T> operator++(Matrix<n, m, T>& mx, int);
matrix_T inline const Matrix<n, m, T>& operator--(Matrix<n, m, T>& mx);
matrix_T inline Matrix<n, m, T> operator--(Matrix<n, m, T>& mx, int);
matrix_T inline Matrix<n, m, T> operator+=(Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator+(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator-=(Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator-(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator*=(Matrix<n, m, T>& L, const T & a);
matrix_T inline Matrix<n, m, T> operator*(const Matrix<n, m, T>& L, const T & a);
matrix_T inline Matrix<n, m, T> operator*=(const T & a, Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator*(const T & a, const Matrix<n, m, T>& R);
matrix_T inline Matrix<n, m, T> operator/=(Matrix<n, m, T>& L, const T & a);
matrix_T inline Matrix<n, m, T> operator/(const Matrix<n, m, T>& L, const T & a);
template<int n, int m, int p, typename T>
inline Matrix<n, p, T> operator*(const Matrix<n, m, T>& L, const Matrix<m, p, T>& R);
matrix_T inline Matrix<n, m, T> operator/<>(const Matrix<n, m, T>& L, const Matrix<m, m, T>& R);
#pragma endregion
matrix_T class Matrix
{
	int _n;
	int _m;
	T** ptr;
public:
	int N() const;
	int M() const;

	Matrix();
	Matrix(T** arr);
	Matrix(const Matrix<n, m, T>& m);
	~Matrix();

	Matrix<n,m,T>& operator=(const Matrix<n,m,T>& right);
	void SetPtr(T** arr);

	/*********Unary operators********/
	//Accessor [][]
	T* operator[](int i) const;
	//Transposed matrix
	friend Matrix<m, n, T> operator~<>(const Matrix<n, m, T>& mx);
	//Unary + (1*mx)
	friend Matrix<n, m, T> operator+<>(const Matrix<n, m, T>& mx);
	//Unary - (-1*mx)
	friend Matrix<n, m, T> operator-<>(const Matrix<n, m, T>& mx);
	//Prefix ++
	friend const Matrix<n, m, T>& operator++<>(Matrix<n, m, T>& mx);
	//Postfix ++
	friend Matrix<n, m, T> operator++<>(Matrix<n, m, T>& mx, int);
	//Prefix --
	friend const Matrix<n, m, T>& operator--<>(Matrix<n, m, T>& mx);
	//Postfix --
	friend Matrix<n, m, T> operator--<>(Matrix<n, m, T>& mx, int);
	/*********Binary operators********/
	//Binary +=
	friend Matrix<n, m, T> operator+=<>(Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
	//Binary +
	friend Matrix<n, m, T> operator+<>(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
	//Binary -=
	friend Matrix<n, m, T> operator-=<>(Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
	//Binary -
	friend Matrix<n, m, T> operator-<>(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R);
	//Binary M *= a
	friend Matrix<n, m, T> operator*=<>(Matrix<n, m, T>& L,const T& a);
	//Binary M * a
	friend Matrix<n, m, T> operator*<>(const Matrix<n, m, T>& L, const T& a);
	//Binary a *= M
	friend Matrix<n, m, T> operator*=<>(const T& a, Matrix<n, m, T>& R);
	//Binary a * M
	friend Matrix<n, m, T> operator*<>(const T& a, const Matrix<n, m, T>& R);
	//Binary M /= a
	friend Matrix<n, m, T> operator/=<>(Matrix<n, m, T>& L, const T& a);
	//Binary M / a
	friend Matrix<n, m, T> operator/<>(const Matrix<n, m, T>& L, const T& a);
	//Binari L_nm * R_mp
	template<int n, int m, int p, typename T>
	friend Matrix<n, p, T> operator*<>(const Matrix<n, m, T>& L,const Matrix<m, p, T>& R);
	template<int n, int m, int p, typename T>
	friend Matrix<n, p, T> operator*<>(const Matrix<n, m, T>& L, const Matrix<m, p, T>& R);
	//Binary L_nm / R_mm
	friend Matrix<n, m, T> operator/<>(const Matrix<n, m, T>& L, const Matrix<m, m, T>& R);
	/*********Methods********/
	//Transform NxN matrix and N-vector to redused form (Gauss)
	static Vect<n, T> Reduse(const Matrix<n, n, T>& M, const Vect<n, T>& V);
	//Get inerse matrix
	static Matrix<n, n, T> Inverse(const Matrix<n, n, T>& M);
	//Determinant
	T GetDeterminant();
	//-------An elementary row operations------//
	//Exchange two rows
	const Matrix<n, m, T>& SwapRows(const int i,const int j);
	//Multiply a row by a nonzero scalar
	const Matrix<n, m, T>& MulRow(const int i, const double a);
	//Add a multiple of one row to another row
	const Matrix<n, m, T>& AddMultToRow(const int i, const int j, const double a);
};
#pragma region Realiztion
matrix_T inline int Matrix<n, m, T>::N()const
{
	return _n;
}
matrix_T inline int Matrix<n, m, T>::M()const
{
	return _m;
}

template<int n, int m, typename T>
inline Matrix<n, m, T>::Matrix<n,m,T>()
{
	_n = n; _m = m;
	ptr = new T*[n];
	for (int i = 0; i < _n; i++) 
		ptr[i] = new T[_m];
}
template<int n, int m, typename T>
inline Matrix<n, m, T>::Matrix<n, m, T>(T** arr)
{
	_n = n; _m = m;
	ptr = new T*[n];
	for (int i = 0; i < _n; i++) {
		ptr[i] = new T[m];
		for (int j = 0; j < _m; j++) {
			ptr[i][j] = arr[i][j];
		}
	}
}
template<int n, int m, typename T>
inline Matrix<n,m,T>::Matrix(const Matrix<n, m, T>& matrix)
{
	_n = n; _m = m;
	ptr = new T*[n];
	for (int i = 0; i < _n; i++)
		ptr[i] = new T[_m];

	if (matrix.N() != n || matrix.M() != m)
		throw "the matrix is not comparable";
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _m; j++)
			ptr[i][j] = matrix[i][j];
	}
}
template<int n, int m, typename T>
inline Matrix<n,m,T>::~Matrix()
{
	if (this != nullptr)
	{
		for (int i = 0; i < _n; i++) {
			if (ptr[i] != nullptr)
			{
				delete[] ptr[i];
				ptr[i] = nullptr;
			}
		}
		delete[] ptr;
		ptr = nullptr;
	}
}

matrix_T inline Matrix<n, m, T>& Matrix<n,m,T>::operator=(const Matrix<n, m, T>& matrix)
{
	_n = n; _m = m;
	ptr = new T*[n];
	for (int i = 0; i < _n; i++)
		ptr[i] = new T[_m];

	if (matrix.N() != n || matrix.M() != m)
		throw "the matrix is not comparable";
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _m; j++)
			ptr[i][j] = matrix[i][j];
	}
}
matrix_T inline void Matrix<n,m,T>::SetPtr(T** arr)
{
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _m; j++)
			ptr[i][j] = arr[i][j];
	}
}
matrix_T inline T* Matrix<n,m,T>::operator[](int i) const
{
	return ptr[i];
}
matrix_T inline const Matrix<n, m, T>& Matrix<n, m, T>::SwapRows(const int p,const int q)
{
	T buf;
	for (int j = 0; j < m; j++) {
		buf = ptr[p][j]; 
		ptr[p][j] = ptr[q][j];
		ptr[q][j] = buf;
	}
	return *this;
}
matrix_T inline const Matrix<n, m, T>& Matrix<n, m, T>::MulRow(const int p, const double a)
{
	for (int i = 0; i < m; i++)
		ptr[p][i] *= a;
	return *this;
}
matrix_T inline const Matrix<n, m, T>& Matrix<n, m, T>::AddMultToRow(const int p, const int q, const double a)
{
	for(int j = 0; j < m; j++)
		ptr[p][j] += ptr[q][j] * a;
	return *this;
}

matrix_T inline Vect<n, T> Matrix<n, m, T>::Reduse(const Matrix<n, n, T>& M, const Vect<n, T>& V)
{
		int i, j, k;
		T d, s;
		Matrix<n, n + 1, T> matrix;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				matrix[i][j] = M[i][j];
			}
			matrix[i][n] = V[i];
		}
		//triangle
		T tmp;
		Vect<n, T> xx;
		for (i = 0; i<n; i++)
		{
			tmp = matrix[i][i];
			for (j = n; j >= i; j--)
				matrix[i][j] /= tmp;
			for (j = i + 1; j<n; j++)
			{
				tmp = matrix[j][i];
				for (k = n; k >= i; k--)
					matrix[j][k] -= tmp*matrix[i][k];
			}
		}
		//Reverse move
		xx[n - 1] = matrix[n - 1][n];
		for (i = n - 2; i >= 0; i--)
		{
			xx[i] = matrix[i][n];
			for (j = i + 1; j<n; j++) xx[i] -= matrix[i][j] * xx[j];
		}
		return xx;
}
matrix_T inline Matrix<n, n, T> Matrix<n, m, T>::Inverse(const Matrix<n, n, T>& M)
{
	Matrix<n, 2*n, T> A;//the temp matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = M[i][j];//the Left matrix
			A[i][j + n] = i==j ? 1 : 0;// the right E matrix;
		}//Fill the temp matrix

	T tmp;
	double det = 1;
	//Direct stroke
	for (int i = 0; i < n; i++)
	{
		tmp = 1 / A[i][i];
		for (int di = i + 1; di < n; di++)
			A.AddMultToRow(di,i, -A[di][i]*tmp);
		if (A[i][i] == 0) throw DeterminantIsZeroExcheption("Can't inverse matrix");
	}
	Matrix<n, n, T> iM;//Inversed matrix
	for (int i = 0; i<n; i++)
		for (int j = 0, di = n; j<n; j++, di++)
			iM[i][j] = A[i][di];	//Get inversed matrix from A

	//Reverse move
	for (int i = n - 1; i > 0; i--)
	{
		tmp = 1 / A[i][i];
		for (int di = i - 1; di >= 0; di--)
			iM.AddMultToRow(di, i, -A[di][i]*tmp);
		iM.MulRow(i, tmp);
	}
	iM.MulRow(0, 1/A[0][0]);

	return iM;
}
matrix_T inline T Matrix<n,m,T>::GetDeterminant()
{
	Matrix<n, n, T> A;
	A.SetPtr(ptr);
	T tmp;
	T det = 1;
	//Direct stroke
	for(int i = 0; i < n; i++)
	{
		tmp = 1 / A[i][i];
		for (int di = i + 1; di < n; di++)
			A.AddMultToRow(di, i, -A[di][i] * tmp);
		if (A[i][i] == 0) return 0;
		det *= A[i][i];
	}
	return det;
}

matrix_T inline Matrix<m, n, T> operator~(const Matrix<n, m, T>& mx)
{
	Matrix<m, n, T> tm;
	for (int i = 0; i < mx.N(); i++)
		for (int j = 0; j < mx.M(); j++)
			tm[j][i] = mx[i][j];
	return tm;
}
matrix_T inline Matrix<n, m, T> operator+(const Matrix<n, m, T> & mx)
{
	return mx;
}
matrix_T inline Matrix<n, m, T> operator-(const Matrix<n, m, T> & mx)
{
	Matrix<n, m, T> tm;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tm[i][j] = -mx[i][j];
	return Matrix<n,m,T>(tm);
}
matrix_T inline const Matrix<n, m, T>& operator++(Matrix<n, m, T>& mx)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx[i][j]++;
	return mx;
}
matrix_T inline Matrix<n, m, T> operator++(Matrix<n, m, T>& mx, int)
{
	Matrix<n, m, T> tm = mx;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx[i][j]++;
	return tm;
}
matrix_T inline const Matrix<n, m, T>& operator--(Matrix<n, m, T>& mx)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx[i][j]--;
	return mx;
}
matrix_T inline Matrix<n, m, T> operator--(Matrix<n, m, T>& mx, int)
{
	Matrix<n, m, T> tm = mx;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx[i][j]--;
	return tm;
}
matrix_T inline Matrix<n, m, T> operator+=(Matrix<n, m, T>& L, const Matrix<n, m, T>& R)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			L[i][j] += R;
	return L;
}
matrix_T inline Matrix<n, m, T> operator+(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R)
{
	Matrix<n, m, T> mt = L;
	return 	mt += R;
}
matrix_T inline Matrix<n, m, T> operator-=(Matrix<n, m, T>& L, const Matrix<n, m, T>& R)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			L[i][j] -= R;
	return L;
}
matrix_T inline Matrix<n, m, T> operator-(const Matrix<n, m, T>& L, const Matrix<n, m, T>& R)
{
	Matrix<n, m, T> mt = L;
	return 	mt -= R;
}
matrix_T inline Matrix<n, m, T> operator*=(Matrix<n, m, T>& L, const T & a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			L[i][j] *= a;
	return L;
}
matrix_T inline Matrix<n, m, T> operator*(const Matrix<n, m, T>& L, const T & a)
{
	Matrix<n, m, T> mt = L;
	return 	mt *= a;
}
matrix_T inline Matrix<n, m, T> operator*=(const T & a, Matrix<n, m, T>& R)
{
	return R*=a;
}
matrix_T inline Matrix<n, m, T> operator*(const T & a, const Matrix<n, m, T>& R)
{
	return R*a;
}
matrix_T inline Matrix<n, m, T> operator/=(Matrix<n, m, T>& L, const T & a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			L[i][j] /= a;
	return L;
}
matrix_T inline Matrix<n, m, T> operator/(const Matrix<n, m, T>& L, const T & a)
{
	Matrix<n, m, T> mt = L;
	return 	mt /= a;
}
template<int n, int m, int p, typename T> 
inline Matrix<n, p, T> operator*(const Matrix<n, m, T>& L,const Matrix<m, p, T>& R)
{
	Matrix<n, p, T> res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < m; k++)
				res[i][j] += L[i][k] * R[k][j];
		}
	return res;
}
template<int n, int m,typename T> inline Matrix<n, m, T> operator/<>(const Matrix<n, m, T>& L, const Matrix<m, m, T>& R)
{
	Matrix<m, m, T> tR = R;
	return L*tR.Inverse();
}
#pragma endregion