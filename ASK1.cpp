#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


////////////////////////////////////////////////////////////////
/////////////////////////CLASSES////////////////////////////////
////////////////////////////////////////////////////////////////

class student
{
	public:
		student(string name_, int f_, int c_);
		student(const student &s);
		student(){}
		~student();
		int get_f();
		int get_c();
		void set_location(string location_);
		void set_class(int  c_);
		void set_floor(int f_);
		void set_name(string name_);
		void print();		
	private:
		string name;
		int f;
		int c;
		string location;
};

class teacher
{
	public:
		teacher(string name_, int f_, int c_);
		teacher(){}
		~teacher();
		teacher(const teacher &t);
		void print();
		void place();
		bool get_in();
		void set_class(int  c_);
		void set_floor(int f_);
		void set_name(string name_);
	private:
		string name;
		int f;
		int c;
		bool in;
};

class classroom
{
	public:
		static int size_room;	
		classroom();
		~classroom();
		void enter(student *s);
		void print(int i);
	private:
		student **room;
		int in;
};

int classroom::size_room;

class corr
{
	public:
		static int size_corr;
		corr();
		~corr();
		int get_class(int i);
		student *exit(int i);
		void enter(int i, student *s);
		void print();
	private:
		student **c;
};

int corr::size_corr;

class yard
{
	public:
		static int size_yard;
		yard();
		~yard();
		void enter(int i, student &s);
		student *exit(int i);
		void print();
	private:
		student **y;
};

int yard::size_yard;

class stair
{
	public:
		static int size_stair;
		stair();
		~stair();
		void enter(int i , student *s);
		student *exit(int i);
		void print();
		int get_floor(int i);
	private:
		student **s;
};

int stair::size_stair;

class floor
{
	public:
		floor();
		~floor();
		void enter(int i, student * s);
    	int get_class(int i);
    	void exit_corr(int i, int j);
    	void print(int j);
	private:
		corr corridor;
		classroom classes[6];
};

class school
{
	public:
		school(int i);
		~school();
		void enter_school(int i);
    	void enter_yard(int i, int j);
    	void exit_yard(int i, int j);
    	void exit_stairs(int i, int j , int k);
    	void exit_corr(int i, int j, int k);
    	bool teacher_info(int i, int j);
    	void print();
    	void place(int i);
    	int get_floor(int i);
    	int get_class(int i, int j);
	private:
		student *students;
		teacher *teachers;
		yard y;
		stair s;
		floor f[3];	
};

//////////////////////////////////////////////////////
///////////////STUDENT////////////////////////////////
//////////////////////////////////////////////////////

student::student(string name_, int f_, int c_)
{
	name=name_;
	f=f_;
	c=c_;
	location="Outside";
	cout<<"A New Student has been created! "<<name<<" Floor: "<<f<<" Class: "<<c<<endl;
}

student::~student() 
{
	cout<<"A Student to be destroyed"<<endl;
}

int student::get_f() 
{
	return f;
}

int student::get_c() 
{
	return c;
}

void student::set_location(string location_) 
{
	location=location_;
}

void student::print()
{
	cout<<"Student: "<<name<<" Floor: "<<f<<" Class: "<<c<<endl;
}

student::student(const student &s)
{
	name=s.name;
	f=s.f;
	c=s.c;
	location=s.location;
} 

void student::set_class(int c_) 
{
	c=c_;
}

void student::set_floor(int f_) 
{
	f=f_;
}

void student::set_name(string name_) 
{
	name=name_;
}
//////////////////////////////////////////////////////////////////////
//////////////////////TEACHER/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

teacher::teacher(string name_, int f_, int c_)
{
	name=name_;
	f=f_;
	c=c_;
	in=false;
	cout<<"A New Teacher has been created!"<<name<<" Floor"<<f<<" Class"<<c<<endl;
} 

teacher::~teacher() 
{
	cout<<"A Teacher to be destroyed!"<<endl;
}

void teacher::place()
{
	in=true;
}

void teacher::print()
{
	if(in==true)
		cout<<"The teacher is: "<<name<<" Floor: "<<f<<" Class: "<<c<<endl;
}

teacher::teacher(const teacher &t)
{
	name=t.name;
	f=t.f;
	c=t.c;
	in=t.in;
} 

bool teacher::get_in()
{
	return in;
}

void teacher::set_floor(int f_) 
{
	f=f_;
}

void teacher::set_class(int c_) 
{
	c=c_;
}

void teacher::set_name(string name_) 
{
	name=name_;
}
/////////////////////////////////////////////////////////////////////
////////////////////////////SCHOOL///////////////////////////////////
/////////////////////////////////////////////////////////////////////

