#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
// https://www.interviewbit.com/problems/allocate-books/

int min_req(vector<int> &A, int pages) {
  int ret = 0, sum = 0;
  for (int i: A) {
    if (i > pages) {
      return -1;
    } else if (sum + i > pages) {
      ret++;
      sum = i;
    } else {
      sum +=i;
    }
  }
  //cout<<ret+1<<" recepients required for "<<pages<<"\n";
  return ret+1;
}

int func(vector<int> &A, int B) {
  if (A.size() < B) {
    return -1;
  }

  int max = 0, min = 0, mid, req;
  for (int x:A) {
    max+=x;
    if (x > min) {
      min = x;
    }
  }

  while (max >= min) {
    mid = min + (max - min) / 2;
    //cout<<"Trying for "<<min<<" -- "<<max<<" = "<<mid<<"\n";
    req = min_req(A, mid);
    if (req == -1 || req > B) {
      min = mid+1;
    } else {
      max = mid-1;
    }
  }

  return min;
}

int main(int argc, char ** argv) {
  if (argc < 3) {
    cout<<"fuck you\n";
    return 1;
  }

  vector<int> arr;
  int recepients = atoi(argv[1]);

  for (int i = 2; i<argc; i++) {
    arr.push_back(atoi(argv[i]));
  }
  //cout<<min_req(arr, recepients)<<"\n";
  cout<<func(arr, recepients)<<"\n";
  return 0;
}
