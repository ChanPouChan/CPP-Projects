#include <iostream>
#include "STRING.h"
using namespace std;

class table; //forward declaration

class chair
{
	public:
		chair(STRING color_, int height_);
		friend ostream &operator<<(ostream &left, const chair &right);
		friend void shrink(chair &c, table & t);
	private:
		STRING color;
		int height;	
};

class table
{
	public:
		table(STRING color_, int length_, int width_);
		friend ostream &operator<<(ostream &left, const table &right);
		friend void shrink(chair &c, table & t);
	private:
		STRING color;
		int length, width;
};

void shrink(chair &c, table & t)
{
	c.height= 0.9 * c.height;
	t.length= 0.9 * t.length;
	t.width= 0.9 * t.width;
}

int main()
{
	chair c("Black", 100);
	table t("Black", 200, 50);
	
	cout<<c;
	cout<<t;
	
	shrink(c,t);
	
	cout<<c;
	cout<<t;
	
	return 0;
}

chair::chair(STRING color_, int height_)
{
	color=color_;
	height=height_;
}

ostream &operator<<(ostream &left, const chair &right)
{
	left<<"[Chair] color: "<<right.color<<" height: "<<right.height<<endl;
	
	return left;
}

table::table(STRING color_, int length_, int width_)
{
	color=color_;
	length=length_;
	width=width_;
}

ostream &operator<<(ostream &left, const table &right)
{
	left<<"[Table] color: "<<right.color<<" length: "<<right.length<<" width: "<<right.width<<endl;
	
	return left;
}
