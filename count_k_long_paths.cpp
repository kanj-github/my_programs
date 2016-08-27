# include <iostream>
# include <vector>

using namespace std;

int * data;
vector<int> * adj;

void make_adj_list(int **mat, int d) {
	adj = new vector<int>[d];
	for (int i=0; i<d; i++) for(int j=0; j<d; j++)
		if (mat[i][j] == 1) adj[i].push_back(j);
}

void go_crazy(int k, int d) {
	int * temp;
	for (int i=0; i<k; i++) {
		temp = new int[d];
		for (int i=0; i<d; i++) temp[i] = 0;
		
		for (int j=0; j<d; j++) {
			if (data[j] != 0) {
				for (auto it:adj[j]) temp[it] += data[j];
			}
		}
		data = temp;
	}
}

int main() {
	int dim, ** m, s, d, k;
	cout<<"Enter the number of vertices\n";
	cin>>dim;
	m = new int * [dim];
	data = new int[dim];
	for (int i=0; i<dim; i++) {
		data[i] = 0;
		m[i] = new int[dim];
		cout<<"Enter row "<<i<<"\n";
		for (int j=0; j<dim; j++) cin>>m[i][j];
	}
	
	make_adj_list(m, dim);
	
	cout<<"Enter S, D & k. Don't fuck up.\n";
	cin>>s>>d>>k;
	data[s] = 1;
	
	go_crazy(k, dim);
	
	cout<<"-----> "<<data[d]<<"\n";
	
	return 0;
}