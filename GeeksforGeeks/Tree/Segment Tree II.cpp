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

ll a[MAXN];
ll seg[4 * MAXN];
ll lazy[4 * MAXN];

void build(int ind, int start, int end) {
	if (start == end) {
		seg[ind] = a[start];
		return;
	}

	int mid = (start + end) / 2;
	build(2 * ind + 1, start, mid);
	build(2 * ind + 2, mid + 1, end);

	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll query(int ind, int start, int end, int L, int R) {
	if (R < start || end < L || start > end)
		return 0;

	if (start >= L && end <= R)
		return seg[ind];
	int mid = (start + end) / 2;
	ll left = query(2 * ind + 1, start, mid, L, R);
	ll right = query(2 * ind + 2, mid + 1, end, L, R);

	return left + right;
}

void pointUpdate(int ind, int start, int end, int node, int val) {
	if (start > end)
		return;

	if (start == end) {
		seg[ind] += 1ll * val;
		return;
	}

	int mid = start + (end - start) / 2;
	if (mid >= node)
		pointUpdate(2 * ind + 1, start, mid, node, val);
	else
		pointUpdate(2 * ind + 2, mid + 1, end, node, val);

	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void rangeUpdate(int ind, int start, int end, int L , int R, int val) {
	if (lazy[ind] != 0) {
		seg[ind] += 1ll * (end - start + 1) * lazy[ind];
		if (start != end) {
			lazy[2 * ind + 1] += lazy[ind];
			lazy[2 * ind + 2] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if (start > R || end < L || start > end)
		return;

	if (start >= L && end <= R) {
		seg[ind] += (end - start + 1) * val;
		if (start != end) {
			lazy[2 * ind + 1] += val;
			lazy[2 * ind + 2] += val;
		}
		return;
	}

	int mid = start + (end - start) / 2;
	rangeUpdate(2 * ind + 1, start, mid, L, R, val);
	rangeUpdate(2 * ind + 2, mid + 1, end, L, R, val);

	seg[ind] += seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll rangeSum(int ind, int start, int end, int L, int R) {
	if (lazy[ind] != 0) {
		seg[ind] += 1ll * (end - start + 1) * lazy[ind];
		if (start != end) {
			lazy[2 * ind + 1] += lazy[ind];
			lazy[2 * ind + 2] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if (start > R || end < L || start > end)
		return 0;

	if (start >= L && end <= R)
		return seg[ind];

	int mid = start + (end - start) / 2;
	return rangeSum(2 * ind + 1, start, mid, L, R) + rangeSum(2 * ind + 2, mid + 1, end, L, R);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, T, L, R;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	build(0, 0, N - 1);

	for (int q = 0; q < Q; q++) {
		cin >> T >> L >> R;
		if (T == 0) {
			pointUpdate(0, 0, N - 1, L, R);
		} else
			cout << query(0, 0, N - 1, L, R - 1) << "\n";
	}

	return 0;
}
