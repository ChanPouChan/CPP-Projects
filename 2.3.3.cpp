#include <iostream>
#include <ctime>

using namespace std;

namespace Math {
	const double minCharge = 1.602E-19;
	inline double rate(double a, double b) {
		return (b - a) / b;
	}
}

namespace Bank {
	const int minCharge = 3;
	const double rate = 0.015;

	int time(time_t *t){
		return 1;
	}
}

int main() {
	cout << Math::minCharge << endl;
	cout << Bank::minCharge << endl;

	cout << Math::rate(10, 15) << endl;
	cout << Bank::rate << endl;

	using namespace Bank;
	
	double amount=200;
	cout << "The initial amount is: " << amount << ", the minimum charge is: "<< minCharge << ", the rate is: " << rate << ", and the final amount is: "<< amount*(1+rate)-minCharge<< "\n";
	

	const char* rate = "good";
	cout << rate << endl;
	cout << Bank::rate << endl;
	
	cout << Bank::time(NULL) << endl;
	cout << ::time(NULL) << endl;
	
	return 0;	
}
