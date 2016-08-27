# include <iostream>
# include <iomanip>

using namespace std;

int people, rooms;

char ** plan;
int M; // rows
int N; // columns

void explore_room(int i, int j, int r) {
	if (plan[i][j] == '*') people++;
	plan[i][j] = r;
	if ((j-1 > 0) && (plan[i][j-1] == '-' || plan[i][j-1] == '*'))
		explore_room(i, j-1, r);
	if ((j+1 < N-1) && (plan[i][j+1] == '-' || plan[i][j+1] == '*'))
		explore_room(i, j+1, r);
	if ((i-1 > 0) && (plan[i-1][j] == '-' || plan[i-1][j] == '*'))
		explore_room(i-1, j, r);
	if ((i+1 < M-1) && (plan[i+1][j] == '-' || plan[i+1][j] == '*'))
		explore_room(i+1, j, r);
}

void explore_floor() {
	for (int i=1; i<M-1; i++)
		for (int j=1; j<N-1; j++) {
		if (plan[i][j] == '-' || plan[i][j] == '*') {
			rooms++;
			explore_room(i, j, rooms);
		}
	}
}

int main() {
	int T;
	float ans;
	cin>>T;
	while((T--) != 0) {
		cin>>M>>N;
		plan = new char * [M];
		for (int i=0; i<M; i++) {
			plan[i] = new char [N];
			for (int j=0; j<N; j++) cin>>plan[i][j];
		}
		people = rooms = 0;
		explore_floor();
		ans = (float) people / (float) rooms;
		cout<<fixed<<setprecision(2);
		cout<<ans<<"\n";
		delete plan;
	}
	return 0;
}