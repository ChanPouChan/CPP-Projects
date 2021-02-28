#include <iostream>
#include <cstring>
using namespace std;

class Machinery
{
	public:
		Machinery(int _weight, string _name): weight(_weight), name(_name) {cout<<"Constructing machine..."<<endl;}
		int get_weight();		
		string get_name();
		virtual void operate(int hours)=0;
		virtual ~Machinery();
	private:
		int weight;
		string name;
};

class Vehicle:public Machinery
{
	public:
		Vehicle(int _weight, string _name): Machinery(_weight, _name) {cout<<"Constructing vehicle..."<<endl;}
		~Vehicle();
		void operate(int hours);
	private:
};

class Computer:public Machinery
{
	public:
		Computer(int _weight, string _name): Machinery(_weight, _name) {cout<<"Constructing computer..."<<endl;}
		~Computer();
		void operate(int hours); 
	private:
};

class Person
{
	public:
		Person();
		~Person();
		void workOn(Machinery *m, int hours);
		void workOn(Vehicle *v, int hours);
	private:
		
};

class Technician:public Person
{
	public:
		Technician();
		~Technician();
		void workOn(Machinery *m, int hours);
		void workOn(Computer *c, int hours);
	private:
		
};

int main()
{
//	Machinery *pcomp = new Computer(20,"My Computer");
//	delete pcomp;
	
	Machinery *m = new Vehicle(1560,"Nissan Skyline GT-R");
	Vehicle *v = new Vehicle(1200,"Toyota Corolla");
	Computer *c = new Computer(20,"My Pc");
	Person *p = new Person();
	Technician *t = new Technician();
	
	p->workOn(m,2);
	p->workOn(v,4);
	t->workOn(m,1);
	t->workOn(c,3);  
	
	delete v;
	delete c;
	delete p;
	delete t;

	return 0;
}

int Machinery::get_weight()
{
	return weight;
}

string Machinery::get_name()
{
	return name;
}

Machinery::~Machinery()
{
	cout<<"Destroying machine..."<<endl;
}

Vehicle::~Vehicle()
{
	cout<<"Destroying vehicle..."<<endl;
}

void Vehicle::operate(int hours)
{
	cout<<"Vehicle is working for "<<hours<<" hours"<<endl; 
}

Computer::~Computer()
{
	cout<<"Destroying computer..."<<endl;
}

void Computer::operate(int hours)
{
	cout<<"Computer is working for "<<hours<<" hours"<<endl;
}

Person::Person() 
{
	cout<<"Cosntructing person..."<<endl;
}

Person::~Person() 
{
	cout<<"Destroying person..."<<endl;
}

void Person::workOn(Machinery *m,int hours)
{
	m->operate(hours); 
}

void Person::workOn(Vehicle *v,int hours)
{
	v->operate(hours); 
}  

Technician::Technician() 
{
	cout<<"Constructing technician..."<<endl;
}

Technician::~Technician() 
{
	cout<<"Destroying technician..."<<endl;
}

void Technician::workOn(Machinery *m,int hours)
{
	m->operate(hours); 
}

void Technician::workOn(Computer *c,int hours)
{
	c->operate(hours); 
} 
