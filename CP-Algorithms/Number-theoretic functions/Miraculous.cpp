// Problem: Miraculous
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/TNVFC1M/
// Memory Limit: 1536 MB
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

int arr[MAXN];
int st[MAXN][20];
int lg[MAXN];
int n, h, b, e;

void create() {
	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
		lg[i] = lg[i / 2] + 1;

	for (int i = 0; i < MAXN; i++)
		st[i][0] = i;

	for (int j = 1; j < 20; j++) {
		for (int i = 0; i + (1 << (j - 1)) < MAXN; i++) {
			int c1 = st[i][j - 1], c2 = st[i + (1 << (j - 1))][j - 1];
			st[i][j] = ((arr[c1] < arr[c2]) ? c1 : c2);
		}
	}
}

int query(int l, int r) {
	int j = lg[r - l + 1];
	int c1 = st[l][j], c2 = st[r - (1 << j) + 1][j];
	return ((arr[c1] < arr[c2]) ? c1 : c2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> h >> b >> e) {
		memset(arr, 0, sizeof(arr));

		vector<int> ans(n);
		b--, e--;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		create();

		for (int i = n - 1; i >= 0; i--) {
			int idx = query(max(0, i - h + 1), i);
			ans[idx]++;
		}

		for (int i = b; i <= e; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}
