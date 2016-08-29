#include<iostream>

using namespace std;

int max_, max_start, max_end, i, j;
int * array, len;

void expand_zeroes() {
    int x = i;
    while(x<len) {
        if (array[x] == 1) {
            break;
        }
        x++;
    }
    j = x-1;

    if (j-i+1 > max_) {
        max_ = j-i+1;
        max_start = i;
        max_end = j;
    }
}

void expand_including_ones() {
    int gain = j-i+1;
    j++;
    while(gain >= 0 && j < len) {
        if (array[j] == 0) {
            gain++;
        } else {
            gain--;
        }

        if (gain > max_) {
            max_ = gain;
            max_start = i;
            max_end = j;
        }
        j++;
    }
}

int main(int argc, char ** argv) {
    cin>>len;
    array = new int[len];
    for (int i=0; i<len; i++) {
        cin>>array[i];
    }

    max_ = 0;
    i = j = max_start = max_end = -1;
    int index = 0;
    while (index < len && array[index++] == 1);

    if (index == len) {
        cout<<"no solution";
    } else {
        i = j = index - 1;
        while (j < len) {
            expand_zeroes();
            expand_including_ones();
            // when expand_including_ones() returns either j == len or j is index of 1
            // in latter case set i = j = index of next 0
            if (j < len) {
                while (j<len && array[j] == 1) {
                    j++;
                };
                if (j < len) {
                    i = j;
                }
            }
        }
    }

    cout<<max_start<<" "<<max_end<<"\n";
    
    // Kadane's method
    index = 0;
    while (index < len && array[index] == 1) {
        index++;
    }
    if (index == len) {
        cout<<"no solution";
    } else {
        int st, en, curr;
        curr = max_ = 1;
        st = index;
        for (int i = index+1; i<len; i++) {
            if (array[i] == 0 && curr < 0) {
                st = i;
                curr = 1;
            } else if (array[i] == 0) {
                curr++;
            } else {
                curr--;
            }

            if (curr > max_) {
                max_ = curr;
                max_start = st;
                max_end = i;
            }
        }
        cout<<max_start<<" "<<max_end<<"\n";
    }

    return 0;
}

