#include <iostream>
using namespace std;

class ARRAY
{
	public:
		static int MAX_LENGTH;
		ARRAY(int new_n);
		~ARRAY();
		ARRAY(const ARRAY &ob);
		int get_n() const;
		int &operator[] (int i);
		ARRAY &operator=(ARRAY &right);
		ARRAY &operator+=(int right);
		friend ostream &operator<<(ostream &left, const ARRAY &right);
	private:
		int n;
		int *p;
};

int ARRAY::MAX_LENGTH = 1000;

int main()
{
	int n=100000;
	ARRAY ob(n);

	return 0;
}

ARRAY::ARRAY(int new_n )
{
	if(new_n>MAX_LENGTH)
	{
		cout<<"Length too big"<<endl;
		n=0;
	}
	else
	{
		n= new_n;
		p= new int [n];
		if(!p)
			cout<<"Error: Memory allocation"<<endl;
	}
}

ARRAY::ARRAY(const ARRAY &ob)
{
	n=ob.get_n();
	
	p= new int [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
}

ARRAY::~ARRAY()
{
	if(n>0)
		delete [] p;
}

int ARRAY::get_n() const
{
	return n;
}

int &ARRAY::operator[] (int i)
{
	if(i>=0 && i<n)
		return p[i];
	else
		cout<<"Index Error";
}

ARRAY &ARRAY::operator=(ARRAY &right)
{
	if (this==&right)
		return *this; 
	
	n = right.n;
	delete [] p;
	p = new int [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	for (int i=0; i<n; i++)
		p[i]=right[i];
		
	return *this;
}

ARRAY &ARRAY::operator+=(int right)
{
	int newn=n+right;
	int *newp;
	
	newp= new int [newn];
	if(!newp)
		cout<<"Error: Memory allocation"<<endl;
		
	for (int i=0; i<n; i++)
		newp[i]=p[i];
		
	for (int i=n; i<newn; i++)
		newp[i]=0;
	
	delete [] p;
	
	n=newn;
	p=newp; 
}

ostream &operator<<(ostream &left ,const ARRAY &right)
{
	int i=0;
	
	left<<"[";
	for(i=0; i<right.n-1; i++)
		cout<<right.p[i]<<" ";
	left<<right.p[right.n-1];
	left<<"]";
	
	return left;
}
