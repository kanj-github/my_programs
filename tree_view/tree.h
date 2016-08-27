// Header to define stuff
# include <vector>
# include <iostream>

class node {
	int data;
	node* lc;
	node* rc;
	node* p;
	
	public:
	node (int n):data(n) {
		lc=rc=p= NULL;
	}
	
	void set_lc(node* c) {
		lc = c;
	}
	
	void set_rc(node* c) {
		rc = c;
	}
	
	void set_p(node * c) {
		p = c;
	}
	
	node* get_lc() {
		return lc;
	}
	
	node* get_rc() {
		return rc;
	}
	
	node* get_p() {
		return p;
	}
	
	int get_data() {
		return data;
	}
};

class q_node {
	public:
	node * n;
	int x;
	int y;
	
	q_node (node * n, int x, int y) : x(x), y(y), n(n) {}
	void replace_with(q_node qn) {
		this->n = qn.n;
		this->x = qn.x;
		this->y = qn.y;
	}
};

node * get_input_and_build_full();
void print_bfs (node * root);
node * get_input_and_build();
void get_views(node * root, std::vector<q_node> * &ret);
