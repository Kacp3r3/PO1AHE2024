#ifndef _FOO_H_
#define _FOO_H_

#include <iostream>

class Foo
{
public:

	/// <summary>
	/// Constructs new Foo object
	/// </summary>
	/// <param name="new_name"> name of a Foo object </param>
	Foo(std::string new_name);
	Foo();
	Foo(const Foo& rhs);
	Foo& operator=(const Foo& rhs);

	~Foo();

	void sayHi();

	void setName(const std::string& new_name);

	std::string getName();
	int* getDynamicTable();

	Foo operator + (const Foo& rhs);
	friend std::ostream& operator <<(std::ostream& out, const Foo& rhs);


public:
	static constexpr int ARRAY_SIZE = 20;

private:
	std::string name;
	int* dynamic_table;
};


#endif // _FOO_H_