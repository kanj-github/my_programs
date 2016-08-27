# include <iostream>

using namespace std;

int main () {
	int a= 5, b=2;
	if ( a<10 && ((a+=b) < 10)) cout<<"a is "<<a<<"\n";
	else cout<<"####ERROR#####\n";
	return 0;
}
