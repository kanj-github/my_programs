#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> get_indexes_of_next_smaller(vector<int> arr) {
  vector<int> next_smallers(arr.size());
  stack<int> stk;
  for (int i=0; i<arr.size(); i++) {
    if (stk.empty()) {
      stk.push(i);
    } else {
      if (arr[i] >= arr[stk.top()]) {
        stk.push(i);
      } else {
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
          next_smallers[stk.top()] = i;
          stk.pop();
        }
        stk.push(i);
      }
    }
  }

  while (!stk.empty()) {
    next_smallers[stk.top()] = -1;
    stk.pop();
  }

  return next_smallers;
}

// Shit logic. Doesn't work
int get_invert_count(vector<int> arr, vector<int> next) {
  vector<int> count(arr.size());
  count[arr.size() - 1] = 0;

  int total = 0;
  for (int i = arr.size()-2; i>=0; i--) {
    if (next[i] != -1) {
      count[i] = count[next[i]] + 1;
      total += count[next[i]] + 1;
    }
  }

  return total;
}

int main() {
	int tests, size;
	cin>>tests;
	while(tests > 0) {
		cin>>size;
		vector<int> array(size);
		for (int i=0; i<size; i++) {
			cin>>array[i];
		}

		vector<int> nexts = get_indexes_of_next_smaller(array);
		cout<<get_invert_count(array, nexts)<<"\n";

		tests--;
	}
	return 0;
}
