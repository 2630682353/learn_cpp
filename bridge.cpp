#include <iostream>
using namespace std;

class Engine
{
public:
	virtual void installEngine() = 0;
};

class Engine44 : public Engine
{
public:
	virtual void installEngine()
	{
		cout<<"Engine44\n";
	}
};

class Engine55 : public Engine
{
public:
	virtual void installEngine()
	{
		cout<<"Engine55\n";
	}
};

class Car
{
public:
	Car(Engine* engine)
	{
		this->m_engine = engine;
	}
	virtual void installEngine() = 0;
protected:
	Engine* m_engine;
};

class Bmw : public Car
{
public:
	Bmw(Engine* engine) : Car(engine)
	{
	}
	virtual void installEngine()
	{
		cout<<"i am Bmw\n";
		m_engine->installEngine();
	}
};

class Bmw6 : public Car
{
public:
	Bmw6(Engine* engine) : Car(engine)
	{
	}
	virtual void installEngine()
	{
		cout<<"i am Bmw6\n";
		m_engine->installEngine();
	}
};

int main()
{
	Engine* engine = NULL;
	Car* car = NULL;
	engine = new Engine44;
	car = new Bmw(engine);
	car->installEngine();
	delete car;
	delete engine;
}
