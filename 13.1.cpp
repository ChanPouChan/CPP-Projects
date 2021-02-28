#include <iostream>
using namespace std;

template <typename T>
class ARRAY
{
	public:
		ARRAY(int new_n);
		~ARRAY();
		ARRAY(const ARRAY<T> &ob);
		int get_n() const;
		T &operator[] (int i);
		ARRAY<T> &operator=(ARRAY<T> &right);
		ARRAY<T> &operator+=(int right);
		template <typename U> friend ostream &operator<<(ostream &left, const ARRAY<U> &right);
	private:
		int n;
		T *p;
};

int main()
{
	int n=10;
	ARRAY<double> ob(n);
	
	for(int i=0; i<n; i++)
		ob[i]=i*0.1;	
	
	cout<<ob;

	return 0;
}

template <typename T>
ARRAY<T>::ARRAY(int new_n )
{
	n= new_n;
	p= new T [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
}

template <typename T>
ARRAY<T>::ARRAY(const ARRAY<T> &ob)
{
	n=ob.get_n();
	
	p= new T [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
}

template <typename T>
ARRAY<T>::~ARRAY()
{
	delete [] p;
}

template <typename T>
int ARRAY<T>::get_n() const
{
	return n;
}

template <typename T>
T &ARRAY<T>::operator[] (int i)
{
	if(i>=0 && i<n)
		return p[i];
	else
		cout<<"Index Error";
}

template <typename T>
ARRAY<T> &ARRAY<T>::operator=(ARRAY<T> &right)
{
	if (this==&right)
		return *this; 
	
	n = right.n;
	delete [] p;
	p = new T [n];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	for (int i=0; i<n; i++)
		p[i]=right[i];
		
	return *this;
}

template <typename T>
ARRAY<T> &ARRAY<T>::operator+=(int right)
{
	int newn=n+right;
	int *newp;
	
	newp= new T [newn];
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

template <typename T>
ostream &operator<<(ostream &left ,const ARRAY<T> &right)
{
	int i=0;
	
	left<<"[";
	for(i=0; i<right.n-1; i++)
		cout<<right.p[i]<<" ";
	left<<right.p[right.n-1];
	left<<"]";
	
	return left;
}
