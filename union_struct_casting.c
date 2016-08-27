#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int oi;
	} one_t;

typedef struct {
	float ft;
	} two_t;

typedef union {
	one_t o;
	two_t t;
	} ot_t;

int main (){
	one_t *p1 = malloc(sizeof(one_t));
	p1->oi=99;
	ot_t *po;
	po = (ot_t *) p1;
	printf("%d\t%d\n%d\n%f\n", p1, po, po->o.oi, po->t.ft);
	return 0;
	}
