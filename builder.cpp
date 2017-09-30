#include <iostream>
#include <string>
using namespace std;

class House
{
private:
	string mfloor;
	string window;
public:
	void setFloor(const char* f)
	{
		mfloor = f;
	}
	void setWindow(const char* w)
	{
		window = w;
	}
	string getFloor()
	{
		cout<<mfloor<<endl;
		return mfloor;
	}
	string getWindow()
	{
		cout<<window<<endl;
		return window;
	}
};

class Builder
{
public:
	virtual void setFloor() = 0;
	virtual void setWindow() = 0;
	virtual House* getHouse() = 0;
};

class FlatBuilder : public Builder
{
private:
	House* house;
public:
	FlatBuilder()
	{
		house = new House;
	}
	virtual void setFloor()
	{
		house->setFloor("flat floor");
	}
	virtual void setWindow()
	{
		house->setWindow("flat window");
	}
	virtual House* getHouse()
	{
		return house;
	}
};
class VillaBuilder : public Builder
{
private:
	House* house;
public:
	VillaBuilder()
	{
		house = new House;
	}
	virtual void setFloor()
	{
		house->setFloor("villa floor");
	}
	virtual void setWindow()
	{
		house->setWindow("villa window");
	}
	virtual House* getHouse()
	{
		return house;
	}

};

class Director
{
public:
	void construct(Builder* builder)
	{
		builder->setFloor();
		builder->setWindow();
	}
};

int main()
{
	House* house = NULL;
	Builder* builder = NULL;
	Director* director = NULL;
	builder = new FlatBuilder;
	director = new Director;
	director->construct(builder);
	house = builder->getHouse();
	house->getWindow();
	house->getFloor();
	delete house;
	delete builder;

	builder = new VillaBuilder;
	director->construct(builder);
	house = builder->getHouse();
	house->getWindow();
	house->getFloor();
	delete house;
	delete builder;
	delete director;
}