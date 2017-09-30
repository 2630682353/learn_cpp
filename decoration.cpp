#include <iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class Runcar : public Car
{
public:
	virtual void show()
	{
		cout<<"i can run\n";
	}
};

class Swimcar : public Car
{
public:
	Swimcar(Car* car)
	{
		m_car = car;
	}
	virtual void show()
	{
		m_car->show();
		cout<<"i can swim\n";
	}
private:
	Car* m_car;
};

class Flycar : public Car
{
public:
	Flycar(Car* car)
	{
		m_car = car;
	}
	virtual void show()
	{
		m_car->show();
		cout<<"i can fly\n";
	}
private:
	Car* m_car;
};

int main()
{
	Car* runcar = new Runcar;
	runcar->show();
	cout<<"--------\n";
	Swimcar* swimcar = new Swimcar(runcar);
	swimcar->show();
	cout<<"--------\n";
	Flycar* flycar = new Flycar(swimcar);
	flycar->show();
	delete flycar;
	delete swimcar;
	delete runcar;
}



