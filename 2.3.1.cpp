#include <iostream>

using namespace std;

namespace Physics {
	const double minCharge = 1.602E-19;
	inline double rate(double a, double b) {
		return (b - a) / b;
	}
}

int main() {
	cout << Physics::minCharge << endl;

	cout << Physics::rate(20, 25) << endl;
	
	return 0;	
}

