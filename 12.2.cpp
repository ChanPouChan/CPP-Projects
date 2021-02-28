#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class person
{
	public:
		person(){}
		person(string name_, int income_);
	private:
		string name;
		int income;	
};

class barista:virtual public person
{
	public:
		barista(){}
		barista(string name_,int income_);
		void prepare();
	private:
		
};

class waiter:virtual public person
{
	public:
		waiter(){}
		waiter(string name_,int income_);
		void serve(int customers, barista &b);
		void print();
	private:
		int customers_served;	
};

class owner:public barista, public waiter
{
	public:
		owner(string name_,int income_);
	private:
		
};

int main()
{
	srand(time(NULL));
	int clients, waiter_to_serve, barista_to_serve;
	owner *o = new owner("Joe",500);
	waiter *w1 = new waiter("Jack" ,700);
	waiter *w2 = new waiter("Sussy" ,1000);
	barista *b = new barista("Bob",400);
	
	waiter *waiters[3]={o,w1,w2};
	barista *baristas[2]={o,b};
	
	for(int i=0; i<100; i++)
	{
		clients = 1+rand()%5;
		
		waiter_to_serve = rand()%3;
		barista_to_serve = rand()%2;
		
		waiters[waiter_to_serve]->serve(clients, *baristas[barista_to_serve]);
	}
	
	for(int i=0; i<3; i++)
	{
		waiters[i]->print();
		cout<<endl;
	}
	
	delete o;
	delete w1;
	delete w2;
	delete b;
	
	return 0;
}

person::person(string name_, int income_)
{
	name = name_;
	income = income_;
}

waiter::waiter(string name_,int income_):
	person(name_,income_)
{
	customers_served = 0;
}

void waiter::serve(int customers, barista &b)
{
	b.prepare();
	customers_served=+customers;
}

void waiter::print()
{
	cout<<customers_served;
}

barista::barista(string name_,int income_):
	person(name_,income_)
{}

void barista::prepare() 
{}

owner::owner(string name_,int income_):
	person(name_,income_)
{}
