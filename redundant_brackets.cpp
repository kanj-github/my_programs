#include <iostream>
#include <stack>
#include <string>

using namespace std;

int braces(string A) {
    stack<char> st;
    char c;
    int count;
    for (int i = 0; i<A.length(); i++) {
        c = A.at(i);
        if (')' == c) {
            cout<<i<<" - close\n";
            count = 0;
            while (st.top() != '(') {
                count++;
                cout<<"pop "<<st.top()<<"\n";
                st.pop();
            }
            if (count < 2) {
                return 1;
            } else {
                // pop the ( as well
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    return 0;
}

int main (int argc, char ** argv) {
  cout<<braces("((a+b))")<<"\n";
  return 0;
}
