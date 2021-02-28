#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class mage
{
	public:
		mage(int new_age,string new_beard,int new_mana, int new_hp);
		int fireball();
		int  lightning();
		int attack();
		void wait();
		mage &operator-=(int minus_hp);
		mage &operator+=(int plus_hp);
		int get_hp();
		bool check_dead();
	private:
		int age, mana, hp;
		string beard;
			
};

class humanoid
{
	public:
		humanoid();
		humanoid &operator-=(int minus_hp);
		int attack();
		bool check_dead(); 
		int get_hp();
	private:
		int hp;	
};

int main()
{
	srand(time(0));
	
	mage gandalf(2019,"Grey",100,100);
	int damage;
	humanoid a;
	int r;
	
	r=1;
	while(1)
	{
		cout<<"Round "<<r<<endl;
		
		damage = gandalf.attack();
		a-=damage;
		
		if(rand()%2==0)
		{
			damage=gandalf.lightning();
			a-=damage;
		}
		else
		{
			damage=gandalf.fireball();
			a-=damage;
		}
		
		if(a.check_dead())
		{
			break;		
		}	
		
		damage=a.attack();
		gandalf-=damage;
		
		if(gandalf.check_dead())
		{
			break;		
		}	
		
		cout<<"Wizard health: "<<gandalf.get_hp()<<endl;
		cout<<"Humanoid health: "<<a.get_hp()<<endl;
		
		gandalf.wait();
		r++;
	}
}

mage::mage(int new_age,string new_beard,int new_mana, int new_hp)
{
	age=new_age;
	beard = new_beard; 
	mana=new_mana;
	hp=new_hp;
	
} 

int mage::fireball()
{
	if(mana>=90)
	{
	mana-=90;
	cout<<"Fireball!!\n"<<"Mana is:"<<mana<<endl;
	return 50+rand()&21;
	}
	else
	{
		cout<<"Not enough mana"<<endl;
		return 0;
	}
}

int mage::attack() 
{
	return 20+rand()%11;
}

int mage::get_hp() 
{
	return hp;
} 

int mage::lightning()
{
	if(mana>=30)
	{
		mana-=30;
		cout<<"Lightning!!\n"<<"Mana is:"<<mana<<endl;
		return 10+rand()&21;
	}
	else
	{
		cout<<"Not enough mana"<<endl;
		return 0;
	}
}

void mage::wait()
{
	mana=mana+10;
	cout<<"Waiting...\n"<<"Mana is:"<<mana<<endl;
}

mage &mage::operator+=(int plus_hp)
{
	hp+=plus_hp;
	
	if(hp>100)	
		hp=100;
		
	return *this;
}

mage &mage::operator-=(int minus_hp)
{
	hp-=minus_hp;
	
	if(hp<=0)	
		cout<<"Wizard dead! :("<<endl;
}

bool mage::check_dead() 
{
	if(hp<=0)
		return true;
	else 
		return false;
}

humanoid::humanoid() 
{
	hp=100;
}

humanoid &humanoid::operator-=(int minus_hp)
{
	hp-=minus_hp;
	
	if(hp<=0)	
		cout<<"Humanoid dead! :("<<endl;
}

humanoid::attack() 
{
	return 1+rand()%5; 
}

int humanoid::get_hp() 
{
	return hp;
}

bool humanoid::check_dead() 
{
	if(hp<=0)
		return true;
	else 
		return false;
}
