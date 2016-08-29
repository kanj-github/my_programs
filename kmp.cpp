#include <iostream>
#include <string>

using namespace std;

int strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (needle.length() == 0 || haystack.length() == 0) {
        return -1;
    } else if (needle.length() > haystack.length()) {
        return -1;
    } else {
        int * next = new int[needle.length()];
        // Make KMP next array
        int q = 0;
        next[0] = 0;
        for (int i = 1; i<needle.length(); i++) {
            while (q > 0 && needle.at(q) != needle.at(i)) {
                q = next[q-1];
            }
            if (needle.at(q) == needle.at(i)) {
                q++;
            }
            next[i] = q;
        }
        //for (int i=0; i<needle.length(); i++) {
        //    cout<<next[i]<<"\t";
        //}
        //cout<<"\n";

        // Pattern matching step
        q = 0;
        for (int i = 0; i<haystack.length(); i++) {
            while (q>0 && needle.at(q) != haystack.at(i)) {
                q = next[q-1];
            }
            if (needle.at(q) == haystack.at(i)) {
                q++;
                if (q == needle.length()) {
                    return i - needle.length() + 1;
                }
            }
        }
        return -1;
    }
}

int main(int argc, char ** argv) {
  cout<<strStr(
    "baaaabbaaabbaabbaaaaaabaaaaaaabbbbaaaabbaabbababbbaaaabababaabaabaabaabbabbabbbabbbaaabaaaabaaaaaab",
    "aabbbababbbaabaaabbaaabbbbbabababaabaaabbbbaaaaaa"
  );
}
