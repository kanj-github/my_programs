# include <iostream>

using namespace std;

int burn(int * d, int *f, int n) {
	int deficit_at_0 = 0;
	int surplus = 0;
	int start = 0;
	for (int i=0; i<n-1; i++) {
		if (surplus+f[i] >= d[i]) {
			surplus+=(f[i]-d[i]);
		} else {
			deficit_at_0+=(d[i] - (surplus+f[i]));
			surplus = 0;
			start = i+1;
		}
	}
	if (surplus + f[n-1] >= d[n-1] + deficit_at_0) return start;
	else return -1;
}

int main() {
	int n, *d, *f;
	cout<<"Enter number of fuel stations.\n";
	cin>>n;
	d = new int [n];
	f = new int [n];
	cout<<"Enter values.\n";
	for (int i=0; i<n; i++) {
		cin>>d[i]>>f[i];
	}
	int ret = burn (d, f, n);
	cout<<ret<<"\n";
	return 0;
}