#include "main.h"

class Animal {
protected:
	Animal() {}
public:
	virtual void Voice() {}
};

class Wolf :Animal {
public:
	void Voice() override {
		std::cout << "Woof!\n";
	}
};

class Fox :Wolf {
public:
	void Voice() override {
		std::cout << "What does the Fox say?\n";
	}
};
class Cat :Animal {
public:
	void Voice() override {
		std::cout << "Nuaa!\n";
	}
};
int main() {
	int N = 20;
	Animal** ans = new Animal * [N];
	for (int i = 0; i < N; i++) {
		float chance = (float)rand() / RAND_MAX;
		if (chance < 0.3)
			ans[i] = (Animal*)new Wolf;
		else if (chance < 0.7)
			ans[i] = (Animal*)new Fox;
		else
			ans[i] = (Animal*)new Cat;
	}
	for (int i = 0; i < N; i++)
		ans[i]->Voice();

	for (int i = 0; i < N; i++)
		delete ans[i];
	delete[] ans;
	return 0;
}
