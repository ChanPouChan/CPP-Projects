#include <iostream>
using namespace std;

struct Point {
	private:
		double x;
		double y;
	public:
		Point(double x_, double y_) : x(x_), y(y_) {
			cout << "Point creation with x=" << x_<< ", and y=" << y_ << endl;
		}
		~Point() {
			cout << "~Point with x=" << x<< ", and y=" << y << endl;
		}
	
		double getx()const{
			return x;
		};
	
		double gety()const{
			return y;
		};
		void print() const{
			cout << "(" << x << ", " << y << ")" << endl;
		}
};

class List {
		struct Node {
			const Point data;
			Node* next;
			//Node(Point p, Node* n = NULL) : data(p), next(n) {
			Node(const Point& p, Node* n = NULL) : data(p), next(n) {				
				cout << "New Node with Point=(" << p.getx()<< "," << p.gety() << ")" << endl;
			}
			// Why different messages?
			//Node(Point p, Node* n = NULL) : data(p), next(n) {}
		};
		Node* start;
		unsigned int size_;

	public:

		List() : start(NULL), size_(0) {
			cout << "List creation" << endl;
		}
	
		~List() {
			Node* t1 = start;
			while (t1 != NULL) {
				Node* t2 = t1;
				t1 = t1->next;
				delete t2;
			}
			cout << "List destruction" << endl;
		}
	
		unsigned int size() const { return size_; }
	
		void pushFront(const Point& p) {
			start = new Node(p, start);	
			size_++;
		}
	
		bool pop(unsigned int index) {
			if (index >= size_) return false;
	
			Node* t = start;
			if (index == 0) {
				start = start->next;
				delete t;
			} else {
				while (--index > 0) t = t->next;
				Node* t2 = t->next;
				t->next = t->next->next;
				delete t2;
			}
			size_--;
			return true;
		}
	
		void print() const {
			Node* t = start;
			while (t != NULL) {
				t->data.print();
				t = t->next;
			}
		}
};

int main(void) {
	//Point p0;
	Point p1(1,2);
	Point p2(2,3);
	Point p3(3,4);
	Point p4(4,5);

	List l;
	l.pushFront(p1);
	l.pushFront(p2);
	l.pushFront(p3);
	l.pushFront(p4);

	l.pop(2);

	l.print();
	cout << "List size: " << l.size() << endl;
	
	return 0;
}

