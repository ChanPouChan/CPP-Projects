#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class demigorgon
{
	public:
		demigorgon();
		int attack();
	private:
		int height,weight,hp;
		
};

class demidog
{
	public:
		demidog();
		int attack();
	private:
		int hp;	
};

class hive
{
	public:
		hive(bool in_demigorgon);
		int attack();
	private:
		demigorgon *demi_ptr;
		demidog *array_demidogs;
		int n_demidogs;	
};

int main()
{
	hive h(true);
	int damage;
	
	damage = h.attack();
	cout<<"Total damage:"<<damage<<endl;
	
	return 0;
}

demigorgon::demigorgon() 
{
	height=5;
	weight=500;
	hp=10000; 
	cout<<"1"<<endl;
}

int demigorgon::attack() 
{
	srand(time(NULL));
	return 300+rand()%(200-0+1);
}

demidog::demidog() 
{
	hp = 100;
	cout<<"2"<<endl;
}

int demidog::attack()
{
	return 10+rand()%(20-0+1);
}

hive::hive(bool in_demigorgon)
{
	if(in_demigorgon)
	{
		demi_ptr = new demigorgon;
		if(!demi_ptr)
			cout<<"Error: Memory allocation";
	}
	else
		demi_ptr = NULL;
	
	srand(time(NULL));
	n_demidogs= 10+rand()%(40-0+1);
	array_demidogs = new demidog [n_demidogs];
	if(!array_demidogs)
		cout<<"Error: Memory allocation";
}

int hive::attack() 
{
	int damage;
	int sum=0; 
	if(demi_ptr != NULL)
	{
		damage=demi_ptr->attack();
		sum+=damage;
		cout<<"Demigorgon did "<<damage<<" damage!"<<endl;
	}
	
	for(int i=0; i<n_demidogs; i++)
	{
		damage=array_demidogs[i].attack();
		sum+=damage;
		cout<<"Demidog "<<i<<" did "<<damage<<" damage!"<<endl;
	}
	
	return sum;
}
