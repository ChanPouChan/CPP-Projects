#include <iostream>
using namespace std;

class point
{
	public:
		point();
		point(double new_x,double new_y);
		void setter_x(int new_x);
		void setter_y(int new_y);
		double getter_x() const;
		double getter_y() const;
		void printer();
	private:
		double x,y;
};

void swap(int &a,int &b);
void swap(double &a,double &b);
void swap(point &a, point &b);


int main()
{
	int a=1, b=2;
	double c=2.2, d=3.3;
	point p1(1.1,2.2),p2(1.3,2.4);
	swap(a,b);
	cout<<"a: "<<a<<" b: "<<b<<endl;
	swap(c,d);
	cout<<"c: "<<c<<" d: "<<d<<endl;
	swap(p1,p2);
	p1.printer();
	p2.printer();
	return 0;	
}

void swap(int &a,int &b)
{
	int x;
	x=a;
	a=b;
	b=x;
}

void swap(double &a,double &b)
{
	double x;
	x=a;
	a=b;
	b=x;
}

void swap(point &a,point &b)
{
	point x;
	x=a;
	a=b;
	b=x;
}

point::point()
{
	x=0.0;
	y=0.0;
}

point::point(double new_x,double new_y)
{
	x=new_x;
	y=new_y;
}

void point::setter_x(int new_x)
{
	x=new_x;
}

void point::setter_y(int new_y)
{
	y=new_y;
}

double point::getter_x() const
{
	return x;
}

double point::getter_y() const
{
	return y;
}

void point::printer()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
