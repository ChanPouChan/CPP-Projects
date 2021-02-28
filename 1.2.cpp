#include <iostream>
using namespace std;

float average(int x, int y);
float average(float x, float y);

int main()
{	
	
	int ia, ib;
	float fa, fb;
	int input;
	
	cout<<"1-integer, 2-float: ";
	cin>>input;
	
	if(input==1)
	{
		cout<<"Type your numbers: ";
		cin>>ia;
		cin>>ib;
		cout<<"Average: "<<average(ia,ib);
	}
	else
	{
		cout<<"Type your numbers: ";
		cin>>fa;
		cin>>fb;
		cout<<"Average: "<<average(fa,fb);
	}
	
}

float average(int x, int y)
{
	return (x+y)/2.0;
}

float average(float x,float y)
{
	return (x+y)/2;
}
