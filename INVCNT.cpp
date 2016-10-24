#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// http://www.spoj.com/problems/INVCNT/

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

int get_invert_count(vector<int> arr, vector<int> next) {
  vector<int> count(arr.size());

  count[arr.size() - 1] = 0;
  // fill rest of the array with -1 to detect error in logic in the next step
  for (int i = 0; i<arr.size() - 1; i++) {
    count[i] = -1;
  }

  int total = 0;
  for (int i = arr.size()-2; i>=0; i--) {
    if (next[i] != -1) {

      // Just to test for error in logic
      if (count[next[i]] == -1) {
        // logical fuck up
        cout<<"i="<<i<<" next[i]="<<next[i]<<"\n";
        return -1;
      }

      count[i] = count[next[i]] + 1;
      total += count[next[i]] + 1;
    }
  }

  return total;
}

int main (int argc, char ** argv) {
  vector<int> test;
  test.push_back(2);
  test.push_back(3);
  test.push_back(5);
  test.push_back(8);
  test.push_back(6);
  test.push_back(1);
  vector<int> result = get_indexes_of_next_smaller(test);
  cout<<get_invert_count(test, result);
  cout<<"\n";
}
