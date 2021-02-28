#include <iostream>
using namespace std;

class dummy
{
	
	public:
		dummy();
		dummy(int new_x);
		void set_x(int new_x);	
		int get_x() const;
		~dummy();
	private:
		int x;	
};

dummy::dummy()
{
	x=0;
}

dummy::dummy(int new_x)
{
	x= new_x;
}

void dummy::set_x(int new_x) 
{
	x=new_x;
}

int dummy::get_x() const
{
	return x;
}

dummy::~dummy()
{
	cout<<"Destructing with x "<<x<<endl;
}

int main()
{
	dummy dummy1(10), dummy2;
	
}
