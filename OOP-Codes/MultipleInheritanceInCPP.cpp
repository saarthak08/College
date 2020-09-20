#include<iostream>

using namespace std;


class A {
	public: 
		void print() {
			cout << "A" << endl;
		}
};

class B {
	public: 
		void print() {
			cout << "B" << endl;
		}
};


class Child: public A, public B {

};

int main() {
	Child *c=new Child();
	c->A::print();
	c->B::print();
}