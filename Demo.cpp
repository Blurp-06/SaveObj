#include <iostream>
#include "SaveObj.h"

typedef struct {
	int age;
	char* name;
	bool isMale;
}Person;

int main()
{
	Person p;
	p.name = (char *)"Johny Doe";
	p.age = 10;
	p.isMale = true;

	writeObject<Person>(p, "test");

	Person p2;
	p2 = readObject<Person>("test");

	std::cout << p2.name << std::endl;		// Johny Doe
	std::cout << p2.age << std::endl;		// 10
	std::cout << p2.isMale << std::endl;	// 1 (1 == true)

	std::cin.get();
	return 0;
}