#include <iostream>
using namespace std;
#define N 5

int main()
{
	
	int i;
	int A[N]= {5, 3, 2, 4, 0};
	int x=14;
	bool y;
	
	for(i=0; i<N; i++)
	{
		if(A[i]==x){
			y=true;
			break;
		}
	}
	
	if(y)
		cout<<x<<" was found in spot "<<i+1;
	else
		cout<<x<<" was not found :(";	
}
