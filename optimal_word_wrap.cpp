# include <iostream>
# include <climits>
# include <cstdlib>

using namespace std;

void dump (int **s, int n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n-i; j++) cout<<s[i][j]<<" ";
		cout<<"\n";
	}
}

void calc_spaces (int **&space, int *w, int wc, int mx) {
	int i,j;
	space = new int * [wc];
	for (i=0; i<wc; i++) {
		space[i]=new int[wc-i];
		space[i][0] = mx - w[i];
	}
	for (j=1; j<wc; j++) {
		for (i=0; i+j<wc; i++) {
			// calculate space[i][j] here
			// space[i][j] = mx - space taken by j+1 words beginning from i
			space[i][j] = (space[i][j-1] + space[i+j][0] - 1) - mx;
		}
	}
}

void calc_cost (int **&cost, int **space, int *w, int wc) {
	int i,j;
	cost = new int * [wc];
	for (i=0; i<wc; i++) {
		cost[i] = new int[wc-i];
		for (j=0; j+i<wc; j++) {
			if (i+j+1 == wc) cost[i][j] = (space[i][j] >= 0 ? 0:INT_MAX);
			else if (space[i][j] < 0) cost[i][j] = INT_MAX;
			else cost[i][j] = space[i][j] * space[i][j]; // algo in Cormen says cube.
		}
	}
}

void calc_AK47 (int *&AK47, int **cost, int wc) {
	int i,j,min,sum;
	AK47 = new int [wc+1];
	AK47[0] = 0;
	for (i=1; i<=wc; i++) {
		min=INT_MAX;
		for (j=0; j<i; j++) {
			sum = cost[j][i-j-1] == INT_MAX ? INT_MAX : (cost[j][i-j-1] + AK47[j]);
			if (sum < min) {
				min = sum;
				AK47[i] = j;
			}
		}
	}
    //for (i=0;i<=wc;i++) cout<<AK47[i]<<" ";
    //cout<<endl;
}

void fire (int * AK47, int end, int * target) {
	int i, j;
	i = AK47[end];
	// recurse
	if (i != 0) fire(AK47, i, target);
	bool first_word_in_line = false;
	for (; i<end; i++) {
		if (!first_word_in_line) first_word_in_line = true;
		else cout<<" ";
		
		for (j=0; j<target[i]; j++) cout<<"_";
	}
	cout<<"\n";
}

int main(int argc, char * argv[]) {
	
	if (argc<3) {
		cout<<"Usage:\nGive the line's maximum length followed by the length of all words as argument\n";
		return -1;
	}
	
	int max = atoi(argv[1]);
	
	int * input = new int [argc-2];
	for (int i=0; i<argc-2; i++) input[i] = atoi(argv[i+2]);
	
    int **matrix, **lc, *Carray;
	calc_spaces(matrix, input, argc-2, max);
	calc_cost(lc, matrix, input, argc-2);
	calc_AK47(Carray, lc, argc-2);
	fire(Carray, argc-2, input);
	return 0;
}
