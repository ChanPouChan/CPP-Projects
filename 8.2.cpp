#include <iostream>
using namespace std;

int  fibonacci(int n);

int main()
{
	int  i = fibonacci(15);
	cout<<i<<endl;
	return 0;
}

int fibonacci(int n)
{
	static int counter=0;
	
	counter++;
	cout<<counter<<endl;
		
	if(n==1 || n==2)
	{
		return 1;
	}
	else
		return fibonacci(n-1)+fibonacci(n-2);
}
