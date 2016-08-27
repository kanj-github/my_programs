//# include <iostream>
# include <queue>
# include "tree.h"

using namespace std;

node * make_l_child(node * p) {
	int l;
	cin>>l;
	node * child = new node(l);
	child->set_p(p);
	p->set_lc(child);
	return child;
}

node * make_r_child(node * p) {
	int r;
	cin>>r;
	node * child = new node(r);
	child->set_p(p);
	p->set_rc(child);
	return child;
}

node * get_input_and_build_full() {
	int n,r;
	node * root, * temp, * child;
	queue<node *> q;
	cout<<"Enter total number of nodes.\n";
	cin>>n;
	cout<<"Input tree in level order\n";
	cin>>r;
	root = new node(r);
	q.push(root);
	n--;
	while(n>=2) {
		//User has atleat 2 nodes to input
		//Pop from queue, add 2 children to it and push children on queue
		temp = q.front();
		q.pop();
		child = make_l_child(temp);
		q.push(child);
		child = make_r_child(temp);
		q.push(child);
		n-=2;
	}

	temp = q.front();
	q.pop();
	if (n == 2) {
		make_l_child(temp); // don't need the child node
		make_r_child(temp);
	} else if (n == 1) {
		make_l_child(temp);
	}

	return root;
}

void print_bfs (node * root) {
	node * temp, * c;
	queue<node *> q;
	q.push(root);
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		cout<<temp->get_data()<<" ";
		c = temp->get_lc();
		if (c != NULL) q.push(c);
		c = temp->get_rc();
		if (c != NULL) q.push(c);
	}
	cout<<"\n";
}

node * get_input_and_build() {
	int n;
	char c;
	node * ret, *child, * temp;
	queue<node *> q;
	cout<<"Enter root.\n";
	cin>>n;
	ret = temp = new node(n);
	q.push(temp);
	while(!q.empty()) {
		temp = q.front();
		cout<<"Node "<<temp->get_data()<<" has left child? (y/n)\n";
		cin>>c;
		if ('y' == c) {
			cout<<"Enter left child.\n";
			child = make_l_child(temp);
			q.push(child);
		}
		
		cout<<"Node "<<temp->get_data()<<" has right child? (y/n)\n";
		cin>>c;
		if ('y' == c) {
			cout<<"Enter right child.\n";
			child = make_r_child(temp);
			q.push(child);
		}
		q.pop();
	}
	
	return ret;
}