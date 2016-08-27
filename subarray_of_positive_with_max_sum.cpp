#include <vector>
#include <iostream>

using namespace std;

void maxset(vector<int> &A) {
    long sum, max_sum;
    int len, max_len;
    sum = len = max_sum = max_len = 0;
    vector<int> * curr, * max;
    curr = max = NULL;

    for (int i: A) {
        if (i < 0) {
            if ((sum > max_sum) || (sum == max_sum && len > max_len)) {
                max_sum = sum;
                max_len = len;
                max = curr;
            }
            curr = NULL;
            sum = len = 0;

        } else {
            if (curr == NULL) {
                curr = new vector<int>();
            }
            curr->push_back(i);
            sum += i;
            len++;
        }
    }

    if ((sum > max_sum) || (sum == max_sum && len > max_len)) {
        max = curr;
    }

    if (max == NULL) {
        max = new vector<int>();
    }
    for (int i:* max) {
      cout<<i<<" ";
    }
    cout<<"\n";
}

int main (int argc, char **argv) {
  vector<int>  array;
  //1967513926, 1540383426, -1303455736, -521595368
  array.push_back(1967513926);
  array.push_back(1540383426);
  array.push_back(-1303455736);
  array.push_back(-521595368);
  // array.push_back(5);
  // array.push_back(3);
  // array.push_back(-2);
  // array.push_back(-5);
  maxset(array);
}
