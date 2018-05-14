# include <iostream>
# include <vector>

using namespace std;

int maxArea(vector<int> &A) {
	int max = 0, i = 0, j = A.size() - 1, area, min;
	while (i < j) {
		if (A[i] > A[j]) {
			min = j;
			j--;
		} else {
			min = i;
			i++;
		}
		area = A[min] * (j - i + 1); // add one to adjust for increment in i or decrement in j
		max = (area > max) ? area : max;
	}

	return max;
}

int main() {
	int size;
	cin>>size;
	vector<int> arr = vector<int>(size, 0);
	for (int i = 0; i<size; i++) {
		cin>>arr[i];
	}
	cout<<maxArea(arr)<<"\n";
	return 0;
}
