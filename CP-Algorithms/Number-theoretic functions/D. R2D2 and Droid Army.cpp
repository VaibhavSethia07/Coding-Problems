// Problem: D. R2D2 and Droid Army
// Contest: Codeforces - Codeforces Round #291 (Div. 2)
// URL: https://codeforces.com/problemset/problem/514/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;

#define mp make_pair
#define f first
#define s second

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define modinv(a,m) modEx(a,m-2,m)
#define moddiv(a,b,m) (a*modinv(b,m))%m
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

long st[5][MAXN][20];
long ans[5];
long shots[5];
int N, M, K;

void go() {
	for (int k = 0; k < M; k++) {
		for (int j = 1; j < 20; j++) {
			for (int i = 0; i + (1 << (j - 1)) < N; i++) {
				st[k][i][j] = max(st[k][i][j - 1], st[k][i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

int query(int k, int l, int r) {
	long mx = 0;
	for (int j = 19; j >= 0; j--) {
		if ((r - l + 1) >= (1 << j)) {
			mx = max(mx, st[k][l][j]);
			l += 1 << j;
		}
	}
	return mx;
}

bool canDestroy(int mid) {
	for (int i = 0; i + mid <= N; i++) {
		for (int j = 0; j < M; j++) {
			shots[j] = query(j, i, i + mid - 1);
		}
		int tot = 0;
		for (int j = 0; j < M; j++) {
			tot += shots[j];
		}
		if (tot <= K)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> st[j][i][0];
		}
	}

	go();

	long start = 1, end = N;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (canDestroy(mid)) {
			for (int i = 0; i < M; i++)
				ans[i] = shots[i];
			start = mid + 1;
		} else
			end = mid - 1;
	}

	for (int i = 0; i < M; i++)
		cout << ans[i] << " ";


	return 0;
}
