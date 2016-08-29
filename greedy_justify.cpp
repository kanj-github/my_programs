#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
    vector<string> ret;
    int i = 0; // index of string in A which has to go in the next line
    while(true) {
        int words = 0;
        int chars = 0;
        while (i + words < A.size()) {
            if (chars + A[i+words].length() + words <= B) {
                chars += A[i+words].length();
                words++;
            } else {
                break;
            }
        }

        string str;
        //Check whether justify is required
        if (i + words == A.size()) {
            // Last word has been added
            int x = i;
            for (; x < A.size() - 1; x++) {
                str.append(A[x]).append(" ");
            }
            str.append(A[x]);
            ret.push_back(str);
            break;
        } else {
            int diff = B - chars;
            if (words == 1) {
                // only one word fits in this line
                str.append(A[i]);
                for (int y=0; y<diff; y++) {
                       str.append(" ");
                }
            } else {
                int quo = diff / (words - 1);
                int rem = diff % (words - 1);
                for (int x = 0; x < words - 1; x++) {
                    str.append(A[i+x]);
                    for (int y=0; y<quo; y++) {
                       str.append(" ");
                    }
                    if (rem) {
                        str.append(" ");
                        rem--;
                    }
                }
                str.append(A[i+words-1]);
            }
            i+=words;
            ret.push_back(str);
        }
    }
    return ret;
}

int main (int argc, char ** argv) {
    vector<string> text;
    text.push_back("am");
    text.push_back("fasgoprn");
    text.push_back("lvqsrjylg");
    text.push_back("rzuslwan");
    text.push_back("xlaui");
    text.push_back("tnzegzuzn");
    text.push_back("kuiwdc");
    text.push_back("fofjkkkm");
    text.push_back("ssqjig");
    text.push_back("tcmejefj");
    text.push_back("uixgzm");
    text.push_back("lyuxeaxsg");
    text.push_back("iqiyip");
    text.push_back("msv");
    text.push_back("uurcazjc");
    text.push_back("earsrvrq");
    text.push_back("qlq");
    text.push_back("lxrtzkjpg");
    text.push_back("jkxymjus");
    text.push_back("mvornwza");
    text.push_back("zty");
    text.push_back("q");
    text.push_back("nsecqphjy");
    vector<string> justified = fullJustify(text, 14);
    for (string s:justified) {
        cout<<s<<"\n";
    }
}
