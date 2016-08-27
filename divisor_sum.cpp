# include <iostream>

using namespace std;

#define MAX 500000
#define SQRT 708

long ans[MAX];


void init() {
	int temp;
	ans[0] = 0;
	for (int j=1; j<MAX; j++) ans[j] = 1;
	// 1 divides every number and gives an oppurtunity to initialise the array

	/*for (int i=2;i<=SQRT;i++) for (int j=i-1; j<MAX; j++) {
		if (((j+1)%i) == 0) ans[j]+=(i+(j+1)/i);
	}*/
	
	for (int i=2; i<SQRT; i++)
		for(int j=i*i-1; j<MAX; j+=i) {
			temp = (j+1)/i;
			ans[j]+=i;
			if (temp != i) ans[j]+=temp;
		}
}

int main() {
	init();
	int T,N;
	cin>>T;
	while (T>0) {
		cin>>N;
		if (N==0) cout<<0<<"\n";
		else cout<<ans[N-1]<<"\n";
		T--;
	}
	return 0;
}