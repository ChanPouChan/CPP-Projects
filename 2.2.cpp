#include <iostream>
#include <string>

using namespace std;

int main(){
	string str01="Hello World!",str02;
	cout << "The size of 'str01' is: " << str01.size() << " and the size of str02: "<< str02.size() << "\n";
	cout << "The length of 'str01' is: " << str01.length() << " and the length of str02: "<< str02.length() << "\n";

	cout << "The capacity of 'str01' is: " << str01.capacity() << " and the capacity of str02: "<< str02.capacity() << "\n";
	
	if (str01.empty()){
		cout << "'str01' is empty!\n";
	}else{
		cout << "'str01' is NOT empty!\n";
	}
	
	if (str02.empty()){
		cout << "'str02' is empty!\n";
	}else{
		cout << "'str02' is NOT empty!\n";
	}
	
	cout << "The value of 'str01' using the first way is: '" << str01 <<"\n";
	cout << "The value of 'str01' using the second way '[]' is: '";
	for (int i=0; i<str01.length(); ++i)
		cout << str01[i];
	cout << "'\nThe value of 'str01' using the third way 'at' is: '";
	for (int i=0; i<str01.length(); ++i)
		cout << str01.at(i);
	
	str02=str01;
	cout << "'\nThe new value of 'str02' before any changes is: '" << str02 <<"'\n";
	str02=str02+"!!";//or str02=str01+"!!";
	cout << "The newer value of 'str02' using '+' is: '" << str02 <<"'\n";
	str02=str01;
	str02+="!!";
	cout << "The newer value of 'str02' using '+=' is: '" << str02 <<"'\n";
	str02=str01;
	str02.append("!!");
	cout << "The newer value of 'str02' using 'append' is: '" << str02 <<"'\n";
	str02=str01;
	str02.push_back('!');
	str02.push_back('!');
	cout << "The newer value of 'str02' using 'push_back' is: '" << str02 <<"'\n";
	
	str02.insert((str02.size())-3," from DiT");
	cout << "The newer value of 'str02' with ' from DiT' insertion is: '" << str02 <<"'\n";
	
	int pos=str02.find('!');
	str02.replace(pos,2,", this is our second laboratory");
	
	cout << "The final value of 'str01' is: '" << str01 <<"\n";
	cout << "The final value of 'str02' is: '" << str02 <<"\n";
	
	return 0;
}
