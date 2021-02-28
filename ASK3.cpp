#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
///////////////////////////////CLASSES-ABOUT-PERSON//////////////////////
/////////////////////////////////////////////////////////////////////////

class person
{
	public:
		person(){};
		person(string name_, int floor_num_, int class_num_);
		virtual ~person(){};
		virtual void print()=0;
		virtual void set_in_class();
		virtual bool get_in_class();
		virtual int get_floor_num();
		virtual int get_class_num();
		virtual string get_name();
	protected:
		string name;
		int floor_num;
		int class_num;
		bool in_class;
		int fatigue;	
};

class student:public person
{
	public:
		static int Lj;
		static int Ls;
		student(){};
		student(string name_, int floor_num_, int class_num_);
		~student();
		void attend(int hours);
		void print();
	private:
};

int student::Ls;
int student::Lj;

class teacher:public person
{
	public:
		static int Lt;
		teacher(string name_, int floor_num_, int class_num_);
		teacher(){};
		~teacher();
		void teach(int hours);
		void print();
	private:
};

int teacher::Lt;

/////////////////////////////////////////////////////////////////////////
///////////////////////////////CLASSES-ABOUT-AREAS///////////////////////
/////////////////////////////////////////////////////////////////////////

class area
{
	public:
		area();
		virtual ~area();
		virtual void enter(student *p)=0;
	protected:
		teacher *t_pointer;
		student *s_pointer;
		int hours;
};

class classroom:public area
{
	public:
		static int Cclass;
		classroom();
		~classroom();
		void enter(student *p);
		void print();
		void place(teacher *t);	
		void operate(int hours);
	private:
		student **room;
		teacher *teacher_in;
		int pos;		
};

int classroom::Cclass;

class corridor:public area
{
	public:
		corridor();
		~corridor();
		void enter(student *p);
		student* exit();
	private:
		
};

class floor:public area
{
	public:
		floor();
		~floor();
		void enter(student *p);
		void print();
		void place(teacher *t);
		void operate(int hours);
	private:
		corridor corr;
		classroom classes[6];
};

class stair:public area
{
	public:
		stair();
		~stair();
		void enter(student *p);
		student* exit();
	private:
};

class yard:public area
{
	public:
		yard();
		~yard();
		void enter(student *p);
		student* exit();
	private:
};

class school:public area
{
	public:
		school();
		~school();
		void enter(student *p);
		void print();
		void place(teacher *t);
		void operate(int hours);
	private:
		yard y;
		stair s;
		floor f[3];	
};

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////PERSON/////////////////////////////////
/////////////////////////////////////////////////////////////////////////

person::person(string name_, int floor_num_, int class_num_)
{
	name = name_;
	floor_num = floor_num_;
	class_num = class_num_;
	in_class = false;
	fatigue = 0;
} 

void person::set_in_class()
{
	in_class = true;
}

bool person::get_in_class() 
{
	return in_class;
}

int person::get_floor_num() 
{
	return floor_num;
}

int person::get_class_num() 
{
	return class_num;
}

