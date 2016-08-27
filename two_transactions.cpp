# include <iostream>
# include <climits>

using namespace std;

struct tr {
	int b;
	int s;
	
	tr() {
		b = s = -1;
	}
};

tr * t1, * t2;

//int * p1, *p2;

void scan1 (int * arr, int n) {
	t1 = new tr [n];
	//t[0].b = t[0].s = -1;
	int min = 0, max_gain = 0;
	for (int i=1; i<n; i++) {
		if (arr[i] < arr[min]) min = i;
		if (arr[i] - arr[min] > max_gain) {
			max_gain = arr[i] - arr[min];
			//cout<<max_gain<<"---\n";
			t1[i].b=min;
			t1[i].s=i;
		} else {
			t1[i].b = t1[i-1].b;
			t1[i].s = t1[i-1].s;
		}
	}
}

void scan2 (int * arr, int n) {
	t2 = new tr[n];
	int max = n-1, max_gain = 0;
	for (int i=n-2; i>=0; i--) {
		if (arr[i]>arr[max]) max = i;
		if (arr[max] - arr[i] > max_gain) {
			max_gain = arr[max] - arr[i];
			//cout<<max_gain<<"===\n";
			t2[i].b=i;
			t2[i].s=max;
		} else {
			t2[i].b = t2[i+1].b;
			t2[i].s = t2[i+1].s;
		}
	}
}

int main() {
	int len, *arr;
	cin>>len;
	arr = new int[len];
	for (int i=0; i<len; i++) cin>>arr[i];
	
	scan1(arr, len);
	scan2(arr, len);
	
	int i = -1, max = 0, temp;
	
	for (int j=0; j<len; j++) {
		if (t1[j].s == -1 || t1[j].b == -1 || t2[j].s == -1 || t2[j].b == -1) continue;
		temp = arr[t1[j].s]-arr[t1[j].b]+arr[t2[j].s]-arr[t2[j].b];
		//cout<<temp<<"++++\n";
		if (temp > max) {
			max = temp;
			i = j;
		}
	}
	
	if (i != -1) cout<<t1[i].b<<" "<<t1[i].s<<" "<<t2[i].b<<" "<<t2[i].s<<"\n";
}
