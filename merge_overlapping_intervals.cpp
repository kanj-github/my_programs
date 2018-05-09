# include <iostream>
# include <vector>

using namespace std;

// https://www.interviewbit.com/problems/merge-overlapping-intervals/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

 void swap(vector<Interval> &A, int from, int to) {
 	int tmp;
 	tmp = A[from].start;
 	A[from].start = A[to].start;
 	A[to].start = tmp;
 	tmp = A[from].end;
 	A[from].end = A[to].end;
 	A[to].end = tmp;
 }

 void quicksort(vector<Interval> &A, int from, int to) {
 	if (from == to || to < from) {
 		return;
 	} else if (to == from + 1) {
 		if (A[from].start > A[to].start) {
 			swap(A, from, to);
 		}
 		return;
 	} else {
 		int pivot = to;
 		int ptr = from;
 		while (ptr < pivot) {
 			if (A[ptr].start > A[pivot].start) {
 				if (pivot == ptr + 1) {
 					swap(A, pivot, ptr);
 				} else {
 					int ps = A[pivot].start, pe = A[pivot].end;
 					A[pivot].start = A[ptr].start;
 					A[pivot].end = A[ptr].end;
 					A[ptr].start = A[pivot - 1].start;
 					A[ptr].end = A[pivot - 1].end;
 					A[pivot - 1].start = ps;
 					A[pivot - 1].end = pe;
 				}
 				pivot--;
 			} else {
 				ptr++;
 			}
 		}

 		quicksort(A, from, pivot - 1);
 		quicksort(A, pivot+1, to);
 	}
 }

 vector<Interval> merge(vector<Interval> &A) {
 	if (A.size() < 2) {
 		return A;
 	} else {
 		quicksort(A, 0, A.size() - 1);
 		vector<Interval> merged;
 		merged.push_back(A[0]);
 		for (int i = 1; i<A.size(); i++) {
 			if (A[i].start >= merged.back().start && A[i].start <= merged.back().end) {
 				if (A[i].end > merged.back().end) {
 					merged.back().end = A[i].end;
 				}
 			} else {
 				merged.push_back(A[i]);
 			}
 		}
 		return merged;
 	}
 }

 int main() {
 	int x, y, n;
 	cin>>n;
 	vector<Interval> ranges;
 	for (; n>0; n--) {
 		Interval i;
 		cin>>i.start>>i.end;
 		ranges.push_back(i);
 	}
 	vector<Interval> merged = merge(ranges);
 	for (const auto& i : merged) {
 		cout<<"("<<i.start<<", "<<i.end<<")\n";
 	}
 	return 0;
 }
