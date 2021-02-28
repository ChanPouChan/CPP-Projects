#include <iostream>
#include <cmath>

using namespace std;

struct point{
		void set(const double& x=0, const double& y=0);
		void set2(point& p);
		void print() const;
		double dist(const point& p);
		bool equal(const point& p);
	private:
		double x=0, y=0;
		void printInfo() const;
};

class triangle{
		point a,b,c;
	public:
		void set(const point& a, const point& b,const point& c);
		const point& get(const int&) const;
		void print() const;
		double area() const;
		bool equal(const triangle& t) const;
		bool isTheSame(const triangle& t);
};

//****************************

void point::printInfo() const{
	cout << "x= " << this->x << ", y= " << this->y  << endl;
}

//****************************

void point::print() const{
	printInfo();
}

//****************************
void point::set(const double& x, const double& y){
	cout << "This->x" << this->x << ", x=" << x << endl;
	this->x=x;
	this->y=y;
}
//****************************
void point::set2(point& p){
	p.x=this->x;
	p.y=this->y;
}
//****************************

bool point::equal(const point& p) {
	return x == p.x && y == p.y;
}
//****************************

double point::dist(const point& p) {
	return sqrt( (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y) );
}
//****************************
//****************************
void triangle::set(const point& a, const point& b,const point& c){
	this->a=a;
	this->b=b;
	this->c=c;
}

void triangle::print() const{
	cout << "Rectangle: ";
	a.print();
	cout << " , ";
	b.print();
	cout << " , ";
	c.print();
	cout << endl;
}
	
const point& triangle::get(const int& i) const{
	if (i==0) return this->a;
	else if (i==1) return this->b;
	else  return this->c;
}

double triangle::area() const {
	return 1; /* ... */
}

// Two triangles have the same area
bool triangle::equal(const triangle& t) const{
	return area() == t.area();
}

// Two triangles are actually the same (same points)
bool triangle::isTheSame(const triangle& t) {
	// We have access to *everything* inside *any* Triangle,
	// not just the object we called the method on
	return ( a.equal(t.a) && b.equal(t.b) && c.equal(t.c) );
}

int main (){
	point p1, p2;
	double k=1,l=2;
	p1.set(k,l);
	p2.set();
	
	point a,b,c,d,e,f;
	a.set();
	b.set(2,3);
	c.set(3,4);
	b.set2(c);
	d.set(5,6);
	e.set(6,7);
	f.set(8,9);	

	cout << (a.equal(b) ? "" : "NOT ") << "Equal" << endl;
	
	cout << "Distance between 'a' and f is: " << a.dist(f) << endl;
	
	triangle t1,t2;
	t1.set(a,b,c);
	t2.set(d,e,f);
	/*const*/ point j=t1.get(2);
	
	b.print();
	j.print();

	cout << (t1.equal(t2) ? "" : "NOT ") << "Equal" << endl;

	cout << (t1.isTheSame(t2) ? "" : "NOT ") << "The same" << endl;
}
