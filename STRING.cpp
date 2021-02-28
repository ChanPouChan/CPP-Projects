#include <iostream>
#include "STRING.h"
#include <cstring>
using namespace std;

STRING::STRING()
{
	n=0;
	p= new char[1];
	p[0]='\0';
}

STRING::STRING(char *new_p) 
{
	n= strlen(new_p);
	
	p= new char[n+1];	
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p,new_p);	
} 

STRING::STRING(const char *new_p)
{
	n= strlen(new_p);
	
	p= new char[n+1];	
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p,new_p);
}

STRING::STRING(const STRING &ob)
{
	n=ob.get_n();
	
	p= new char[n+1];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p, ob.get_p());
}
STRING::~STRING() 
{
	delete p;
}

int STRING::get_n() const
{
	return n;
}

char* STRING::get_p() const
{
	return p;
}

void STRING::set_p(char * new_p)
{
	if(p!=NULL)
		delete p;
		
	n=strlen(new_p);
	
	p= new char[n];	
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p,new_p);		
}
 
STRING &STRING::operator=(STRING &right)
{
	if(this == &right)
		return *this;
	
	n=right.n;
	
	delete [] p;
	p = new char [n+1];
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p,right.p);
	
	return *this;
}

char &STRING::operator[](int i)
{
	if (i>=0 && i<=n)
		return p[i];
	else
		cout<<"Index out of bounds";
}

bool STRING::operator<(STRING &right)
{
	if (strcmp(p, right.p)<0) 
		return true ;
	else 	 
		return false;
}

bool STRING::operator>(STRING &right)
{
	if (strcmp(p, right.p)>0) 
		return true ;
	else 	 
		return false;
}

bool STRING::operator==(STRING &right)
{
	if (strcmp(p, right.p)==0) 
		return true ;
	else 	 
		return false;
}

ostream &operator<<(ostream &left, const STRING &right)
{
	left<<right.p;
	
	return left;
}

istream &operator>>(istream &left, STRING &right)
{
	char in_p[80];
	
	left>>in_p;
	
	if(right.p != NULL)
		delete [] right.p;
	
	right.p = new char [strlen(in_p)+1];
	if(right.p==NULL)
		cout<<"Error: Memory allocation"<<endl;
			
	right.n=strlen(in_p);
	strcpy(right.p,in_p);
	
	return left;	
}
