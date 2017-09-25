#include <iostream>
using namespace std;
class Cpu
{
public:
	virtual void work() = 0;
};

class Memory
{
public:
	virtual void work() = 0;
};

class Disk
{
public:
	virtual void work() = 0;
};

class Computer
{
private:
	Cpu* m_cpu;
	Memory* m_memory;
	Disk* m_disk;
public:
	Computer(Cpu *cpu, Memory* memory, Disk* disk) 
	{
		m_cpu = cpu;
		m_memory = memory;
		m_disk = disk;
	}
	void work() 
	{
		m_disk->work();
		m_cpu->work();
		m_memory->work();
	}
};

class Ccpu : public Cpu
{
public:
	virtual void work()
	{
		cout<<"cpu work\n";
	}
};

class Cmemory : public Memory
{
public:
	virtual void work()
	{
		cout<<"memory work\n";
	}
};

class Cdisk : public Disk
{
public:
	virtual void work()
	{
		cout<<"disk work\n";
	}
};

int main()
{
	Computer mycomputer = Computer(new Ccpu, new Cmemory, new Cdisk);
	mycomputer.work();
}
