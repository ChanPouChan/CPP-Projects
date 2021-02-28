#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vectorOfInts;

bool isOdd(int k){
	if (k%2!=0)
		return true;
	else		
		return false;
}

bool isNotPrime(int candidate, vectorOfInts primes){
	if (isOdd(candidate)==true || primes.empty()){
		for (int i=0;i<primes.size();i++){
			if (primes[i]>1){
				if (candidate%primes[i]==0){
					return true;
				}
			}
		}
		return false;
	}else 
		return true;
}

void printPrimes(vectorOfInts primes){
	if (primes.size()<2)
		cout<< 1 << ": "<< primes[0];
	else{		
		for (int i=0;i<primes.size()-1;i++)
			cout<< i+1 << ": "<< primes[i]<< ",\t";
		cout<< primes.size() << ": "<< primes[primes.size()-1];
	}
	cout<<"\n"; 
}

int main()
{
	const int max=100;
	vectorOfInts allPrimes, evenPrimes, oddPrimes;
	for (int i=2;i<max;i++){
		if (isNotPrime(i,allPrimes)==false){
			allPrimes.push_back(i);
			if (isOdd(i))
				oddPrimes.push_back(i);
			else
				evenPrimes.push_back(i);
		}
	}
	cout << "All prime numbers until " << max << " are :\n";
	printPrimes(allPrimes);
	
	cout << "\n\nAll even prime numbers until " << max << " are :\n";
	printPrimes(evenPrimes);
	
	cout << "\n\nAll odd prime numbers until " << max << " are :\n";
	printPrimes(oddPrimes);
	
	allPrimes.clear();
	evenPrimes.clear();
	oddPrimes.clear();
	return 0;
}

