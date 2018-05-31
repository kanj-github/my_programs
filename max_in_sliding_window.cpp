# include <iostream>
# include <vector>
# include <deque>

using namespace std;

vector<int> slidingMax(const vector<int> A, int B) {
	vector<int> ret;
	deque<int> q;

	for (int i=0; i<B; i++) {
		if (q.empty()) {
			q.push_front(i);
		} else {
			while (!q.empty() && A[q.back()] <= A[i]) {
				q.pop_back();
			}
			q.push_back(i);
		}
	}

	for (int i=B; i<A.size(); i++) {
		ret.push_back(A[q.front()]);

		// Remove index at front that may be out of window
		if (!q.empty() && q.front() <= i - B) {
			q.pop_front();
		}

		// Try to put A[i] in queue from the end
		while (!q.empty() && A[q.back()] <= A[i]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	ret.push_back(A[q.front()]);

	return ret;
}

int main() {
	int len, w_len, x;
	cin>>len;
	vector<int> array;
	for (int i=0; i< len; i++) {
		cin>>x;
		array.push_back(x);
	}
	cin>>w_len;
	vector<int> answer = slidingMax(array, w_len);
	for (auto i : answer) {
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
