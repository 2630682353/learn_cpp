#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

template<typename T>
class IsDiv
{
public:
	IsDiv(const T &divisor)
	{
		this->divisor = divisor;
	}
	bool operator()(T &t)
	{
		return (t%divisor == 0);
	}
private:
	T divisor;

	/* data */
};

void showElement(int &n)
{
	cout<<n<<" ";
}

class Myshow
{
public:
	void operator()(int &n)
	{
		cout<<n<<" ";
	}
};

bool greater_three(int num)
{
	return num > 20;
}

class Student
{
public:
	Student(string name, int id)
	{
		m_name = name;
		m_id = id;
	}
	void prinT()
	{
		cout<<m_name<<":::"<<m_id;
	}
	string m_name;
	int m_id;
};

bool compares(const Student &s1, const Student &s2)
{
	return s1.m_id > s2.m_id;
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 33; i++) {
		v.push_back(i);
	}
	int a = 4;
	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), IsDiv<int>(a));
	while(it != v.end()) {
		cout<<*it<<" ";
		it = find_if(++it, v.end(), IsDiv<int>(a));
	}
	cout<<endl;
	for_each(v.begin(), v.end(), showElement);
	cout<<endl;
	for_each(v.begin(), v.end(), Myshow());
	cout<<endl;
	int amount = count_if(v.begin(), v.end(), greater_three);
	cout<<"大于20个数："<<amount<<endl;
	vector<Student> v1;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(Student(string("xxxx"),i));
	}
	sort(v1.begin(), v1.end(), compares);
	for (std::vector<Student>::iterator it=v1.begin(); it != v1.end(); it++)
		(*it).prinT();
	random_shuffle(v1.begin(), v1.end());
	for (std::vector<Student>::iterator it=v1.begin(); it != v1.end(); it++)
		(*it).prinT();

}