# include <iostream>
# include <string>
# include <vector>

# define NUMBER_OF_CHARACTERS 62

using namespace std;

int t[NUMBER_OF_CHARACTERS], curr[NUMBER_OF_CHARACTERS];
int first, last, count, strlen;

int index(char c) {
	if (c>=48 && c<=57) return c-48; // digits
	else if (c>=65 && c<=90) return c-55; // uppercase letters
	else if (c>=97 && c<=122) return c-61; // lowercase letters
	else return -1;
}

bool is_worthy(char c) {
	if (t[index(c)] > 0) return true;
	else return false;
}

bool does_contain() {
	for (int i=0; i<NUMBER_OF_CHARACTERS; i++) {
		if (t[i] > curr[i]) return false;
	}
	
	return true;
}

void increase_last_till_good(const char * str) {
	// Check with 0 increment too
	while (str[last] != '\0') {
		if (does_contain()) break;
		else {
			curr[index(str[++last])]+=1;
		}
		//last++;
	}
}

void solve(string targ, const char * str) {
	for (int i=0; i<NUMBER_OF_CHARACTERS; i++) {
		t[i] = curr[i] = 0;
	}
	last = first = 0;
	count = 0;
	
	for (int i=0; i<targ.length(); i++) {
		t[index(targ.at(i))]+=1;
	}
	
	curr[index(str[last])]+=1; //add the first character in curr
	
	while (strlen-first >= targ.length()) {
		increase_last_till_good(str);
		count+=(strlen-last); //strlen-last substrings beginning from first are good
		// Remove current first from curr and increment first
		curr[index(str[first])]-=1;
		first++;
	}
}

int main() {
	int T,Q;
	string s,t;
	cin>>T;
	vector<int> ans;
	while (T>=1) {
		cin>>s;
		strlen=s.length();
		cin>>Q;
		while (Q>=1) {
			cin>>t;
			solve(t,s.c_str());
			ans.push_back(count);
			Q--;
		}
		T--;
	}
	
	for (auto it:ans) cout<<it<<"\n";
	
	return 0;
}
