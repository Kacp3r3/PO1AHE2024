#include "Foo.h"

Foo::Foo(std::string new_name)
{
	name = new_name;
	std::cout << "Konstruktor Foo: " << name << "\n";
	dynamic_table = new int[ARRAY_SIZE];
}

Foo::Foo()
{
	name = "default";
	std::cout << "Konstruktor Foo: " << name << "\n";
	dynamic_table = new int[ARRAY_SIZE];
}

Foo::Foo(const Foo& rhs)
{
	name = rhs.name;
	dynamic_table = new int[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i)
		dynamic_table[i] = rhs.dynamic_table[i];
	std::cout << "Konstruktor Foo: " << name << "\n";
}

Foo& Foo::operator=(const Foo& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		dynamic_table = new int[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; ++i)
			dynamic_table[i] = rhs.dynamic_table[i];
	}

	return *this;
}

Foo::~Foo()
{
	std::cout << "Destruktor Foo: " << name << "\n";
	delete[] dynamic_table;
}

void Foo::sayHi()
{
	std::cout << "Im " << name << "\n";
}

void Foo::setName(const std::string& new_name)
{
	name = new_name;
}

std::string Foo::getName()
{
	return name;
}

int* Foo::getDynamicTable()
{
	return dynamic_table;
}

Foo Foo::operator+(const Foo& rhs)
{
	return Foo(this->name + rhs.name);
}

std::ostream& operator<<(std::ostream& out, const Foo& rhs)
{
	return out << "Name: " << rhs.name;
}
