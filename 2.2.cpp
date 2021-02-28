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

int main()
{
	point p1(1.1,2.2),p2(1.0,2.0),p3;
	p1.printer();
	p2.printer();
	p3.printer();
	return 0;
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
