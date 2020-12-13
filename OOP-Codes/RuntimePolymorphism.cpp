#include<iostream>

using namespace std;

class Parent {
	public:
		// This method will be overridden.
		virtual void print() {
			cout << "Parent" << endl;
		} 

		//This method will not be overrriden.
		void hello() {
			cout << "Hello from Parent" << endl;
		}

};

class Child: public Parent {
	public:
		void print() {
			cout << "Child" << endl;
		}

		void hello() {
			cout << "Hello from Child" << endl;
		}
};


int main() {
	// No polymorphism.
	Child c;

	// No polymorphism.
	Parent *p = new Parent();

	// Runtime Polymorphism or Late Binding.
	Parent *pr = new Child();

	c.print();
	p->print();
	pr->print();
	pr->hello();
}



