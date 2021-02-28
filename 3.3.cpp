#include <iostream>
#include <cstring>

using namespace std;


class String{
    private:
        char * s;
        int length;
        int capacity;
    public:
        String(const char* p);

        String(const int &cap,const char* p);

        ~String();

        int size() const{
            return strlen(s) + 1;
        };

  /*      int Capacity() const{
            return 0;
        };
*/
        char at(const int &) const;
        int find(const String & , const int &)const;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


String::String(const char* p){
            s = new char[strlen(p)+1];
            strcpy(s,p);
            length = this->size();
//            capacity = this->Capacity();
            cout << "I just constructed a String " << s << endl;
}

 String::String(const int &cap,const char* p){
            this->capacity = cap;
            s = new char[strlen(p)+1];
            strcpy(s,p);
            length = this->size();
            cout << "I just constructed a String " << s << endl;
}

String::~String(){
    cout << "Deleting string: " << s << endl ;
   delete[] s;
}

char String::at(const int &i) const{
    if (i<length)
        return s[i];
    else
        return '\0';
}

int String::find(const String &p , const int &a = 0)const{
    if (p.size() > this->size())
        return -1;
    int j = 0;
    int i = a;
    int k = -1;
    int flag = 0;
    while ((i < this->size()-1) && (j < p.size()-1))
    {
        if(this->at(i)==p.at(j))
        {
            j++;
            if (flag == 0)
            {
                k = i;
                flag = 1;
            }
        }
        else
        {
            if (flag == 1) i--;
            j = 0;
            flag = 0;
            k = -1;
        }
        i++;
    }
    if (j==p.size()-1) return k; //we scaned all the string
    else return -1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
    String p("HELLOHELLOAA");
    cout <<"The size of string is " << p.size() << endl;
    cout <<"In the first index the char is "<< p.at(1) << endl;
    cout << p.at(20) << endl; // Index 20 -> '\0'
    cout << p.find("AB") << endl;
    cout << p.find ("HELLO",5) << endl;
    cout << p.find ("HELLO") << endl;
    return 0;
}

