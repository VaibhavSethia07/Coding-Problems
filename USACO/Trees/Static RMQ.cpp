// Problem: Static RMQ
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/staticrmq
// Memory Limit: 1024 MB
// Time Limit: 5000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using l = long;
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
const int MAXN = 5e5 + 5;

int sparse_table[MAXN][21];
int N, Q, a, b;
int arr[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sparse_table[i][0] = arr[i];
	}

	for (int j = 1; j < 21; j++) {
		for (int i = 0; i < N && i + (1 << (j - 1)) < N; i++) {
			sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int i = 1; i <= Q; i++) {
		cin >> a >> b;
		int ans = 1e9;
		for (int j = 20; j >= 0; j--) {
			if ((1 << j) <= (b - a)) {
				ans = min(ans, sparse_table[a][j]);
				a += 1 << j;
			}
		}
		cout << ans << "\n";
	}


	return 0;
}
