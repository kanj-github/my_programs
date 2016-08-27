#include <iostream>

using namespace std;

void func(int* p) {
	*p = 10;
}

int main () {
int c;
cout<<"Enter number \n";
cin>>c;
switch (c)
{
	case 0:
		//{
		int j;// = 5; - Can't initialise here without braces
		cout<<"0\n";
		func (&j);
		cout<<"Value set to "<<j<<"\n";
		break;
		//}
	default:
		cout<<"Not declaring j";
		break;
}
return 0;
}
