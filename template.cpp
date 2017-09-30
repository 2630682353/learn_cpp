#include <iostream>
using namespace std;

class Makecar
{
public:
	virtual void makeHead() = 0;
	virtual void makebody() = 0;
	virtual void maketail() = 0;
	void make()
	{
		makeHead();
		makebody();
		maketail();
	}
};

class Jeep : public Makecar
{
public:
	virtual void makeHead()
	{
		cout<<"jeep Head\n";
	}
	virtual void makebody()
	{
		cout<<"jeep body\n";
	}
	virtual void maketail()
	{
		cout<<"jeep tail\n";
	}
};

class Bwm : public Makecar
{
public:
	virtual void makeHead()
	{
		cout<<"Bwm Head\n";
	}
	virtual void makebody()
	{
		cout<<"Bwm body\n";
	}
	virtual void maketail()
	{
		cout<<"Bwm tail\n";
	}
};

int main()
{
	Makecar* makecar = new Jeep;
	makecar->make();
	delete makecar;
	makecar = new Bwm;
	makecar->make();
	delete makecar;
}

