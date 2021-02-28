#include <iostream>
using namespace std;

class card
{
	public:
		card(string name_, string color_, string rarity_);
		friend ostream &operator<<(ostream &left, card &right);
	protected:
		string name;
		string color;
		string rarity;	
};
class creature:public card
{
	public:
		creature(string name_, string color_, string rarity_, int attack_, int defence_, string kind_);
		friend ostream &operator<<(ostream &left, creature &right);
	private:
		int attack;
		int defence;
		string kind;
};

class land:public card
{
	public:
		land(string name_, string color_, string rarity_, int mana_, string descr_, bool tap_);
		friend ostream &operator<<(ostream &left, land &right);
	private:
		int mana;
		string descr;
		bool tap;
};

int main()
{
	creature c1("Akroan Crusader","Red","Common",1,1,"Human Soldier");
	cout<<c1;
	creature c2("Rune-Scarred Demon","Black","Rare",6,6,"Demon");
	cout<<c2;
	land l1("Plains","White","Uncommon",1,"Basic Land-Plains",false);
	cout<<l1;

	
	
	return 0;
}

card::card(string name_, string color_, string rarity_)
{
	name = name_;
	color = color_;
	rarity = rarity_;
}

ostream &operator<<(ostream &left, card &right)
{
	left<<endl<<"Card Name: "<<right.name<<endl<<"Color: "<<right.color<<endl<<"Rarity: "<<right.rarity<<endl;
	
	return left;
}

creature::creature(string name_, string color_, string rarity_, int attack_, int defence_, string kind_):
	card(name_,color_,rarity_)
{
	attack = attack_;
	defence = defence_;
	kind = kind_;
}

ostream &operator<<(ostream &left, creature &right)
{
	left<<endl<<"Card Name: "<<right.name<<endl<<"Attack: "<<right.attack<<endl<<"Defence: "<<right.defence<<endl<<"Kind: "<<right.kind<<endl<<"Color: "<<right.color<<endl<<"Rarity: "<<right.rarity<<endl;
	
	return left;
}

land::land(string name_, string color_, string rarity_, int mana_, string descr_, bool tap_):
	card(name_,color_,rarity_)
{
	mana = mana_;
	descr = descr_;
	tap_ = tap;
}

ostream &operator<<(ostream &left, land &right)
{
	left<<endl<<"Card Name: "<<right.name<<endl<<"Color: "<<right.color<<endl<<"Rarity: "<<right.rarity<<endl<<"Mana: "<<right.mana<<endl<<"Description: "<<right.descr<<endl;
	
	if(right.tap)
		left<<"Tapped"<<endl;
	else	
		left<<"Untapped"<<endl;
		
	return left;
}
