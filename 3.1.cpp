#include <iostream>
using namespace std;

int main()
{
	int x=69;
	cout<<"Value of x is : "<<x<<" and adresss is : "<<&x<<endl;
	
	int *p;
	p=&x;
	cout<<"Value of p is : "<<p<<" and adress is : "<<&p<<endl;
	cout<<"value of x through p is : "<<*p<<endl;
	
	int **pp;
	pp=&p;
	cout<<"Value of pp is : "<<pp<<" and adress is : "<<&pp<<endl;
	cout<<"value of x through pp is : "<<**pp<<endl;
	cout<<"value of p through pp is : "<<*pp<<endl;
}
