#include <iostream>
using namespace std;

class STRING
{
	
	public:
		STRING();
		STRING(char *new_p);
		STRING(const char *new_p);
		STRING(const STRING &ob);
		~STRING();
		int get_n() const;
		char* get_p() const;
		void set_p(char *new_p);
		STRING &operator=(STRING &right);
		char &operator[](int i);
		bool operator<(STRING &right);
		bool operator>(STRING &right);
		bool operator==(STRING &right);
		friend ostream &operator<<(ostream &left, const STRING &right);
		friend istream &operator>>(istream &left, STRING &right);	
	private:
		char *p;
		int n;	
};
