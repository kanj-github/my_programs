# include <iostream>

# define MAXK(x) ((x < 11)?x:11)

using namespace std;

int ** data;

void init (int * arr, int len) {
	data = new int * [MAXK(len)];
	for (int i=0; i<MAXK(len); i++) {
		data[i] = new int [len];
		for (int j=1; j-1<=i; j++) data[i][len-j] = arr[len-j];
	}
	
	int * temp, n;
	
	for (int i=0; i<MAXK(len); i++) {
		temp = new int [i+1];
		for (int j=0; j<=i; j++) temp[j] = 0;
		
		n = 0;
		while (n<len) {
			for (int j=0; j<=i; j++) {
				if (n == len) break;
				temp[j] += arr[n++];
				//n++;
			}
		}
		
		n=0;
		while (n<len-i-1) {
			for (int j=0; j<=i; j++) {
				if (n == len-i-1) break;
				data[i][n] = temp[j];
				temp[j] -= arr[n];
				n++;
			}
		}
	}
}

int main () {
	int s,Q,L,R,k,sub;
	cin>>s;
	int *a = new int[s];
	for (int i=0;i<s;i++) cin>>a[i];
	
	init (a, s);
	
	cin>>Q;
	
	for (int i=0; i<Q; i++) {
		cin>>L;
		cin>>R;
		cin>>k;
		if (L >= s || R>=s || k>= MAXK(s)) {
			cout<<"Fuck you!!\n";
			continue;
		}
		sub = (((R-L)/(k+1))+1)*(k+1);
		if (L+sub < s) sub = data[k][L+sub];
		else sub = 0;
		cout<<"-----> "<<data[k][L]-sub<<"\n";
	}
	return 0;
}