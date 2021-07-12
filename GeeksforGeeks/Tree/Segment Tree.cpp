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

int a[MAXN];
int seg[4 * MAXN];

void build(int ind, int start, int end) {
	if (start == end) {
		seg[ind] = a[start];
		return;
	}

	int mid = (start + end) / 2;
	build(2 * ind + 1, start, mid);
	build(2 * ind + 2, mid + 1, end);

	seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int start, int end, int L, int R) {
	if (R < start || end < L)
		return INT_MAX;

	if (start >= L && end <= R)
		return seg[ind];
	int mid = (start + end) / 2;
	int left = query(2 * ind + 1, start, mid, L, R);
	int right = query(2 * ind + 2, mid + 1, end, L, R);

	return min(left, right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, L, R;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	build(0, 0, N - 1);

	for (int q = 0; q < Q; q++) {
		cin >> L >> R;
		cout << query(0, 0, N - 1, L, R - 1) << "\n";
	}

	return 0;
}
