# include <iostream>

using namespace std;

typedef struct {
	int n;
	char c;
} str_t;

void func (int * n) {
	str_t * p = (str_t *) n;
	cout<<p->c<<"\n";
}

int main () {
	str_t struc;
	struc.n=100;
	struc.c='x';
	func(&struc.n);
	return 0;
}
