#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string cache[8];
int ascii_start = 48;

string multiply_string_by_n(string s, int n) {
	string result = "";
	int carry = 0;
	for (int i = s.length() - 1; i>=0; i--) {
		int val = ((s.at(i) - ascii_start) * n) + carry;
		char c = (val%10) + ascii_start;
		carry = val / 10;
		result.insert(result.begin(), c);
	}
	
	if (carry > 0) {
		char d = carry + ascii_start;
		result.insert(result.begin(), d);
	}

	cache[n-2] = result;
	return result;
}

string add_strings(const string a, const string b) {
	if (a.compare("") == 0) {
		return b;
	} else if (b.compare("") == 0) {
		return a;
	}

	string result="";

	int pos = 0, carry = 0, a_last = a.length() - 1, b_last = b.length() - 1;
	while(pos <= a_last || pos <= b_last) {
		int sum = carry;
		if (a_last - pos >= 0) {
			sum+=(a.at(a_last - pos) - ascii_start);
		}

		if (b_last - pos >= 0) {
			sum+=(b.at(b_last - pos) - ascii_start);
		}

		char c = (sum%10) + ascii_start;
		result.insert(result.begin(), c);

		carry = sum/10;
		pos++;
	}

	if (carry > 0) {
		char d = carry + ascii_start;
		result.insert(result.begin(), d);
	}

	return result;
}

string multiply(string A, string B) {
	// Initilaise multiplication cache
	for (int i = 0; i<8; i++) {
    	cache[i] = "";
    }

    string top, bottom;

    if (B.length() > A.length()) {
    	top = B;
    	bottom = A;
    } else {
    	top = A;
    	bottom = B;
    }

    int top_len = top.length();
    int bottom_len = bottom.length();

    string sum = "";
    for (int i = 0; i<bottom_len; i++) {
    	int n = bottom.at(bottom_len - i - 1) - ascii_start;
    	string value;
    	if (n == 0) {
    		continue;
    	} else if (n == 1) {
    		value = top;
    	} else if (cache[n - 2].compare("") != 0) {
    		// found in cache
    		value = cache[n - 2];
    	} else {
    		value = multiply_string_by_n(top, n);
    	}

    	for (int j = 0; j<i; j++) {
    		value.append("0");
    	}

    	sum = add_strings(sum, value);
    }

    if (sum.compare("") == 0) {
    	return "0";
    } else {
    	// Remove 0s from beginning if any
	    while(sum.at(0) == '0') {
	    	sum.erase(0, 1);
	    }
    	return sum;
    }
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout<<"Fuck you\n";
		return 1;
	}

	string a = string(argv[1]);
	string b = string(argv[2]);

	//cout<<multiply_string_by_n(a, 7)<<"\n";
	//cout<<multiply_string_by_n(b, 1)<<"\n";

	//cout<<add_strings(a, b)<<"\n";

	cout<<multiply(a, b)<<"\n";

	return 0;
}
