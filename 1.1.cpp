#include <iostream>

using namespace std;

bool isOdd(int k){
	if (k%2!=0)
		return true;
	else		
		return false;
}

bool isNotPrime(int candidate, int *primes, int sizeOfArray){
	if (isOdd(candidate)==true || sizeOfArray==0){
		for (int i=0;i<sizeOfArray;i++){
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

void printPrimes(int *primes, int sizeOfArray){
	if (sizeOfArray<2)
		cout<< 1 << ": "<< primes[0];
	else{		
		for (int i=0;i<sizeOfArray-1;i++)
			cout<< i+1 << ": "<< primes[i]<< ",\t";
		cout<< sizeOfArray << ": "<< primes[sizeOfArray-1];
	}
	cout<<"\n"; 
}

int main()
{
	const int max=100;
	int *allPrimes, *evenPrimes, *oddPrimes;
	int sizeOfAllPrimes=0, sizeOfEvenPrimes=0, sizeOfOddPrimes=0;
	//allPrimes[0]=2;
	//evenPrimes=new int(2);
	for (int i=2;i<max;i++){
		if (isNotPrime(i,allPrimes,sizeOfAllPrimes)==false){
			//addPrime(i,allPrimes,sizeOfAllPrimes++);		
			int *newPrimesArray=new int[++sizeOfAllPrimes];
			for (int j=0;j<sizeOfAllPrimes-1;j++)
				newPrimesArray[j]=allPrimes[j];
			newPrimesArray[sizeOfAllPrimes-1]=i;
			//if (sizeOfAllPrimes==1)
			//	delete allPrimes;
			/*else*/ if (sizeOfAllPrimes>1)
				delete[] allPrimes; 
			allPrimes=newPrimesArray;
			if (isOdd(i))
				sizeOfOddPrimes++;
			else	
				sizeOfEvenPrimes++;	
		}
	}
	cout << "All prime numbers until " << max << " are :\n";
	printPrimes(allPrimes,sizeOfAllPrimes);
	
	if (sizeOfEvenPrimes>0){
		if (sizeOfEvenPrimes==1){
			for (int i=0,j=0;i<sizeOfAllPrimes && j<sizeOfEvenPrimes;i++)
				if (isOdd(allPrimes[i])!=true)
					evenPrimes=new int(allPrimes[i]);
		}else{
			evenPrimes=new int[sizeOfEvenPrimes];
			for (int i=0,j=0;i<sizeOfAllPrimes && j<sizeOfEvenPrimes;i++)
				if (isOdd(allPrimes[i])!=true)
					evenPrimes[j++]=allPrimes[i];
		}
	} 
	cout << "\n\nAll even prime numbers until " << max << " are :\n";
	cout<< "1: "<< *evenPrimes<< "\t";
	if (sizeOfOddPrimes>0){
		oddPrimes=new int[sizeOfOddPrimes];
		for (int i=0,j=0;i<sizeOfAllPrimes && j<sizeOfOddPrimes;i++)
			if (isOdd(allPrimes[i])==true)
				oddPrimes[j++]=allPrimes[i];
	} 
	cout << "\n\nAll odd prime numbers until " << max << " are :\n";
	printPrimes(oddPrimes,sizeOfOddPrimes);	
	
	delete[] allPrimes, evenPrimes, oddPrimes;
	return 0;
}