string person::get_name() 
{
	return name;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////STUDENT////////////////////////////////
/////////////////////////////////////////////////////////////////////////

student::student(string name_, int floor_num_, int class_num_):
	person(name_,floor_num_,class_num_)
{
	cout<<"A New Student has been created! (Name: "<<name_<<" Floor: "<<floor_num_<<" Class: "<<class_num_<<")"<<endl;
}

student::~student()
{
	cout<<"A Student to be destroyed! (Name: "<<name<<" Floor: "<<floor_num<<" Class: "<<class_num<<")"<<endl;
} 

void student::attend(int hours)
{
	if(class_num>=1 && class_num<=3)
		fatigue += hours*Lj;
	else
		fatigue += hours*Ls;
}

void student::print()
{
	cout<<"Student: "<<name<<" Fatigue: "<<fatigue<<endl;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////TEACHER////////////////////////////////
/////////////////////////////////////////////////////////////////////////

teacher::teacher(string name_, int floor_num_, int class_num_):
	person(name_,floor_num_,class_num_)
{
	cout<<"A New Teacher has been created! (Name: "<<name_<<" Floor: "<<floor_num_<<" Class: "<<class_num_<<")"<<endl;
}

teacher::~teacher() 
{
	cout<<"A Teacher to be destroyed! (Name: "<<name<<" Floor: "<<floor_num<<" Class: "<<class_num<<")"<<endl;
}

void teacher::teach(int hours)
{
	fatigue += hours*Lt;
}

void teacher::print()
{
	cout<<"Teacher: "<<name<<" Fatigue: "<<fatigue<<endl;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////AREA///////////////////////////////////
/////////////////////////////////////////////////////////////////////////

area::area() 
{}

area::~area()
{}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////SCHOOL/////////////////////////////////
/////////////////////////////////////////////////////////////////////////

school::school() 
{
	cout<<"A New School has been created!"<<endl;
}

school::~school() 
{
	cout<<"A School to be destroyed!"<<endl;
}

void school::enter(student *p)
{
	s_pointer = p;
	cout<<"Student "<<s_pointer->get_name();
	cout<<" enters school!"<<endl; 
	
	y.enter(s_pointer); 
	
	s.enter(y.exit());
	
	int temp = s_pointer->get_floor_num();
	f[temp-1].enter(s.exit());
}

void school::print()
{
	cout<<"School life consists of: "<<endl;
	
	for(int i=0; i<=2; i++)
	{
		cout<<"Floor number "<<i+1<<" contains: "<<endl;
		f[i].print();
	}	
}

void school::place(teacher *t)
{
	t_pointer = t; 
	int temp = t_pointer->get_floor_num();
	f[temp-1].place(t_pointer);
}

void school::operate(int hours)
{
	for(int i=0; i<=2; i++)
		f[i].operate(hours);
} 

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////YARD///////////////////////////////////
/////////////////////////////////////////////////////////////////////////

yard::yard() 
{
	cout<<"A New Yard has been created!"<<endl;
}

yard::~yard() 
{
	cout<<"A Yard to be destroyed!"<<endl;
}

void yard::enter(student *p)
{
	s_pointer = p;
	cout<<"Student "<<s_pointer->get_name();
	cout<<" enters yard!"<<endl;
}

student* yard::exit()
{
	cout<<"Student "<<s_pointer->get_name();
	cout<<" exits schoolyard!"<<endl;
	return s_pointer;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////STAIR//////////////////////////////////
/////////////////////////////////////////////////////////////////////////

stair::stair() 
{
	cout<<"A New Stair has been created!"<<endl;
}

stair::~stair() 
{
	cout<<"A Stair to be destroyed!"<<endl;
}

void stair::enter(student *p)
{
	s_pointer = p;
	cout<<"Student "<<s_pointer->get_name();
	cout<<" enters stairs!"<<endl;
}

student* stair::exit()
{
	cout<<"Student "<<s_pointer->get_name();
	cout<<" exits stairs!"<<endl;
	return s_pointer;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////FLOOR//////////////////////////////////
/////////////////////////////////////////////////////////////////////////

floor::floor()
{
	cout<<"A New Floor has been created!"<<endl;
}

floor::~floor() 
{
	cout<<"A Floor to be destroyed!"<<endl;
}

void floor::enter(student *p)
{
	s_pointer = p;
	cout<<"Student "<<s_pointer->get_name();
	cout<<" enters floor!"<<endl;
	
	corr.enter(s_pointer);
	
	int temp = s_pointer->get_class_num();
	classes[temp-1].enter(corr.exit()); 
	
}

void floor::print() 
{
	for(int i=0; i<=5; i++)
	{
		cout<<"People in class "<<i+1<<" are: "<<endl;
		classes[i].print();
	}
}

void floor::place(teacher *t)
{
	t_pointer = t;
	int temp = t_pointer->get_class_num();
	classes[temp-1].place(t_pointer); 
}
 
void floor::operate(int hours)
{
	for(int i=0; i<=5; i++)	
		classes[i].operate(hours);
}
 
/////////////////////////////////////////////////////////////////////////
//////////////////////////////////CORRIDOR///////////////////////////////
/////////////////////////////////////////////////////////////////////////

corridor::corridor() 
{
	cout<<"A New Corridor has been created!"<<endl;
}

corridor::~corridor() 
{
	cout<<"A Corridor to be destroyed!"<<endl;
}

void corridor::enter(student *p)
{
	s_pointer = p;
	cout<<"Student "<<s_pointer->get_name();
	cout<<" enters corridor!"<<endl;
}

student* corridor::exit()
{
	cout<<"Student "<<s_pointer->get_name();
	cout<<" exits corridor!"<<endl;
	return s_pointer;
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////CLASSROOM//////////////////////////////
/////////////////////////////////////////////////////////////////////////

classroom::classroom()
{
	pos = 0;
	
	room = new student*[Cclass];
	if(!room)
		cout<<"Error allocating memory 1"<<endl;
	for(int i=0; i<Cclass; i++)
	{
		room[i] = new student();
		if(!room[i])
			cout<<"Error allocating memory 2"<<endl;	
	}
	
	teacher_in = new teacher();
	
	cout<<"A New Classroom has been created!"<<endl;
}

classroom::~classroom() 
{
	for(int i=0; i<Cclass; i++)
		delete room[i];
	delete [] room;
	
	delete teacher_in;
	
	cout<<"A Classroom to be deleted!"<<endl;
}

void classroom::enter(student *p)
{
	room[pos] = p;
	cout<<"Student "<<room[pos]->get_name();
	cout<<" enters classroom"<<endl;
	room[pos]->set_in_class();
	pos++;
}

void classroom::print()
{
	for(int i=0; i<Cclass; i++)
		room[i]->print();
	teacher_in->print();
}

void classroom::place(teacher *t)
{
	teacher_in = t;
	cout<<"Teacher "<<teacher_in->get_name()<<" enters class!"<<endl; 
	teacher_in->set_in_class();
} 

void classroom::operate(int hours)
{
	for(int i=0; i<Cclass; i++)
	{
		room[i]->attend(hours);
	}	
	
	teacher_in->teach(hours);
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////////MAIN///////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	const int temp1 = atoi(argv[1]);
	classroom::Cclass = temp1;
	
	const int temp2 = atoi(argv[2]);
	student::Lj = temp2;
	
	const int temp3 = atoi(argv[3]);
	student::Ls = temp3;
	
	const int temp4 = atoi(argv[4]);
	teacher::Lt = temp4;
	
	int N = atoi(argv[5]);
	
	srand(time(NULL));
	
	school *dit = new school();
	student *students[36];
	teacher *teachers[18];
	int student_to_enter, teacher_to_enter;
	
	ifstream myfile;
	
	string str;
    int k,l;
	
    myfile.open("Students.txt");
    
    
    for (int i=0;i<36;i++)
    {
        myfile>>str;
        myfile>>k;
        myfile>>l;
    	student *s = new student(str,k,l);
    	students[i] = s;
    }
	
	myfile.close();
	 
	myfile.open("Teachers.txt");
	
	 for (int i=0;i<18;i++)
    {
        myfile>>str;
        myfile>>k;
        myfile>>l;
    	teacher *t = new teacher(str,k,l);
    	teachers[i] = t;
    }
	
	int i = 0;
	 
	while(i<36)
	{
		student_to_enter = rand()%36;
		
		if(students[student_to_enter]->get_in_class() == false)
		{
			dit->enter(students[student_to_enter]); 
			i++;
		}
	}
	
	i=0;
	
	while(i<18)
	{
		teacher_to_enter = rand()%18;
		
		if(teachers[teacher_to_enter]->get_in_class() == false)
		{
			dit->place(teachers[teacher_to_enter]);		
			i++;
		}
	}
	
	dit->operate(N);
	
	dit->print();
	
	delete dit;
		
	return 0;	
}
