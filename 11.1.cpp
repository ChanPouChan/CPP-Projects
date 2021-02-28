#include <iostream>
#include  <ctime>
#include <cstdlib>
using namespace std;

class card
{
	public:
		card(string name_, string color_, string rarity_);
		virtual void print(ostream &left);
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
		void print(ostream &left);
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
		void print(ostream &left);
		friend ostream &operator<<(ostream &left, land &right);
	private:
		int mana;
		string descr;
		bool tap;
};

class pool
{
	public:
		pool();
		~pool();
		card *pick_random_card();
	private:
		card *cards[300];	
		int n_cards;
};

class hand
{
	public:
		hand(pool &p);
		void pick_card(pool &p, int i);
		void fill_hand(pool &p);
		friend ostream &operator<<(ostream &left, const hand &right);
	private:
		card *cards[10];
		int n_cards;
};

int main()
{
	srand(time(NULL));
	
	pool p;
	
	hand h(p);
	cout<<h;
	
	
	return 0;
}

card::card(string name_, string color_, string rarity_)
{
	name = name_;
	color = color_;
	rarity = rarity_;
}

void card::print(ostream &left) 
{
	left<<endl<<"Card Name: "<<name<<endl<<"Color: "<<color<<endl<<"Rarity: "<<rarity<<endl;
}

ostream &operator<<(ostream &left, card &right)
{
	right.print(left);
		
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
	right.print(left);
	
	return left;
}

void creature::print(ostream &left)
{
	left<<endl<<"Card Name: "<<name<<endl<<"Attack: "<<attack<<endl<<"Defence: "<<defence<<endl<<"Kind: "<<kind<<endl<<"Color: "<<color<<endl<<"Rarity: "<<rarity<<endl;
}

land::land(string name_, string color_, string rarity_, int mana_, string descr_, bool tap_):
	card(name_,color_,rarity_)
{
	mana = mana_;
	descr = descr_;
	tap_ = tap;
}

void land::print(ostream &left)
{
	left<<endl<<"Card Name: "<<name<<endl<<"Color: "<<color<<endl<<"Rarity: "<<rarity<<endl<<"Mana: "<<mana<<endl<<"Description: "<<descr<<endl;
	
	if(tap)
		left<<"Tapped"<<endl;
	else	
		left<<"Untapped"<<endl;

}

ostream &operator<<(ostream &left, land &right)
{
	right.print(left);
			
	return left;
}

pool::pool()
{
	cards[0] = new creature("Akroan Crusader","Red","Common",1,1,"Human Soldier");
	cards[1] = new creature("Rune-Scarred Demon","Black","Rare",6,6,"Demon");
	cards[2] = new land("Plains","White","Uncommon",1,"Basic Land-Plains",false);
	cards[3] = new land("Swamp","Black","Uncommon",1,"Basic Land-Swamp",false);
	cards[4] = new creature("Aegis Angel","White","Rare",5,5,"Angel");
	cards[5] = new creature("Angler Turtle","Blue","Rare",5,7,"Turtle");
	cards[6] = new creature("Harbringer of Life","Black","Common",2,3,"Summon Spirit");
	cards[7] = new creature("Ghalta, Primal Hunger","Green","Rare",12,12,"Elder Dinsoaur");
	cards[8] = new creature("Skarrgan Hellkite","Red","Rare",4,4,"Dragon");
	cards[9] = new creature("Spawn of Mayhem","Black","Rare",4,4,"Demon");	
	
	n_cards=10;
}

pool::~pool()
{
	for(int i=0; i<10; i++)
		delete cards[i];
}

card *pool::pick_random_card() 
{
	return cards[rand()%n_cards];
}

void hand::pick_card(pool &p, int i)
{
	cards[i]=p.pick_random_card();
}

void hand::fill_hand(pool &p)
{
	for(int i=0; i<7; i++)
		pick_card(p,i);
		
	n_cards = 7;
}

hand::hand(pool &p)
{
	fill_hand(p);
}

ostream &operator<<(ostream &left, const hand &right)
{
	for(int i=0; i<right.n_cards; i++)
		left<<*right.cards[i];
		
	return left;	
}
