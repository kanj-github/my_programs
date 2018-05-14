# include <iostream>

using namespace std;

int zero;
int len;

/*int get_0 (int * arr) {
	for (int i=1; i<len; i++) if (arr[i] < arr[i-1]) return i;
	return -1;
}*/

int log_n_get_0 (int * arr) {
	int i, start=0, end=len-1;
	int last = arr[end];
	while (end-start > 1) {
		// use binary search type logic.
		i = start + (end-start)/2;
		if (arr[i] > last) {
			start = i;
		} else {
			end = i;
		}
	}

	if (end - start == 1 && arr[start] < arr[end]) return start;
	else return end;
}

int get_index (int i) {
	int ret = zero+i;
	if (ret >= len) ret-=len;
	return ret;
}

int modified_binary_search (int * arr, int start, int end, int num) {
	//cout<<"called with "<<start<<" - "<<end<<"\n";
	int i = start + (end-start)/2;
	int idx = get_index(i);
	//cout<<"i = "<<i<<" & idx = "<<idx<<"\n";
	if (arr[idx] == num) return idx;
	else if (start == end) return -1;
	else if (arr[idx] > num) return modified_binary_search(arr, start, i-1, num);
	else return modified_binary_search(arr, i+1, end, num);
}

int main () {
	int n;
	
	cout<<"Enter length\n";
	cin>>n;
	len = n;
	int * array = new int[n];
	for (int i=0; i<n; i++) cin>>array[i]; 
	zero = log_n_get_0(array);
	
	cout<<"\nWhat to search?\n";
	cin>>n;
	
	cout<<"Found at "<<modified_binary_search(array, 0, len-1, n)<<"\n";
	//cout<<"New zero is "<<log_n_get_0(array)<<"\n";
	return 0;
}
