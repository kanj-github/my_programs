//# include <vector>
# include <queue>
//# include <iostream>
# include "tree.h"

using namespace std;

void check_visibility (q_node qn, vector<q_node> * v) {
	// Top view. Only the first node with a particular x value needs to be considered
	if (v[0].size() == qn.x) {
		v[0].push_back(qn);
	}
	
	// Right view
	if (v[1].size() > qn.y) {
		// Something already visible at this level, compare x value
		// (Due to BFS order, node coming later will always have higher x
		// but still compare and print logs)
		if (v[1].at(qn.y).x < qn.x) v[1].at(qn.y).replace_with(qn);
		else cout<<"The impossible has happenned - 1\n";
	} else if (v[1].size() == qn.y) {
		// Add a new level
		v[1].push_back(qn);
	} else cout<<"The impossible has happenned - 2\n";
	
	// Bottom view
	if (v[2].size() > qn.x) {
		// Something already visible at this level, compare y value
		// (Due to BFS order, node coming later will always have higher y
		// but still compare and print logs)
		if (v[2].at(qn.x).y < qn.y) v[2].at(qn.x).replace_with(qn);
		else cout<<"The impossible has happenned - 3\n";
	} else if (v[2].size() == qn.x) {
		// Add a new level
		v[2].push_back(qn);
	} else cout<<"The impossible has happenned - 4\n";
	
	// Left view. Only the first node with a particular y value needs to be considered
	if (v[3].size() == qn.y) {
		v[3].push_back(qn);
	}
}

// Return an array of 4 vectors. 0 - top, 1 - right, 2 - bottom & 3 - left

void get_views(node * root, vector<q_node> * &ret) {
	ret = new vector<q_node>[4];
	queue<q_node> q;
	node * temp;
	int level = 0, xc =0;
	q_node qn = q_node(root, 0, 0);
	q.push(qn);
	
	while (!q.empty()) {
		qn = q.front();
		if (qn.y > level) {
			// Reset x counter because we will process nodes at a lower level
			level = qn.y;
			xc = 0;
		}
		check_visibility(qn, ret);
		temp = qn.n->get_lc();
		if (temp != NULL) {
			q.push(q_node(temp, xc, level+1));
			xc++;
		}
		temp = qn.n->get_rc();
		if (temp != NULL) {
			q.push(q_node(temp, xc, level+1));
			xc++;
		}
		q.pop();
	}
}
