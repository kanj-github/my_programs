# include <iostream>

using namespace std;

int main () {
	int n = 22;
	int ans = 0;
	
	while (n>0) {
		ans = ans | (n & 1);
		ans<<=1;
		n>>=1;
	}
	ans>>=1;
	cout << "answer is "<<ans<<"\n";
}

