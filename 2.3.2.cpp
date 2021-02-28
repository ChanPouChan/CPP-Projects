#include <iostream>

using namespace std;

namespace Bank {
	const double minCharge = 3;
	const double rate = 0.015;
}

int main() {
	
	double amount=200;
	using namespace Bank;
	cout << "The initial amount is: " << amount << ", the minimum charge is: "<< minCharge << ", the rate is: " << rate << ", and the final amount is: "<< amount*(1+rate)-minCharge<< "\n";
	
	return 0;	
}

