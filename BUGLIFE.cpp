# include <iostream>
# include <vector>

using namespace std;

// Try to solve http://www.spoj.com/problems/BUGLIFE/

int bugs, edges;
vector<vector<int>> graph;
vector<int> colour_array; // 0 - unknown, 1 - one, 2 - other

// return true if already coloured.
//                all edges can be coloured with the other colour
// return false if already coloured with other
//                 all edges can not be coloured with the other colour
bool bfs_colour(int b, int colour) {
	if (colour_array[b] != 0) {
		return colour_array[b] == colour;
	} else {
		colour_array[b] = colour;
		int other_colour = (colour == 1) ? 2 : 1;
		for (const auto& i : graph[b]) {
			if (!bfs_colour(i, other_colour)) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int tests, x, y;
	cin>>tests;
	for (int t = 1; t <= tests; t++) {
		cin>>bugs>>edges;
		graph = vector<vector<int>>(bugs, vector<int>());
		colour_array = vector<int>(bugs, 0);
		for (int i = 0; i<edges; i++) {
			cin>>x>>y;
			graph[x-1].push_back(y-1);
			graph[y-1].push_back(x-1);
		}

		cout<<"Scenario #"<<t<<":\n";
		bool suspicion = false;
		for (int i = 0; i<bugs; i++) {
			if (colour_array[i] == 0 && !bfs_colour(i, 1)) {
				suspicion = true;
				break;
			}
		}
		if (suspicion) {
			cout<<"Suspicious bugs found!\n";
		} else {
			cout<<"No suspicious bugs found!\n";
		}
	}
	return 0;
}
