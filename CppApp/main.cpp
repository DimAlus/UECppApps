#include "main.h"
#include <memory>


class s_Player {
	int points;
	std::string name;
public:
	s_Player(int pts, std::string Name) : points(pts), name(Name) { }
	int GetPoints() { return points; }
	void SetPoints(int pts) { points = pts; }
	std::string GetName() { return name; }
	std::string ToString() {
		return name + ": <" + std::to_string(points) +">";
	}
};

#define DBG_

#include <ctime>
bool comp(void* a, void* b) {
	return ((s_Player*)a)->GetPoints() <= ((s_Player*)b)->GetPoints();
}
int main() {
	int N = 100000000;
	int seed = 0;
	unsigned int start_time;
	srand(seed);


	printf("%d\t%d\n\n", N, rand());

	// init players
	s_Player** players = new s_Player * [N];//malloc(sizeof(s_Player*) * N);

	for (int i = 0; i < N; i++) {
		players[i] = new s_Player(rand(), "Player " + std::to_string(i));
	}

#ifdef DBG
	for (int i = 0; i < N; i++)
		std::cout << players[i]->ToString() << "\n";
	std::cout << "\n\n\n\n\t\tSORTING\n\n";
#endif



	start_time = clock();
	SortMerge((void**)players, N, comp);//197972
	//QuicklyBubleSort((void**)players, N, comp);//221332
	//QuicklySort((void**)players, N, comp);
	//QuickCombSort((void**)players, N, comp);
	//SortBub((void**)players, N, comp);
	start_time = clock() - start_time;







	std::cout << start_time << "   " << clock() << "\n";

#ifdef DBG
	std::cout << "\n\n\n";
	for (int i = 0; i < N; i++)
		std::cout << players[i]->ToString() << "\n";
#endif



	std::cout << Check((void**)players, N, comp) << "\n\n";


	//destroy elements
	for (int i = 0; i < N; i++)
		delete players[i];
	delete[] players;
	
	return 0;
}
