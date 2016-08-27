# include <stdlib.h>
# include <stdio.h>

int main (int argc, char * args[]) {
	char * s, * str;
	int i,j,n;
	str = s = (char *) malloc(sizeof(char) * 16);
	if (argc == 2) {
		n = atoi(args[1]);
	}
	else n = 100;
	sprintf(s, "%d", n);
	for (i=10, j=1; ; i*=10,j++) if (n/i == 0) break;
	s+=j;
	sprintf(s,"%c", 'X');
	s++;
	*s='\0';
	printf("String is now %s", str);
	return 0;
}
