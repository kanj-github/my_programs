#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
set<long long> hash;
long long state[40][40][20000];
int len[40][40];
pair<int, int> w[100000];
int N, M, T;
void work0() {
	int s[3] = {0};
	for(int i = 0; i < T; i++) s[(M - w[i].second) % 3] ^= 1;
	if(M % 2 == 0) s[0] ^= 1, s[1] ^= 1;
	s[M % 3] = 0;
	printf("%s\n", (s[0] + s[1]) ? "NO" : "YES");
}
void work1() {
	long long d = 0;
	for(int i = 0; i < T; i++) {
		int s = (M - w[i].second) % len[N][w[i].first - 1] + 1;
		d ^= state[N][w[i].first - 1][s];
	}
	int A[45][45];
	memset(A, 0, sizeof(A));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		if(state[N][i][M % len[N][i] + 1] & (1LL << j)) A[j][i] = 1;
	for(int i = 0; i < N; i++) if(d & (1LL << i)) A[i][N] = 1;
	int now = 0;
	for(int i = 0; i < N; i++) {
		for(int j = now; j < N; j++) if(A[j][i]) {
			for(int k = 0; k <= N; k++) swap(A[j][k], A[now][k]);
			break;
		}
		if(!A[now][i]) continue;
		for(int j = now + 1; j < N; j++) if(A[j][i]) for(int k = 0; k <= N; k++)
			A[j][k] ^= A[now][k];
		now++;
	}
	for(int i = now; i < N; i++) if(A[i][N]) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
}
int main()
{
	for(int i = 1; i < 40; i++) for(int j = 0; j < i; j++) {
		long long *p = state[i][j];
		p[1] = (1LL << j);
		int k;
		for(k = 2; ; k++) {
			p[k] = (p[k - 1] ^ p[k - 2] ^ (p[k - 1] << 1) ^ (p[k - 1] >> 1)) & ((1LL << i) - 1);
			if(p[k] == p[1] && p[k - 1] == p[0]) break;
		}
		len[i][j] = k - 1;
	}
	int Test;
	for(scanf("%d", &Test); Test--; ) {
		scanf("%d%d%d", &N, &M, &T);
		for(int i = 0; i < T; i++) scanf("%d%d", &w[i].first, &w[i].second);
		if(N > M) {
			swap(N, M);
			for(int i = 0; i < T; i++) swap(w[i].first, w[i].second);
		}
		if (N == 1) work0();
		else work1();
	}
}