school::school(int j)
{
	ifstream myfile;
    myfile.open("Students.txt");
    students = new student[j];
    for (int i=0;i<j;i++)
	{
        string temp;
        myfile>>temp;
        students[i].set_name(temp);
        int temp2;
        myfile>>temp2;
        students[i].set_floor(temp2);
        myfile>>temp2;
        students[i].set_class(temp2);
    }
    myfile.close();
    
    myfile.open("Teachers.txt");
    int k = 18;
    teachers = new teacher[k];
    for (int i=0;i<18;i++)
	{
        string temp;
        myfile>>temp;
        teachers[i].set_name(temp);
        int temp2;
        myfile>>temp2;
        teachers[i].set_floor(temp2);
        myfile>>temp2;
        teachers[i].set_class(temp2);
    }
    myfile.close();
	
	cout<<"A New School has been created! "<<endl;
}

school::~school() 
{
	cout<<"A School to be destroyed!"<<endl;
}

void school::enter_school(int i)
{
	students[i].print();
	students[i].set_location("School");
	cout<<" enters school!"<<endl;
}

void school::enter_yard(int i, int j)
{
	y.enter(i,students[j]); 
}  

void school::exit_yard(int i, int j)
{
	s.enter(i, y.exit(j));
}  

void school::exit_stairs(int i, int j , int k)
{
	f[j].enter(k, s.exit(i));
}

void school::exit_corr(int i, int j, int k)
{
	f[i].exit_corr(j, k);
}

bool school::teacher_info(int i, int j)
{
	j--;
	int val=0;
	
	if(i==0)
		val = j;
	else if(i==1)
	{
		val = 6+j; 
	}
	else if(i==2){
		val = 12+j;
	}
	
	return teachers[val].get_in();
}

void school::print()
{
	cout<<"School life consists of: "<<endl;
	y.print();
    s.print();
    f[0].print(1);
    f[1].print(2);
    f[2].print(3);
    for (int i = 0; i < 18; i++)
        teachers[i].print();
}

void school::place(int i)
{
	teachers[i].place();
} 

int school::get_floor(int i)
{
	return s.get_floor(i);
} 

int school::get_class(int i, int j)
{
	return f[i].get_class(j);
} 
/////////////////////////////////////////////////////////////////////////
///////////////////////////CLASSROOM/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

classroom::classroom()
{
	room = new student*[size_room];
	
	for(int i=0; i<size_room; i++)
		room[i]= new student();
		
	cout<<"A New Classroom has been created! "<<endl;
	in=0;
}

classroom::~classroom() 
{
	cout<<"A Classroom to be destroyed!"<<endl;
}

void classroom::enter(student *s)
{
	room[in] = s;
	room[in]->set_location("Class");
	room[in]->print();
	cout<<" enters classroom!"<<endl;
	in++;
}

void classroom::print(int i)
{
	cout<<"People in class: "<<i+1<<" are: "<<endl;
	for(int i=0; i<size_room; i++)
		if(room[i]!=NULL)
			room[i]->print();
} 

/////////////////////////////////////////////////////////////////////
///////////////////////////YARD//////////////////////////////////////
/////////////////////////////////////////////////////////////////////

yard::yard()
{
	y = new student*[size_yard];
	
	for(int i=0; i<size_yard; i++)
		y[i]= new student();
	
	cout<<"A New Yard has been created! "<<endl;
}

yard::~yard() 
{
	cout<<"A Yard to be destroyed!"<<endl;
}

void yard::enter(int i, student &s)
{
	y[i] = &s;
	y[i]->set_location("Yard"); 
	y[i]->print();
	cout<<" enters yard!"<<endl;
}

student *yard::exit(int i)
{
	y[i]->print();
	cout<<" exits yard!"<<endl;
	student *temp=y[i];
	y[i]=NULL;
	return temp;
} 

void yard::print()
{
	cout<<"People in schoolyard are: "<<endl;
	for(int i=0; i<size_yard; i++)
		if(y[i]!=NULL)
			y[i]->print();
}
/////////////////////////////////////////////////////////////////////
//////////////////////////STAIR//////////////////////////////////////
/////////////////////////////////////////////////////////////////////

stair::stair()
{
	s = new student*[size_stair];
	
	for(int i=0; i<size_stair; i++)
		s[i]= new student();
		
	cout<<"A New Stair has been created! "<<endl;
}

stair::~stair() 
{
	cout<<"A Stair to be destroyed!"<<endl;
}

void stair::enter(int i , student *st)
{
	s[i] = st;
	s[i]->set_location("Stairs");
	s[i]->print();
	cout<<" enters staris!"<<endl;  
}

