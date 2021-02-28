#include <iostream>
//#include <cstdlib>
//#include <ctime>
using namespace std;

class movie
{
	public:
		movie(){}
		movie(string name_, double imdb_, int debut_);
		virtual double score();
	private:
		string name;
		double imdb;
		int debut;
};

class thriller:virtual public movie
{
	public:
		thriller(double fear_factor_);
		thriller(string name_, double imdb_, int debut_, double fear_factor_);
		virtual double score();
	protected:
		double fear_factor;
};

class comedy:virtual public movie
{
	public:
		comedy(double fun_factor_);
		comedy(string name_, double imdb_, int debut_, double fun_factor_);
		virtual double score();
	protected:
		double fun_factor;
};

class comedy_thriller:public thriller, public comedy
{
	public:
		comedy_thriller(string name_, double imdb_, int debut_, double fear_factor_, double fun_factor_);
		double score();	
	private:
};

int main()
{
	thriller t1("It, Chapter 2", 6.8, 10, 8.0);
	cout<<"Score: "<<t1.score()<<endl;
	thriller t2("Us", 6.9, 30, 7.0);
	cout<<"Score: "<<t2.score()<<endl;
	thriller t3("Silence of the Lambs", 8.6, 1540, 9.0);
	cout<<"Score: "<<t3.score()<<endl;
	comedy m("Test", 8.6, 1540, 9.0);
	cout<<"Score: "<<m.score()<<endl;
	comedy_thriller a("Test2", 6.8, 10, 8.0, 0.0);
	cout<<"Score: "<<a.score()<<endl;
	
	return 0;
}

movie::movie(string name_, double imdb_, int debut_) 
{
	name = name_;
	imdb = imdb_;
	debut = debut_;
}

double movie::score() 
{
	return imdb / (0.5 * debut);
}

thriller::thriller(string name_, double imdb_, int debut_, double fear_factor_):
	movie(name_,imdb_,debut_)
{
	fear_factor = fear_factor_;
}

thriller::thriller(double fear_factor_)
{
	fear_factor = fear_factor_;
}

double thriller::score()
{
	return fear_factor*movie::score();
} 

comedy::comedy(double fun_factor_)
{
	fun_factor = fun_factor_;
}

comedy::comedy(string name_, double imdb_, int debut_, double fun_factor_):
	movie(name_,imdb_,debut_)
{
	fun_factor = fun_factor_;
}

double comedy::score()
{
	return fun_factor*movie::score();
} 

comedy_thriller::comedy_thriller(string name_, double imdb_, int debut_, double fear_factor_, double fun_factor_):
	movie(name_,imdb_,debut_), thriller(fear_factor_), comedy(fun_factor)
{} 

double comedy_thriller::score()
{
	return (fun_factor+fear_factor)/2*movie::score();
} 
