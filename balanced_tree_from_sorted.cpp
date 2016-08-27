# include <iostream>

using namespace std;

struct n_t {
	int d;
	n_t* l;
	n_t* r;
	n_t* p;
	
	n_t (n_t * p) : p(p) {
		l = r = NULL;
	}
};

void make_balanced_tree(int * arr, int s, n_t * n) {
	n->d = arr[s/2];
	
	if (s/2 > 0) {
		n_t * ltree = new n_t(n);
		n->l = ltree;
		make_balanced_tree(arr, s/2, ltree);
	}
	
	if (s/2-1 > 0) {
		n_t * rtree = new n_t(n);
		n->r = rtree;
		make_balanced_tree(arr+s/2+1, s-s/2-1, rtree);
	}
}

void dump (n_t * n) {
	cout<<n->d<<" -- ";
	if (n->l != NULL) {
		cout<<"l= "<<n->l->d;
	}
	if (n->r != NULL) {
		cout<<"\t r= "<<n->r->d;
	}
	cout<<"\n";
	if (n->l != NULL) dump(n->l);
	if (n->r != NULL) dump(n->r);
}

int main () {
	int size;
	cout<<"Enter size of sorted array\n";
	cin>>size;
	int * sorted = new int[size];
	for (int i=0; i<size; i++) cin>>sorted[i];
	
	n_t * root = new n_t (NULL);
	make_balanced_tree(sorted, size, root);
	
	dump(root);
	
	return 0;
}

