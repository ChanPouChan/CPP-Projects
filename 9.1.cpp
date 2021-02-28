#include <iostream>
using namespace std;
#define SIZE 10

//Forward Declaration
void swap(string &s1, string &s2);
void insertion_sort(string *pinakas, int N);

int main()
{
	string pin[SIZE] = {"asd", "abc", "mpo","gkaf", "asldk", "qwerty", "baba", "mti", "kalsd", "asgbfb"};
	
	insertion_sort(pin, SIZE);
	
	for(int i=0; i<SIZE; i++)
		cout<<pin[i]<<endl;
	
	return 0;
}

void insertion_sort(string *pinakas, int N)
{
	for(int i=1; i<N; i++)
		for(int j=i; j>=1; j--)
		{
			if(pinakas[j]<pinakas[j-1])
				swap(pinakas[j],pinakas[j-1]);
			else
				break;
		}
}

void swap(string &s1, string &s2)
{
	string k = s1;
	s1=s2;
	s2=k;
}
