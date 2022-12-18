#include "main.h"


int main() {
	float max = 100;
	float a = std::rand() * max / RAND_MAX, b = (float)std::rand() * max / RAND_MAX;
	std::printf("(%f + %f) ** 2 = %f\n", a, b, SumSquare(a, b));
	return 0;
}