#include "math_lib.h"


float SumSquare(float a, float b) {
	return (a += b) * a;
}

void PrintNumbers(int lim, bool isOdd) {
	for (int i = (isOdd ? 0 : 1); i < lim;i += 2)
		std::cout << i << std::endl;
}

