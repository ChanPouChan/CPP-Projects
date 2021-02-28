#include <iostream>
#include <cstdlib>
using namespace std;

class point
{
	public:
		point(int x_, int y_);
		int get_x();
		int get_y();
		void set_x(int x_);
		void set_y(int y_);
		friend ostream &operator<<(ostream &left, const point &right); 
	private:
		int x;
		int y;	
};

class board
{
	public:
		board(int N_);
		board(const board &ob);		
		~board();
		board &operator=(const board &ob);
		char get_element(int i, int j);
		friend ostream &operator<<(ostream &left, const board &right);
		void insert_point(point p);
		void clear();
	private:
		int N;
		char **pin;	
};

int main()
{
	int choice;
	point p(0,0);
	int x,y;
	board b(10);
		
	while(true)
	{
		cout<<"Menu: "<<endl;
		cout<<"1: Insert point "<<endl;
		cout<<"2: Print board"<<endl;
		cout<<"3: Clear board"<<endl;
		cout<<"4: Exit program"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Give X: ";
				cin>>x;
				p.set_x(x); 
				cout<<"Give Y: ";
				cin>>y;
				p.set_y(y); 
				b.insert_point(p); 
				
				break;
			case 2:
				cout<<endl<<b;
				
				break;
			case 3:
				b.clear();
				cout<<endl<<"Board was cleared :)"<<endl;
				
				break;
			case 4:
				cout<<"Bye"<<endl;
				exit(0);
				
			default:
				cout<<"Wrong input :("<<endl;
		}
	}
	
	return 0;
}

point::point(int x_, int y_) 
{
	if(x_<0 || x_>59)
	{
		cout<<"Wrong value :("<<endl;
		x=0;
	}
	else
		x=x_;
	
	if(y_<0 || y_>59)
	{
		cout<<"Wrong value :("<<endl;
		y=0;
	}
	else
		y=y_;	
}

int point::get_x() 
{
	return x;
}

int point::get_y() 
{
	return y;
}

void point::set_x(int x_)
{
	x=x_;
}

void point::set_y(int y_)
{
	y=y_;
}

ostream &operator<<(ostream &left, const point &right)
{
	left<<"X: "<<right.x<<" Y: "<<right.y<<endl;
	
	return left;
}

board::board(int N_)
{
	N=N_;
	
	pin = new char* [N];
	if(!pin)
	{
		cout<<"Error in memory allocation :(";
		exit(0);
	}
	
	for(int i=0; i<N; i++)
	{
		pin[i] = new char [N];	
		if(!pin[i])
		{
			cout<<"Error in memory allocation :(";
			;exit(0);
		}			 
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pin[i][j]= '.';
} 

board::~board() 
{
	for(int i=0; i<N; i++)
		delete [] pin[i];
	delete [] pin;	
}

board::board(const board &ob)
{
	N=ob.N;
	
	pin = new char* [N];
	if(!pin)
	{
		cout<<"Error in memory allocation :(";
		exit(0);
	}
	
	for(int i=0; i<N; i++)
	{
		pin[i] = new char [N];	
		if(!pin[i])
		{
			cout<<"Error in memory allocation :(";
			;exit(0);
		}			 
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pin[i][j]=ob.pin[i][j];
} 

board &board::operator=(const board &ob)
{
	if(pin!=NULL)
	{
		for(int i=0; i<N; i++)
			delete [] pin[i];
		delete [] pin;
	}
	
	N=ob.N;
	
	pin = new char* [N];
	if(!pin)
	{
		cout<<"Error in memory allocation :(";
		exit(0);
	}
	
	for(int i=0; i<N; i++)
	{	
		pin[i] = new char [N];	
		if(!pin[i])
		{
			cout<<"Error in memory allocation :(";
			;exit(0);
		}
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pin[i][j]=ob.pin[i][j];
}

char board::get_element(int i, int j)
{
	return pin[i][j];
}

ostream &operator<<(ostream &left, const board &right)
{
	for(int i=right.N-1; i>=0; i--)
	{
		for(int j=0; j<right.N; j++)	
			left<<right.pin[i][j]<<" ";
		left<<endl;	
	}
	
	return left;
}

void board::insert_point(point p)
{
	if(p.get_x()>=0 && p.get_x()<N && p.get_y()>=0 && p.get_y()<N)
		pin[p.get_x()][p.get_y()]='O';
} 

void board::clear()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pin[i][j]= '.';	
}
