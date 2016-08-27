# include <iostream>

using namespace std;

int R, C;

int *** matrix;
// Matrix stores the maximal hand hold count possible moving ahead
// from row k upto the end when the couple occupy columns i & i+j+1 at k.

char ** path;

void init_matrix() {
	matrix = new int ** [C-1];
	for (int i=0; i<C-1; i++) {
		matrix[i] = new int * [C-(i+1)];
		for(int j=0; i+j+1<C; j++) {
			matrix[i][j] = new int[R];
				for(int k=0; k<R; k++) matrix[i][j][k] = -2;
		}
	}
}

void make_path() {
	path = new char * [R];
	for (int i=0; i<R; i++) {
		path[i] = new char[C];
		for (int j=0;j<C;j++) cin>>path[i][j];
	}
}

// In row r, couple occupy column i & i+j+1.
int row(int i, int j, int r) {
	//cout<<"--- "<<i<<" "<<j<<" "<<r<<"\n";
	if (r == R-1) {
		if(j == 0) {
			// holding hands
			matrix[i][j][r] = 1;
			return 1;
		} else {
			// not holding hands but finished the path
			matrix[i][j][r] = 0;
			return 0;
		}
	}
	
	if (matrix[i][j][r] != -2) {
		//cout<<".\n";
		return matrix[i][j][r];
	}
	
	int temp, max = -1;
	// left shift
	if ((i-1)>=0 && path[r+1][i-1] == '.' && path[r+1][i+j]=='.') {
		temp = row(i-1, j, r+1);
		if (temp>max) max=temp;
	}
	
	// right shift
	if ((i+j+2)<C && path[r+1][i+1] == '.' && path[r+1][i+j+2]=='.') {
		temp = row(i+1, j, r+1);
		if (temp>max) max=temp;
	}
	
	// go straight
	if (path[r+1][i] == '.' && path[r+1][i+j+1]=='.') {
		temp = row(i, j, r+1);
		if (temp>max) max=temp;
	}
	
	// split
	if ((i-1)>=0 && (i+j+2)<C && path[r+1][i-1] == '.' && path[r+1][i+j+2]=='.') {
		temp = row(i-1, j+2, r+1);
		if (temp>max) max=temp;
	}
	
	// i straight, j goes right
	if ((i+j+2)<C && path[r+1][i] == '.' && path[r+1][i+j+2]=='.') {
		temp = row(i, j+1, r+1);
		if (temp>max) max=temp;
	}
	
	// j straight, i goes left
	if ((i-1)>=0 && path[r+1][i-1] == '.' && path[r+1][i+j+1]=='.') {
		temp = row(i-1, j+1, r+1);
		if (temp>max) max=temp;
	}
	
	// i straight, j comes left
	if (j>0 && path[r+1][i] == '.' && path[r+1][i+j]=='.') {
		temp = row(i, j-1, r+1);
		if (temp>max) max=temp;
	}
	
	// j straight, i comes right
	if (j>0 && path[r+1][i+1] == '.' && path[r+1][i+j+1]=='.') {
		temp = row(i+1, j-1, r+1);
		if (temp>max) max=temp;
	}
	
	// come together
	if (j>1 && path[r+1][i+1] == '.' && path[r+1][i+j]=='.') {
		temp = row(i+1, j-2, r+1);
		if (temp>max) max=temp;
	}
	
	
	if (max== -1) {
		// This choice is a dead end
		//cout<<"-- "<<i<<" "<<j<<" "<<r<<" -| \n";
		matrix[i][j][r] = -1;
	} else {
		matrix[i][j][r] = max + ((j==0)?1:0);
		//cout<<"-- "<<i<<" "<<j<<" "<<r<<" - "<<matrix[i][j][r]<<"\n";
	}
	
	return matrix[i][j][r];
}

void doit() {
	int temp, max = -1;
	init_matrix();
	for (int i=0;i<C-1;i++) {
		if (path[0][i] == '#') continue;
		for(int j=0; i+j+1<C;j++) {
			if (path[0][i+j+1] == '#') continue;
			temp = row(i,j,0);
			if (temp > max) max = temp;
		}
	}
	if (max == -1) cout<<"Detour\n";
	else cout<<max<<"\n";
}

int main() {
	int T;
	cin>>T;
	while(T>0) {
		cin>>R;
		cin>>C;
		make_path();
		doit();
		T--;
	}
	return 0;
}