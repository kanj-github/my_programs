# include <iostream>
# include <vector>

using namespace std;

int ans;
//int counter;

class node {
	public:
	
	static int counter;
	int id, cc;
	node ** cv;
	
	
	node() {
		id=counter++;
		cout<<"generating "<<id<<"\n";
		cc=0;
		cv=NULL;
	}
	
	void add_children(int);
	
	void add_children_to_v (vector<node *> &v) {
		for(int i=0; i<cc; i++) {
			v.push_back(cv[i]);
		}
	}
};

void node::add_children(int n) {
	if (n==0 || cc!=0) {
		cout<<id<<" you fucked up\n";
		return;
	}
	cc = n;
	cv = new node * [n];
	for (int i=0; i<n; i++) cv[i] = new node();
}

int node::counter = 0;

node * build_tree() {
	int n;
	vector<node *> vec;
	node * curr;
	cout<<"Enter no. of root's children\n";
	cin>>n;
	node * root = new node();
	root->add_children(n);
	root->add_children_to_v(vec);
	
	while(!vec.empty()) {
		curr = vec.back();
		vec.pop_back();
		cout<<"Enter the number of children of "<<curr->id<<"\n";
		cin>>n;
		if (n!=0) {
			curr->add_children(n);
			curr->add_children_to_v(vec);
		}
	}
	return root;
}

void dfs_it_man(node * p, int d, int s) {
	/*
	cout<<p->id<<" has "<<p->cc<<" children.\n";
	for (int j=0; j<(p->cc); j++) cout<<(p->cv)[j]->id<<" ";
	cout<<"\n";
	*/
	if (d+s-1 > ans) ans = d+s-1;
	for (int i=0; i<(p->cc); i++) dfs_it_man((p->cv)[i], d+1, (p->cc));
}

int main() {
	ans=0;
	
	node * r = build_tree();
	dfs_it_man(r, 0, 0);
	
	cout<<ans<<"\n";
	
	return 0;
}