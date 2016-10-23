#include <iostream>

using namespace std;

// http://www.spoj.com/problems/BUGLIFE/

/*
  Update:- Problem can't be solved by detecting cycle in graph.
  Correct solution uses n^2 space and n time.
  https://github.com/srikk595/Spoj-Problems/blob/master/BUGLIFE-6859699-src.cpp
*/

// Return set representative node of node a
int get_set_rep(int * set_array, int a) {
  while(set_array[a] != -1) {
    a = set_array[a];
  }
  return a;
}

int main(int argc, char ** argv) {
  int S;
  cin>>S;

  int * set_array, x, y, a, b, rep_a, rep_b, scenario_count = 0;
  bool cycle_detected;
  while (S > 0) {
    scenario_count ++;
    cin>>x>>y;
    // x is the number of bugs (nodes)
    // y is the number of interactions (edges)
    set_array = new int[x];

    // initialise all nodes to be in separate set.
    for (int i = 0; i<x; i++) {
      set_array[i] = -1;
    }

    cycle_detected = false;

    // Read y lines of edges
    while (y>0) {
      cin>>a>>b;
      // a and b are 1 to (number of nodes)
      a--;
      b--;
      if (!cycle_detected) {
        rep_a = get_set_rep(set_array, a);
        rep_b = get_set_rep(set_array, b);
        if (rep_a == rep_b) {
          cycle_detected = true;
        } else {
          // Merge sets of a & b
          set_array[rep_a] = rep_b;
        }
      }
      y--;
    }

    // Show output
    cout<<"Scenario #"<<scenario_count<<":\n";
    if (cycle_detected) {
      cout<<"Suspicious bugs found!\n";
    } else {
      cout<<"No suspicious bugs found!\n";
    }

    S--;
  }
}
