# include <cmath>
# include "floyd_warshall.h"

using namespace std;

int main () {
	int N;
	cout<<"Enter number of currencies.\n";
	cin>>N;
	double rate,** weights;
	weights = new double * [N];
	cout<<"Enter the damn table. Don't fuck it up.\n";
	for(int i=0; i<N; i++) {
		weights[i] = new double [N];
		for (int j=0; j<N; j++) {
			cin>>rate;
			weights[i][j] = log2(1/rate);
		}
	}

	double **neg_cycles;
	int **path;

	neg_cycles = new double * [N];
	path = new int * [N];

	for (int i=0; i<N; i++) {
		neg_cycles[i] = new double [N];
		path[i] = new int [N];
	}

	all_pair_shortest(weights, neg_cycles, path, N);

	for (int i=0; i<N; i++) {
		if (neg_cycles[i][i] < 0) {
			//print_path(path, i, i); This method doesn't work for cycles.
			int curr = path[i][i];
			cout<<i;
			while (curr != i) {
				cout<<" -> "<<curr;
				curr=path[curr][i];
			}
			cout<<" -> "<<i<<"\n";
		}
	}
	return 0;
}