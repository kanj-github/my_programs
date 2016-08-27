# include <iostream>
# include <vector>
 
using namespace std;
 
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
 
node* recurse_it_man(node * p) {
	/*
	cout<<p->id<<" has "<<p->cc<<" children.\n";
	for (int j=0; j<(p->cc); j++) cout<<(p->cv)[j]->id<<" ";
	cout<<"\n";
	*/
	if (p->cc == 0) return p;
	
	node * temp_prev, * temp;
	temp_prev = temp = NULL;
	
	for (int i=0; i<(p->cc); i++) {
		temp = recurse_it_man((p->cv)[i]);
		if (temp != NULL  && temp_prev != NULL) {
			cout<<temp_prev->id<<" + "<<temp->id<<"\n";
			temp = temp_prev = NULL;
		} else if (temp != NULL) temp_prev = temp; // Not necessary to set temp to NULL
	}
	/*
	if (temp_prev == NULL) cout<<p->id<<" returning NULL\n";
	else cout<<p->id<<" returning "<<temp_prev->id<<"\n";
	*/
	
	return temp_prev;
}
 
int main() {

	node * r = build_tree();
	cout<<"\n**********************************************************\n\n";
	recurse_it_man(r);
 
	return 0;
}
