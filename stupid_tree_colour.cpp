# include <iostream>
# include <vector>
//# include <set> Don't use set, use an array of size = no. of nodes

using namespace std;

int ans, len;

vector<int> * adj;

void increment() {
	ans++;
	if (ans == 10000007) ans = 0;
};

class choices {
	int * ch;
	int c;
	int size;
	
	public:
	choices(int n) : size(n) {
		c=0;
		ch = new int[n];
		for (int i=0; i<n; i++) ch[i]=0;
	}
	
	void init() {
		for (auto it:adj[0]) {
			ch[it]=1; // Children of n are now available
			c++;
		}
	}
	
	bool empty() {
		if (c==0) return true;
		else return false;
	}
	
	void make_choice(int n) {
		for (auto it:adj[n]) {
			ch[it]=1; // Children of n are now available
			c++;
		}
		ch[n] = 0; // n is no more available
		c--;
	}
	
	void undo_choice(int n){
		for (auto it:adj[n]) {
			ch[it]=0; // Children of n are no more available
			c--;
		}
		ch[n] = 1; // n is now available
		c++;
	}
	
	int is_available(int n) {
		return ch[n];
	}
	
	void dump() {
		for (int i=0; i<size; i++) cout<<ch[i]<<"  ";
		cout<<"\n";
	}
};

void go_crazy(choices& c) {
	/*
	cout<<"going crazy with ";
	c.dump();*/
	
	if (c.empty()) {
		increment();
		return;
	}
	
	for (int i=0; i<len; i++) {
		if (!c.is_available(i)) continue;
		
		c.make_choice(i);
		/*
		cout<<"start going crazy with ";
	    c.dump();*/
		
		go_crazy(c);
		
		c.undo_choice(i);
		/*
		cout<<"restore back to ";
		c.dump();*/

	}
	/*cout<<"done going crazy with ";
	c.dump();*/
}

int main() {
	int T,N,a,b,i;
	cin>>T;
	
	while (T>=1) {
		ans = 0;
		cin>>N;
		len=N;
		adj = new vector<int>[N];
		for (i=0; i<N-1; i++) {
			cin>>a;
			cin>>b;
			adj[a-1].push_back(b-1);
		}
		
		choices begin = choices(N);

		begin.init();

		go_crazy(begin);

		cout<<ans<<"\n";
		T--;
	}
	return 0;
}
