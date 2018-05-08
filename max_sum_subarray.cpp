#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int len;
    cin>>len;
    int * array = new int[len];
    for (int i=0; i<len; i++) {
        cin>>array[i];
    }

    int max, curr, start, end, max_start, max_end;
    max = curr = array[0];
    max_start = max_end = end = start = 0;

    for (int j=1; j<len; j++) {
        if (array[j] > curr + array[j]) {
            start = j;
            curr = array[j];
        } else {
            curr += array[j];
        }

        if (curr > max) {
            max = curr;
            max_start = start;
            max_end = j;
            end = j;
        }
    }

    for (int i = max_start; i<=max_end; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

