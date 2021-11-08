#include "MyList.h"


int main()
{
	MyList L1;
	//expect: " "
	std::cout << L1;

	for (int i = 0; i < 5; i++)
		L1.push_back(i);

	//expect: "0 1 2 3 4"
	std::cout << L1;

	for (int i = 0; i > -5; i--)
		L1.push_front(i);

	//expect: "-4 -3 -2 -1 0 0 1 2 3 4"
	std::cout << L1;

	MyList L2;
	for (int i = 0; i < 3; i++)
		L2.push_back(0);

	L1.push_front(L2);

	//expect: "0 0 0 -4 -3 -2 -1 0 0 1 2 3 4"
	std::cout << L1;
	
	for (size_t i = 0; i < L1.get_size(); i++)
		if (L1.at(i) == 0) {
			L1.remove(i);
			i--;
		}

	//expect: "-4 -3 -2 -1 1 2 3 4"
	std::cout << L1;

	L1.clear();

	//expect: " "
	std::cout << L1;

	for (int i = 0; i < 3; i++)
		L1.push_back(i);

	//expect: "0 1 2"
	std::cout << L1;

	L1.pop_back();

	//expect: "0 1"
	std::cout << L1;

	L1.pop_front();

	//expect: "1"
	std::cout << L1;

	L1.insert(-9, 0);

	//expect: "-9 1"
	std::cout << L1;

	L1.insert(-8, 1);

	//expect: "-9 -8 1"
	std::cout << L1;

	L1.set(2, -7);

	//expect: "-9 -8 -7"
	std::cout << L1;

	//expect: "0"
	std::cout << L1.isEmpty() << std::endl;

	L1.clear();

	//expect: "1"
	std::cout << L1.isEmpty() << std::endl;

	return 0;
}
