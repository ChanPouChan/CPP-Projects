#include <iostream>
#include <cstring>
using namespace std;
class STRING
{
	
	public:
		STRING();
		STRING(char *new_p);
		STRING(const STRING &ob);
		~STRING();
		int get_n() const;
		char* get_p() const;
		void set_p(char *new_p);
		void print();
	private:
		char *p;
		int n;	
};

int main()
{
	char s[80]="Test string";
	STRING s1(s);
	STRING s2=s1;
	
	strcpy(s,"Test string 2 ");
	s2.set_p(s);

	s1.print();
	cout<<endl;
	s2.print();
	cout<<endl;
	
	return 0;
}

STRING::STRING()
{
	n=0;
	p=NULL;
}

STRING::STRING(char *new_p) 
{
	n= strlen(new_p);
	
	p= new char[n];	
	if(!p)
		cout<<"Error: Memory allocation"<<endl;
		
	strcpy(p,new_p);	
} 

STRING::STRING(const STRING &ob)
{
	n=ob.get_n();
	
	p= new char[n];
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
 
void STRING::print()
{
	cout<<p;
}







