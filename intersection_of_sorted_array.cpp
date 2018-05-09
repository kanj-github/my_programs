# include <iostream>
# include <vector>

using namespace std;

// Return intersection of arrays sorted in ascending order
// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
vector<int> intersect(vector<int> &A, vector<int> &B) {
	vector<int> ret;
	if (A.size() == 0 || B.size() == 0) {
		return ret;
	} else {
		int ptr_a = 0, ptr_b = 0;

		while (ptr_a < A.size() && ptr_b < B.size()) {
			if (A[ptr_a] < B[ptr_b]) {
				ptr_a++;
			} else if (A[ptr_a] > B[ptr_b]) {
				ptr_b++;
			} else {
				ret.push_back(A[ptr_a]);
				ptr_a++;
				ptr_b++;
			}
		}

		return ret;
	}
}

int main() {
	int n, x;
	cin>>n;
	vector<int> v1;
	for (int i = 0; i<n; i++) {
		cin>>x;
		if (v1.empty() || x >= v1.back()) {
			// To enforce ascending order input array
			v1.push_back(x);
		} else {
			return 1;
		}
	}

	cin>>n;
	vector<int> v2;
	for (int i = 0; i<n; i++) {
		cin>>x;
		if (v2.empty() || x >= v2.back()) {
			// To enforce ascending order input array
			v2.push_back(x);
		} else {
			return 1;
		}
	}

	vector<int> v = intersect(v1, v2);
	for (auto i : v) {
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}