# include <iostream>
# include <iomanip>
# include <vector>

using namespace std;

// Try to solve http://www.spoj.com/problems/HFLOOR/

vector<vector<char>> floor;
int rows, columns;
int people;

void check_room(int x, int y) {
	if (floor[x][y] == '*') {
		people++;
	}
	floor[x][y] = '0';

	// Boundry rows and columns are # walls
	if (y-1 > 0 && !(floor[x][y-1] == '#' || floor[x][y-1] == '0')) {
		check_room(x, y-1);
	}
	if (x-1 > 0 && !(floor[x-1][y] == '#' || floor[x-1][y] == '0')) {
		check_room(x-1, y);
	}
	if (y+1 < columns-1 && !(floor[x][y+1] == '#' || floor[x][y+1] == '0')) {
		check_room(x, y+1);
	}
	if (x+1 < rows-1 && !(floor[x+1][y] == '#' || floor[x+1][y] == '0')) {
		check_room(x+1, y);
	}
}

float calculate() {
	people = 0;
	int rooms = 0;
	for (int i = 1; i<rows-1; i++) {
		for (int j = 1; j<columns-1; j++) {
			if (floor[i][j] != '#' && floor[i][j] != '0') {
				rooms++;
				check_room(i, j);
			}
		}
	}
	return (float) people/(float) rooms;
}

int main() {
	int floors;
	char c;
	cin>>floors;
	for (; floors > 0; floors--) {
		cin>>rows>>columns;
		floor = vector<vector<char>>(rows, vector<char>());
		for (int i=0; i<rows; i++) {
			for (int j=0; j<columns; j++) {
				cin>>c;
				floor[i].push_back(c);
			}
		}
		cout<<fixed<<setprecision(2)<<calculate()<<"\n";
	}
	return 0;
}
