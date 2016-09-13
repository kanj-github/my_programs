#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

# define ABS_DIFF(A, B) (((A-B) > 0)? (A-B) : (B-A))

int closest (vector<int> A, int B) {
  sort(A.begin(), A.end());
  int i, k, sum, temp, diff;
  diff = -1;
  i = 0;
  k = A.size()-1;
  while(k > i+1) {
    for (int x = i+1; x < k; x++) {
      // Update sum
      temp = A[i] + A[k] + A[x];
      cout<<i<<" "<<x<<" "<<k<<"\n";
      int diff_ = ABS_DIFF(B, temp);
      if (diff > -1) {
        if (diff_ < diff) {
          sum = temp;
          diff = diff_;
        }
      } else {
        sum = temp;
        diff = diff_;
      }

      if (temp > B) {
        k--;
        break;
      } else if (temp == B) {
        //break;
        return B;
      }
    }

    if (temp < B) {
      i++;
    } else if (temp == B) {
      //break;
      return B;
    }
  }

  return sum;
}

int main (int argc, char ** argv) {
  if (argc < 3) {
    cout<<"fuck you\n";
    return 1;
  }

  vector<int> arr;
  int target = atoi(argv[1]);

  for (int i = 2; i<argc; i++) {
    arr.push_back(atoi(argv[i]));
  }

  cout<<closest(arr, target)<<"\n";
  return 0;
}
