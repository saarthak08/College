#include<iostream>

using namespace std;

// Abstract Class. (Cannot make an object of it)
class Parent {
	public:
		//Abstract Method
		virtual void print() = 0;

		void hello() {
			cout << "Hello from Parent" << endl;
		}

};

//Class Inheriting Abstract class should define Abstract Method in order to get instantiate.
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

	// Not allowed.
	//Parent *p = new Parent();

	// Runtime Polymorphism or Late Binding.
	Parent *pr = new Child();

	pr->print();
	pr->hello();
}



