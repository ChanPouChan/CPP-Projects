#include <iostream>
using namespace std;
#define N 3

class XOX
{
	
	public:
		XOX();
		bool play(int x, int y);
		char check_winner();
		void print();
		void next_player();
		char get_player() const;
	private:
		char array[N][N];
		char player;
};

int main()
{
	XOX t;
	int x,y,counter=0; 
	
	while(true)
	{
		
		t.print(); 
		cout<<endl;
		cout<<t.get_player()<<" is playing"<<endl;
		
		cout<<"Give X coordinate: ";
		cin>>x;
		cout<<"Give Y coordinate: ";
		cin>>y;
		
		if(!t.play(x,y))
		{
			cout<<"Invalid move"<<endl;
			continue;
		}
		else
			counter++;
		
		if(t.check_winner()!= '-')
		{
			cout<<t.check_winner()<<"has won"<<endl;
			break;
			t.print();
		}
		else if 
		{
			cout<<"Draw"<<endl;
			break;
			t.print();
		}
		
		t.next_player();
	}
	
	return 0;
}

XOX::XOX()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			array[i][j]='-';
	}
	player = 'X';
}

bool XOX::play(int x, int y) 
{
	if(array[x][y]=='-')
	{
		array[x][y]=player;
		return true;
	}
	else
		return false;
}

char XOX::check_winner()
{
	int i,j;
	
	for(i=0; i<N; i++)
	{
		if(array[i][0]==array[i][1] && array[i][0]==array[i][2])
			return array[i][0];
	}
	
	for(j=0; j<N; j++)
	{
		if(array[0][j]==array[1][j] && array[0][j]==array[2][j])
			return array[0][j];
	}
	
	if(array[0][0]==array[1][1] && array[0][0]==array[2][2])
		return array[0][0];
		
	if(array[0][2]==array[1][1] && array[0][2]==array[2][0])
		return array[0][2];	
	
	return '-';	
}

void XOX::print() 
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cout<<array[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;	
}

void XOX::next_player()
{
	if(player = 'X')
		player = 'O';
	else
		player = 'X';
}

char XOX::get_player() const
{
	return player;
}
























