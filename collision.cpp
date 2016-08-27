#include <iostream>
#include <iomanip>
#define MAX_TEST_CASES 11
#define SAFE 201

using namespace std;

float getTime (int, int, char, char);

int main() {
	int tc, xe, ye, xa, ya,n,i,l=0;
	float ans[MAX_TEST_CASES],tim;
	char de, da;
	cin>>tc;
	while (l<tc) {
		ans[l]=SAFE;
		cin>>xe>>ye>>de>>n;
		for (i=0;i<n;i++) {
			cin>>xa>>ya>>da;
			tim=getTime(xa-xe,ya-ye,de,da);
			if (tim<0) tim=-tim;
			if (ans[l]>tim) ans[l]=tim;
		}
	l++;
	}
	cout<<"OUTPUT\n";
	for (i=0;i<tc;i++) {
		if (ans[i]==SAFE) cout<<"SAFE\n";
		else cout<<setprecision(1)<<fixed<<ans[i]<<"\n";
	}
}

float getTime (int x, int y, char e, char a) {
	switch(e) {
		case 'U':
			if (y<=0 || (x>0 && a=='R') || (x<0 && a=='L') || (a=='D' && x!=0)) return SAFE;
			if (a=='D') return y/2.0;
			if (x==y) return x;
			else return SAFE;
			break;
		case 'D':
			if (y>=0 || (x>0 && a=='R') || (x<0 && a=='L') || (a=='U' && x!=0)) return SAFE;
			if (a=='U') return y/2.0;
			if (x==y) return x;
			else return SAFE;
			break;
		case 'R':
			if (x<=0 || (y>0 && a=='U') || (y<0 && a=='D') || (a=='L' && y!=0)) return SAFE;
			if (a=='L') return x/2.0;
			if (x==y) return x;
			else return SAFE;
			break;
		case 'L':
			if (x>=0 || (y>0 && a=='U') || (y<0 && a=='D') || (a=='R' && y!=0)) return SAFE;
			if (a=='R') return x/2.0;
			if (x==y) return x;
			else return SAFE;
			break;
		default:
			return SAFE;
	}
}
