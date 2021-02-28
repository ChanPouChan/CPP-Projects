#include <iostream>
using namespace std;

class ARRAY
{
	public:
		ARRAY(int new_n);
		~ARRAY();
		void set_i(int i, int val);
		int get_i(int i);
		void print();
	private:
		int n;
		int *p;
};

int main()
{
	int n=10;
	ARRAY ob(n);
	for(int i=0; i<10; i++)
	{
		ob.set_i(i,i*i);
	}
	ob.print();
	return 0;
}

ARRAY::ARRAY(int new_n )
{
	n= new_n;
	p= new int [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
}

ARRAY::~ARRAY()
{
	delete [] p;
}
void ARRAY::set_i(int i, int val)
{
	if(i>=0 && i<n)
		p[i]=val;
	else
		cout<<"Error: Accessing outside of array"<<endl;
}
 
int ARRAY::get_i(int i) 
{
	if(i>=0 && i<n)
		return p[i];
	else
		cout<<"Error: Accessing outside of array"<<endl;
}

void ARRAY::print()
{
	for(int k=0; k<n; k++)
		cout<<"Value is : "<<p[k]<<endl;
}