student *stair::exit(int i)
{
	s[i]->print();
	cout<<" exits stairs!"<<endl;	
	student *temp=s[i];
	s[i]=NULL;
	return temp;
}

void stair::print()
{
	cout<<"People in stairs are: "<<endl;
	for(int i=0; i<size_stair; i++)
		if(s[i]!=NULL)
			s[i]->print();
}

int stair::get_floor(int i)
{
	return s[i]->get_f();
}
//////////////////////////////////////////////////////////////////////
///////////////////////////FLOOR//////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void floor::enter(int i, student *s)
{
	corridor.enter(i, s);
}

int floor::get_class(int i)
{
	return corridor.get_class(i);
}

void floor::exit_corr(int i, int j)
{
	classes[i].enter(corridor.exit(j));
}

void floor::print(int j)
{
	cout<<"Floor number "<<j<<" contains: "<<endl;
	corridor.print();
	for(int i=0; i<6; i++)
		classes[i].print(i);
}

floor::floor() 
{
	cout<<"A New Floor has been created! "<<endl;
}

floor::~floor() 
{
	cout<<"A Floor to be destroyed!"<<endl;
}
/////////////////////////////////////////////////////////////////////
//////////////////////////CORRIDOR///////////////////////////////////
/////////////////////////////////////////////////////////////////////

corr::corr()
{
	c = new student*[size_corr];
	
	for(int i=0; i<size_corr; i++)
		c[i]= new student();
		
	cout<<"A New Corridor has been created! "<<endl;
}

corr::~corr() 
{
	cout<<"A Corridor to be destroyed!"<<endl;
}

int corr::get_class(int i)
{
	return c[i]->get_c();
} 

student *corr::exit(int i)
{
	c[i]->print();
	cout<<" enters corridor!"<<endl;
	student *temp = c[i];
	c[i] = NULL;
	return temp;
}

void corr::enter(int i, student *s)
{
	c[i] = s;
	c[i]->set_location("Corridor"); 
	c[i]->print();
	cout<<" enters floor!"<<endl;
	cout<<" enters corridor!"<<endl;
} 

void corr::print()
{
	cout<<"People in corridor are: "<<endl; 
	for(int i =0; i<size_corr; i++)
		if(c[i]!= NULL)
			c[i]->print();
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////MAIN///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	
	const int Cyard= atoi(argv[2]);
    yard::size_yard=Cyard;
    const int Cclass =atoi(argv[1]);
    classroom::size_room=Cclass;
    const int Cstair = atoi(argv[3]);
    stair::size_stair=Cstair;
    const int Ccorr=atoi(argv[4]);
    corr::size_corr=Ccorr ;
    int Cschool=Cclass*18;
	
	int in_school = 0;
	int in_yard = 0;
	int in_stair = 0;
	int in_corridors[3];
	for(int i=0; i<2; i++)
		in_corridors[i] = 0;
	int teachers = 0;
	
	school DIT(36);
	srand(time(NULL));
	
	while((teachers < 18) && (in_school < Cschool))
	{
		while((in_yard < Cyard))
		{
			DIT.enter_school(in_school);
			DIT.enter_yard(in_yard,in_school); 
			in_school++;
			in_yard++;
		}
		
		while((in_stair < Cstair) && (in_yard > 0))
		{
			in_yard--;
			DIT.exit_yard(in_stair,in_yard);
			in_stair++;
		}
		
		while(((in_corridors[0] < Ccorr) && (in_corridors[1] < Ccorr)) && (in_corridors[2] < Ccorr) && (in_stair > 0))
		{
			in_stair--;
			int k = DIT.get_floor(in_stair)-1;
			DIT.exit_stairs(in_stair, k, in_corridors[k]);
			in_corridors[k]++;
		}
		
		for(int i=0; i<=2; i++)
		{
			while(in_corridors[i] > 0)
			{
				in_corridors[i]--;
				int class_ = DIT.get_class(i, in_corridors[i])-1;
				if(DIT.teacher_info(i, class_)==false) 
					DIT.exit_corr(i, class_, in_corridors[i]);
			}
		}
		
		if(in_yard < 0)
			in_yard = 0;
			
		if(in_stair < 0)
			in_stair = 0;
			
		if(in_corridors[0] < 0)
			in_corridors[0] = 0;
			
		if(in_corridors[1] < 0)
			in_corridors[1] = 0;
			
		if(in_corridors[2] < 0)
			in_corridors[2] = 0;
			
		int random = rand() % (0+18);
		teachers = teachers+random;
		if(teachers > 18)
			teachers = 18;
			
		for(int i=0; i<teachers; i++)
			DIT.place(i); 
	}
	
	DIT.print();
}

