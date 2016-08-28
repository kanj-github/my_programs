#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int count_digits(int x) {
    int ret = 0;

    while (true) {
        x /= 10;
        ret++;
        if (x==0) break;
    }
    return ret;
}

bool comp(int a, int b) {
    int a_digits = count_digits(a);
    cout<<a<<" has "<<a_digits<<" digits\n";
    int b_digits = count_digits(b);
    double ab, ba;
    ab = a * pow(10, b_digits) + b;
    ba = b * pow(10, a_digits) + a;
    cout<<"ab= "<<ab<<" ba= "<<ba<<"\n";
    return (ab > ba); 
}

char * itoa (int x) {
    int len = count_digits(x) + 1;
    char * ret = new char[len];
    ret[len - 1] = '\0';
    int rem;
    for (int i = len-2; i>=0; i--) {
        rem = x%10;
        ret[i] = (48+rem);
        x/=10;
    }
    cout<<"itoa - "<<ret<<"\n";
    return ret;
}

string largestNumber(const vector<int> &A) {
    vector<int> array = vector<int>(A);
    sort(array.begin(), array.end(), comp);
    string ret;
    for (int i: array) {
        cout<<"append "<<i<<"\n";
        ret += itoa(i);
    }
    return ret;
}

int main(int argc, char ** argv) {
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(89);
    string out = largestNumber(arr);
    cout<<"out is "<<out<<"\n";
    return 0;
}

