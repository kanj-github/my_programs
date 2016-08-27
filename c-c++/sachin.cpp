# include <iostream>

#include "dhoni.h"

using namespace std;

int stupid (const char* str, const int len) {
	cout<<"str pointer is "<<str<<"\n";
	for (int i=0; i<len; i++) cout<<*(str+i);
	cout<<endl;
	return 0;
}

int main () {
	char in[] = "test";
	int (*cb) (const char *, const int);
	cb = &stupid;
	dumb (cb, in);
	return 0;
}
