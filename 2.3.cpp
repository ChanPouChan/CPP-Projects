#include <iostream>
#include <cstring>
using namespace std;

class mage
{
	public:
		mage(int new_age,char *new_beard_color,int new_mana);
		void fireball();
		void lightning();
		void wait();
	private:
		int age, mana;
		char beard_color[20];
			
};

int main()
{
	char str[20]="grey";
	mage gandalf(2019,str,100);
	
	gandalf.fireball();
	gandalf.wait();
	gandalf.lightning();
	gandalf.wait();
	gandalf.wait();
	gandalf.fireball();	
}

mage::mage(int new_age,char *new_beard_color,int new_mana)
{
	age=new_age;
	strcpy(beard_color,new_beard_color);
	mana=new_mana;
	
} 

void mage::fireball()
{
	mana=mana-30;
	cout<<"Fireball!!\n"<<"Mana is:"<<mana<<endl;
	
}

void mage::lightning()
{
	mana=mana-90;
	cout<<"Lightning!!\n"<<"Mana is:"<<mana<<endl;
}

void mage::wait()
{
	mana=mana+10;
	cout<<"Waiting...\n"<<"Mana is:"<<mana<<endl;
}
