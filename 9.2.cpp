#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 10

int main()
{
	string words[N] = {"bond","neo","boromir","saruman","gandalf","sansha","stark","spiderman","frodo","morhpeus"};
	
	//Choose random words
	
	srand(time(NULL));
	
	string hidden = words[rand()%N];
	
	//Initialize game	

	string game(hidden.length(), '_');
	
	//Guesses
	
	string bad_guesses;
	string right_guesses;
	
	//Number of bad guesses
	
	int MAX = 10;
	int wrong_guesses;
	
	//Algorithm
	
	char letter;
	
	while(true)
	{
		cout<<game<<endl;
		cout<<"Choose letter: ";
		cin>>letter;
		
		if(bad_guesses.find(letter) != bad_guesses.npos)
		{
			cout<<"Letter already chosen."<<endl;
			continue;
		}
					
		if(right_guesses.find(letter) != right_guesses.npos)
		{
			cout<<"Letter already chosen."<<endl;
			continue;	
		}
		
		if(hidden.find(letter) != hidden.npos)   //The letter exists
		{
			int pos;
			
			cout<<"Letter exists"<<endl;
			
			pos = hidden.find(letter);
			
			while(pos<hidden.length())
			{
				game[pos] = hidden[pos];
				pos = hidden.find(letter, pos+1 );
			}
			
			right_guesses.push_back(letter); 
			
			if(game.find('_') == hidden.npos)
			{
				cout<<"You win!"<<endl;
				cout<<"Word was: "<<game;
				break;
			}
		}
		else
		{
			cout<<"Letter does not exist"<<endl;
			wrong_guesses++;
			cout<<"Guesses left: "<<MAX-wrong_guesses<<endl;
			bad_guesses.push_back(letter); 
			
			if(wrong_guesses == MAX)
			{
				cout<<"You lose :("<<endl;
				cout<<"Word was: "<<hidden;
				break;
			}
		}
	}	
	
	return 0;
}


