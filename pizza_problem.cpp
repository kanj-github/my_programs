# include <iostream>

using namespace std;

int len;
int * a, * b;

int * after_i;

int get_after(int idx) {
  if (after_i[idx] != -1) return after_i[idx];

  int n,max = -1;
  for (int i=0; i<len; i++) {
    if (i == idx) continue;

    if (a[i] >= b[idx]) {
      n = get_after(i) + 1;
      if (n > max) max = n;
    }
  }

  if (max == -1) max = 0;
  after_i[idx] = max;

  return max;
}

int main() {
  cout<<"Enter size\n";
  cin>>len;

  a = new int[len];
  b = new int[len];
  after_i = new int[len];

  int i;
  for (i=0; i<len; i++) {
    after_i[i] = -1;
    cin>>a[i]>>b[i];
  }

  for (i=0; i<len; i++) {
    if (after_i[i] == -1) {
      //after_i[i] =
      get_after(i);
    }
  }

  int max = -1;
  for (i=0; i<len; i++) {
    if (after_i[i] > max) max = after_i[i];
  }

  cout<<"Maximum- "<<max + 1<<"\n";
}
