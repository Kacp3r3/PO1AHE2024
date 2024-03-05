#include "gtest/gtest.h"
#include "Obiektówka AHE 2024/Foo.h"


TEST(FooTests, setName) 
{
	Foo f;
	f.setName("Dummy");
	EXPECT_EQ(f.getName(), "Dummy");
}

TEST(FooTests, defaultConstructor)
{
	Foo f;
	EXPECT_EQ(f.getName(), "default");
}

TEST(FooTests, copyConstructor)
{
	Foo f;
	int* table = f.getDynamicTable();
	table[0] = 10;

	Foo f2(f);
	
	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		EXPECT_EQ(f.getDynamicTable()[i], f2.getDynamicTable()[i]);
	}

	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		f.getDynamicTable()[i] = 20;
	}

	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		EXPECT_NE(f.getDynamicTable()[i], f2.getDynamicTable()[i]);
	}

	EXPECT_EQ(f.getName(), f2.getName());

	f.setName("Another");

	EXPECT_NE(f.getName(), f2.getName());
}

TEST(FooTests, assignmentOperator)
{
	Foo f;
	int* table = f.getDynamicTable();
	table[0] = 10;

	Foo f2 = f;

	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		EXPECT_EQ(f.getDynamicTable()[i], f2.getDynamicTable()[i]);
	}

	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		f.getDynamicTable()[i] = 20;
	}

	for (int i = 0; i < Foo::ARRAY_SIZE; ++i)
	{
		EXPECT_NE(f.getDynamicTable()[i], f2.getDynamicTable()[i]);
	}

	EXPECT_EQ(f.getName(), f2.getName());

	f.setName("Another");

	EXPECT_NE(f.getName(), f2.getName());
}


TEST(FooTests, operatorplus)
{
	Foo f("Example");
	Foo f2("Name");
	
	Foo f3 = f + f2;

	EXPECT_EQ(f3.getName(), "ExampleName");

	Foo f4 = f2 + f;
	EXPECT_EQ(f4.getName(), "NameExample");
}