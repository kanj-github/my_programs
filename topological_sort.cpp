# include <iostream>
# include <vector>
# include <forward_list>

using namespace std;

void walk (vector<int> * am, int v, forward_list<int> * q, bool * d) {
	for(auto i:am[v]) {
		if (!d[i]) walk(am, i, q, d);
	}
	d[v] = true;
	q->push_front(v);
}

forward_list<int> * topological_sort (vector<int> * am, int v) {
	forward_list<int> * ret = new forward_list<int>;
	bool done[v];
	int i;
	for (i=0; i<v; i++) done[i] = false;
	
	for (i=0; i<v; i++) {
		if (done[i]) continue;
		walk(am, i, ret, done);
	}
	return ret;
}

int main () {
	int i,j,v,n,a;
	cout<<"Enter no. of vertices.\n";
	cin>>v;
	vector<int> * adj_mat = new vector<int>[v];
	for (i=0; i<v; i++) {
		cout<<"Enter the number of adjacent vertices of vertex "<<i<<"\n";
		cin>>n;
		for (j=0; j<n; j++) {
			cout<<"-->";
			cin>>a;
			if (a<v) adj_mat[i].push_back(a);
			else {
				cout<<"Invalid!!";
				j--;
			}
		}
	}
	
	// dump
	cout<<"***********************\n";
	for (i=0; i<v; i++) {
		cout<<i<<" -> ";
		for (auto it:adj_mat[i]) cout<<it<<" ";
		cout<<"\n";
	}
	cout<<"***********************\n";
	
	forward_list<int> * sorted = topological_sort(adj_mat, v);
	
	for (auto it:*sorted) cout<<it<<" ";
	cout<<"\n";
	
	return 0;
}