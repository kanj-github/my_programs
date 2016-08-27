# include <iostream>
# include <vector>

using namespace std;

class t_node {
	public:
	int x;
	t_node * l;
	t_node * r;

	t_node(int x):x(x) {
		l = NULL;
		r = NULL;
	}
	
	t_node() {
		x = -1;
		l = NULL;
		r = NULL;
	}
	void die() {
		if (l != NULL) {
			l->die();
			delete(l);
		}
		if (r != NULL) {
			r->die();
			delete(r);
		}
	}
};

class data_tree {
	t_node root;
	int len;
	
	public:
	
	data_tree(int v) : len(v) {
		//root = t_node();
	}
	
	int search(int * arr) {
		t_node * cur = &root;
		int i;
		for (i=0; i<len; i++) {
			if (arr[i] == 1) cur = cur->r;
			else cur = cur->l;
			if (cur == NULL) break;
		}
		if (i == len) return cur->x;
		else return -1;
	}
	
	void save(int * arr, int val) {
		int i,flag=0;
		t_node * cur = &root;
		// traverse the path that already exists
		for (i=0; i<len; i++) {
			if (arr[i] == 1) {
				if ((cur->r) == NULL) break;
				else cur = cur->r;
			} else {
				if ((cur->l) == NULL) break;
				else cur = cur->l;
			}
		}
		// make new path except for the leaf
		for (; i<len-1; i++) {
			if (arr[i] == 1) {
				cur->r = new t_node(1);
				cur = cur->r;
			} else {
				cur->l = new t_node(0);
				cur = cur->l;
			}
		}
		// add leaf with value
		if (arr[len-1] == 1) cur->r = new t_node(val);
		else cur->l = new t_node(val);
	}
	
	//~data_tree() {
	//	root.r = root.l = NULL;
	//}
	void set_null() {
		//root.r = root.l = NULL;
		//delete(root.r);
		//delete(root.l);
		root.die();
	}
};

int * w;
vector<int> * adj;
data_tree * dt;
int nv;

int choose(int * choices) {
	int max = 0, new_ch[nv];
	
	for (int i=0; i<nv; i++) {
		if (choices[i] == 1) {
			// make this choice
			for (int j=0; j<nv; j++) new_ch[j]=choices[j];
			new_ch[i] = 0;
			for(auto n:adj[i]) new_ch[n] = 0;
			int saved = dt->search(new_ch);
			if (saved != -1 && w[i]+saved > max) max = w[i]+saved;
			else if (saved == -1) {
				int calc = choose(new_ch);
				if (w[i]+calc > max) max = w[i]+calc;
			}
		}
	}
	// Save data for later use
	dt->save(choices, max);
	return max;
}

void make_adj(int v, int e) {
	adj = new vector<int> [v];
	int a,b;
	for (int i=0;i<e; i++) {
		cin>>a;
		cin>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
}

void make_w(int v) {
	w = new int[v];
	for (int i=0;i<v;i++) cin>>w[i];
}

int main () {
	int T,N,K;
	int * c;
	
	cin>>T;
	while (T>0) {
		cin>>N;
		cin>>K;
		nv = N;
		make_w(N);
		make_adj(N,K);
		c = new int[N];
		for (int i=0; i<N; i++) c[i] = 1;
		dt = new data_tree(N);
		cout<<choose(c)<<"\n";
		dt->set_null();
		//delete(c);
		//delete(w);
		//delete(dt);
		//delete(adj);
		T--;
	}
	return 0;
}
