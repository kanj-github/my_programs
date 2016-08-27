# include <iostream>

using namespace std;

int func1() {
	cout<<"func1\n";
	return 1;
}

int func2() {
	cout<<"func2\n";
	return 2;
}

int func3() {
	cout<<"func3\n";
	return 3;
}

int main () {
	func1() && func2() || func3();
	return 0;
}
