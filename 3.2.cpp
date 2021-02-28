#include <iostream>

using namespace std;

class Pet;
class Person {
	Pet* myPet;

public:
	//const int*const Method3(const int*const&)const;
	void getPet();
	~Person();
};

class Pet {
	Person* owner;

public:

	void setOwner(Person* owner_) {
		owner = owner_;
	}
};

//const int*const Person::Method3(const int*const&)const{
//	return 0;
//}

void Person::getPet() {
	/* Why would this be wrong? */
	// Pet p;
	// myPet = &p;

	myPet = new Pet;
	// We *need* this in this example
	myPet->setOwner( this );
}

Person::~Person(){
	delete myPet;
}

int main() {

	Person kapoios;
	
	kapoios.getPet();
}

