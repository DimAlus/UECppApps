#include "main.h"


#define N1 6
#define N2 10


void PrintArr(int* arr, int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			std::cout << *(arr++) << "\t";
		std::cout << "\n";
	}
}
#include <time.h>

int main() {

	struct tm buf;
	time_t t = time(NULL);
	localtime_s(&buf, &t);

	int arr[N1][N2];
	for (int i = 0; i < N1; i++)
		for (int j = 0, k = i; j < N2; j++, k++)
			arr[i][j] = k;
	
	PrintArr((int*)arr, N1, N2);

	int m = buf.tm_mday % N1;

	std::printf("\nSumm elements of %d row is %d\n\n", m, (int)(((float)N2 / 2 + m) * N2));

	return 0;
}