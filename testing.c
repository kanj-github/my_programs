# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define KANJWA 0

typedef struct {
	int arr[16];
} arr16_t;

enum {
	length = 33
};

int func (const char* char1, const char* char2, int* n, arr16_t a) {
	int i;
	printf("%s --- %s --- %d\n",char1, char2, *n);
	for (i=0; i<16; i++) printf("%d\t", a.arr[i]);
	printf("\n");
	return 0;
}

void main () {

# if defined (KANJWA) \
                          && (KANJWA == 0)
	printf("defined\n");
# endif
	char * ptr1, * ptr2;
	char arr1[length], blank[]={'\0'};
	int i,n = length+1;
	sprintf(arr1,"hjhvgckhgdk");
	
	int array[16];
	for (i=0; i<16; i++) array[i] = i+1;
	arr16_t *a16 = (arr16_t *) (char*) array;
	//a16 = (arr16_t *) (char*) array;
	
	func (arr1, "just", &n, *a16);
	
	void * pointer = malloc(32);
	memset(pointer, '\0', 32);
	ptr1 = (char *) pointer;
	memcpy (ptr1, arr1, 11);
	//ptr1 = (char *) pointer;
	strcpy (ptr2, (char *) pointer);
	
	printf("%s---%s\n",ptr2,ptr1);
	
}
