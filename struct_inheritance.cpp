# include <iostream>

using namespace std;

struct A {
	int num1;
	virtual int get() {
		cout<<"A's get\n";
		return this->num1; 
	}
};

struct B : public A {
	int num2;
	int get() {
		cout<<"B's get\n";
		return this->num2;
	}
};

// B* can be type-cast to A*
// A* can't be type-cast to B*
/* A's get
   0
   B's get
   2 */


int func (A *a) {
	return a->get();
}

int main () {
	B b;
	A a;
	a.num1 = 0;
	b.num1 = 1;
	b.num2 = 2;
	cout<<func(&a)<<"\n";
	cout<<func(&b)<<"\n";
	return 0;
}
