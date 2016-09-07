#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

vector<int> func(vector<int> &A) {
  vector<int> ret;
  int i = 0;
  for (; i< A.size(); i++) {
    ret.push_back(-1);
  }

  stack<int> st;
  int p;
  for (i = 0; i<A.size(); i++) {
    if (st.empty()) {
      st.push(i);
    } else if (A[i] > A[st.top()]) {
      ret[i] = st.top();
      st.push(i);
    } else if (A[i] == A[st.top()]) {
      ret[i] = ret[st.top()];
      st.push(i);
    } else {
      while(!st.empty() && A[st.top()] >= A[i]) {
        p = st.top();
        if (ret[p] == -1 || (i-p) < (p-ret[p])) {
          ret[p] = i;
        }
        st.pop();
      }
      if (!st.empty()) {
        ret[i] = st.top();
      }
      st.push(i);
    }
  }
  return ret;
}

int main(int argc, char ** argv) {
  vector<int> arr;
  for (int i = 1; i<argc; i++) {
    arr.push_back(atoi(argv[i]));
  }

  vector<int> solution = func(arr);
  for (int i: solution) {
    cout<<i<<"\n";
  }
  return 0;
}
