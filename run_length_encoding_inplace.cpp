#include <iostream>
#include <cstdio>

using namespace std;

// Append number after *arr. Return char* with automatic null character
char * add_count(char * arr, int n) {
	int i = sprintf(++arr, "%d", n);
	//cout<<"---"<<arr<<"  "<<i<<"\n";
	return arr+i;
}

int main(int argc, char* argv[]){
	if (argc != 2) {
		cout<<"Incorrect arguments.\n";
		return 1;
	}
	char * a = argv[1];
	char * b = a;
	
	int n;
	char temp; // Required only when repetition occurs twice.
	
	while (*a != '\0') {
		n = 1;
		while (*(++a) == *b) n++;
		temp = *a;
		if (n > 1) {
			//cout<<"-- "<<n<<"Next letter is "<<*a<<"\n";
			b = add_count(b, n);
			*b = temp;
			//cout<<"B is "<<*b<<" complete "<<argv[1]<<"\n";
			//n = 1;
		} else {
			*(++b) = *a;
		}
	}
	
	*(b+1) = '\0'; // May or may not already be null terminated 
	
	cout<<argv[1]<<"\n";

	return 0;
}