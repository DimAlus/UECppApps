#include "main.h"




int main() {
	CVector<int> v, v2(10, 23, 101);
	CVector<double> v4(1, 2, 4);
	v.SetX(3);
	v.SetY(4);
	v.SetZ(v2.GetY());
	
	std::cout << v.ToString() << "\n" << v2.ToString() << "\n" << v4.ToString() << "\n" << v4.Length();
	return 0;
}
