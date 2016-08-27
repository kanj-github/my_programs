# include "floyd_warshall.h"

using namespace std;

// caller should allocate memory at wm, sol & path (if needed)
// wm = weight matrix
// sol = weight of shortest paths
// path[i][j]=n, means to go from i to j move to n
	
//template <typename WT>
//	void all_pair_shortest(WT **wm, WT **sol, int **path, int v) {
void all_pair_shortest(double **wm, double **sol, int **path, int v) {
	int i, j, k;
	
	bool ret_path = (NULL != path);
	
	// initialise
	for(i=0; i<v; i++) for (j=0; j<v; j++) {
		sol[i][j] = wm[i][j];
		if (ret_path) path[i][j] = j;
	}
	
	for(k=0; k<v; k++) for(i=0; i<v; i++) for (j=0; j<v; j++) {
		if (sol[i][j] > sol[i][k] + wm[k][j]) {
			sol[i][j] = sol[i][k] + wm[k][j];
			if (ret_path) path[i][j] = path[i][k];
		}
	}
}

// print non-cyclic path from i to j
void print_path (int ** path, int i, int j) {
	cout<<i<<" -> ";
	print_path_recursion(path, i, j);
}

void print_path_recursion (int ** path, int i, int j) {
	if (i == j) cout<<j<<"\n";
	else {
		cout<<path[i][j]<<" -> ";
		print_path_recursion(path, path[i][j], j);
	}
}