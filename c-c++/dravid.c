#include <cstdio>
#include <cstring>

#include "dhoni.h"

void dumb(int (*call) (const char*, const int), char *in) {
	char ou[9] = "TEST";
	strcat(ou,in);
	int retval = (*call)(ou, 9);
	printf("retvalue is %d\n",retval);
}
