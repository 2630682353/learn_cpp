#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void sayname() = 0;
};

class Abfactory
{
public:
	virtual Fruit* create_product() = 0;
};

class Apple : public Fruit
{
public:
	virtual void sayname()
	{
		cout<<"i am apple\n";
	}
};

class Applefactory : public Abfactory
{
public:
	virtual Fruit* create_product()
	{
		return new Apple;
	}
};

class Banana : public Fruit
{
public:
	virtual void sayname()
	{
		cout<<"i am Banana\n";
	}
};

class Bananafactory : public Abfactory
{
public:
	virtual Fruit* create_product()
	{
		return new Banana;
	}
};

int main()
{
	Abfactory* factory = new Applefactory;
	Fruit *f = factory->create_product();
	f->sayname();
	delete f;
	delete factory;
	factory = new Bananafactory;
	f = factory->create_product();
	f->sayname();
	delete f;
	delete factory;
}