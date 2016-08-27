#include <stdio.h>

#define KAND 3

int func (int n) {
	printf("func called with %d\n",n);
	return n;
}

int main() {
	if ((1+3) == 4 && (func(0)
#if (KAND == 3)
	|| func (1)
#endif
	)) printf("3\n");
#if (KAND == 2)
	printf("2\n");
#endif
}
