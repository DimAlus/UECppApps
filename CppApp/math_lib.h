#ifndef __MATH_LIB__
#define __MATH_LIB__

#include "library.h"

float SumSquare(float a, float b);
void PrintNumbers(int lim, bool isOdd);

template<typename T>
class CVector {
private:
	T vec[3];


public:

	T GetX() { return vec[0]; }
	T GetY() { return vec[1]; }
	T GetZ() { return vec[2]; }
	void SetX(T val) { vec[0] = val; }
	void SetY(T val) { vec[1] = val; }
	void SetZ(T val) { vec[2] = val; }

	CVector() {}
	CVector(T x, T y, T z) : vec{ x, y, z } {}
	double Length() {
		T sum = 0;
		for (int i = 0; i < 3; i++)
			sum += vec[i];
		return sqrt(sum);
	}

	std::string ToString() {
		std::string s = "(";
		for (int i = 0; i < 3; i++)
			s += std::to_string(vec[i]) + ";";
		s.back() = ')';
		
		return s;
	}
};

#endif // !__MATH_LIB__


