#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void func(vector<vector<int>> &A) {
  int size = A.size(), temp;
  for (int i = 0; i<size/2; i++) {
    for (int j = 0; j < size-(2*i)-1; j++) {
      //cout<<"("<<i<<","<<i+j<<"), ("<<i+j<<","<<size-i-1<<"), ("<<size-i-1<<","<<size-i-j-1<<"), ("<<size-i-j-1<<","<<i<<")\n";
      temp = A[size-i-j-1][i];
      A[size-i-j-1][i] = A[size-i-1][size-i-j-1];
      A[size-i-1][size-i-j-1] = A[i+j][size-i-1];
      A[i+j][size-i-1] = A[i][i+j];
      A[i][i+j] = temp;
    }
  }
}

int main(int argc, char ** argv) {
  if (argc < 3) {
    cout<<"fuck you\n";
    return 1;
  }

  vector<vector<int>> mat;
  int size = atoi(argv[1]);

  int index = 2;

  for (int i = 0; i<size; i++) {
    vector<int> * arr = new vector<int>;
    for (int j = 0; j<size; j++) {
      arr->push_back(atoi(argv[index++]));
    }
    mat.push_back(*arr);
  }

  for (int i = 0; i<size; i++) {
    for (int j = 0; j<size; j++) {
      cout<<mat[i][j]<<"\t";
    }
    cout<<"\n----------------------------\n";
  }

  func(mat);

  for (int i = 0; i<size; i++) {
    for (int j = 0; j<size; j++) {
      cout<<mat[i][j]<<"\t";
    }
    cout<<"\n";
  }

  return 0;
}
