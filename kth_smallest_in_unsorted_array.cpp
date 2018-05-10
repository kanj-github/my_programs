# include <iostream>
# include <vector>

using namespace std;

void max_heapify(vector<int> &A, int i) {
	if (i < 0) return;
 
	int l = 2*i + 1, r = 2*i + 2, max = i;
	if (l < A.size() && A[l] > A[i]) {
		max = l;
	}
	if (r < A.size() && A[r] > A[max]) {
		max = r;
	}
	if (max != i) {
		int tmp = A[i];
		A[i] = A[max];
		A[max] = tmp;
		max_heapify(A, max);
	}
}

int get_kth_smallest(vector<int> &A, int k) {
	// Make a max-heap with k nodes man
	if (k < 0 || k > A.size()) {
		return -1; // or whatever the error value should be
	}

	// Make a max-heap with k nodes
	vector<int> heap;
	for (int i = 0; i<k; i++) {
		heap.push_back(A[i]);
	}
	for (int i = k/2 - 1; i>=0; i--) {
		max_heapify(heap, i);
	}

	// Deal with the next n-k elements in the array
	for (int i = k; i<A.size(); i++) {
		if (A[i] < heap[0]) {
			heap[0] = A[i];
			max_heapify(heap, 0);
		}
	}

	return heap[0];
}

int main() {
	int size, k;
	cin>>size>>k;
	vector<int> array(size);
	for (int i=0; i<size; i++) {
		cin>>array[i];
	}
	cout<<get_kth_smallest(array, k)<<"\n";
	return 0;
}
