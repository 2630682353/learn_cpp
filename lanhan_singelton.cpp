#include <iostream>
using namespace std;

class Singelton
{
private:
	Singelton()
	{
		cout << "Singelton 构造函数\n";
	}
	static Singelton* m_psl;
public:
	static Singelton *getInstance()
	{
		//if (m_psl == NULL) {
		//	cs.lock();
		//	if (m_psl == NULL)
		//		m_psl = new Singelton;
		//	cs.unlock;
		//}
		return m_psl;
	}
	static void freeInstance()
	{
		if (m_psl != NULL) {
			delete m_psl;
			m_psl = NULL;
		}
	}
};
//类静态变量在全局初始化
//Singelton* Singelton::m_psl = NULL; 
//饿汉
Singelton* Singelton::m_psl = new Singelton;
int main()
{
	Singelton* p1 = Singelton::getInstance();
	Singelton* p2 = Singelton::getInstance();
	if (p1 == p2)
		cout<<"相等\n";
	Singelton::freeInstance();
}