# include <iostream>
# include <cstdlib>

using namespace std;

int swaps = 0;

void swap (int * arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j]= temp;
	swaps++;
}

void merge_sort (int * arr, int s, int e) {
	if (s==e) return;
	else if (e-s == 1) {
		if (arr[s] > arr[e]) swap(arr, s, e);
		return;
	} else {
		int mid = s+(e-s)/2;
		merge_sort(arr,s,mid);
		merge_sort(arr,mid+1,e);
		// merge
		int i=s,j=mid+1;
		while (i<=mid && j<=e) {
			if (arr[i] <= arr[j]) i++;
			else {
				// slide the left sorted part one step right by swapping
				for (int k=j; k>i; k--) swap (arr, k, k-1);
				j++;i++; mid++;
			}
		}
	}
}

int main(int argc, char * argv[]) {
	
	if (argc < 3) {
		cout<<"Usage:\n1st argument = number of integers to sort.\n";
		cout<<"Give the input array as arguments after that\n";
		return -1;
	}
	
	int count = atoi(argv[1]);
	int * arr = new int[count];
	for (int i = 0; i<count; i++) arr[i] = atoi(argv[2+i]);
	merge_sort (arr, 0, count-1);
	for (int i = 0; i<count; i++) cout<<arr[i]<<" ";
	cout<<"\nNo. of swaps is "<<swaps<<"\n";
	return 0;
}
