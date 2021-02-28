#include <iostream>
#include <cmath>
using namespace std;

// volume of a cube
int volume (int s) {
	return s*s*s;
}
 
// volume of a cylinder
double volume (double r, int h) {
	return 3.14*r*r*(double)(h);
}
 
// volume of a cuboid
long volume (int l, int b, int h) {
	return l*b*h;
}

/* double dist(double a, double b) { return a*b; } */

/* inline */ double dist(double x1, double y1, double x2 = 0.0, double y2 = 0.0) {
	return sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}
 
int main() {
	cout << volume(10) << endl;
	cout << volume(2.5, 8) << endl;
	cout << volume(100, 75, 15) << endl;

	cout << dist(1, 1.3, 4, 3.4) << endl;
	cout << dist(2, 3, 0, 0) << endl;
	cout << dist(3, 4) << endl;
}
