#include <stdio.h>

void func(int* p) {
	printf("1\n");
	*p=10;
	printf("2\n");
}

int main () {
int c;
printf("Enter number \n");
scanf("%d",&c);
switch (c)
{
	case 0:
		{ // Can't compile without these braces. Can do that in C++
		int j;
		printf("0\n");
		func (&j);
		printf("Value set to %d\n",j);
		break;
		}
	default:
		printf("Not declaring j");
		break;
}
return 0;
}
