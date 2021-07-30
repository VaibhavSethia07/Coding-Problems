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

const int MAXN = 1e5 + 5;
struct data {
	int sum, pref, suf, ans;
};

data seg[4 * MAXN];
int arr[MAXN];

data combine(data L, data R) {
	data res;
	res.sum = L.sum + R.sum;
	res.pref = max(L.pref, L.sum + R.pref);
	res.suf = max(R.suf, R.sum + L.suf);
	res.ans = max({L.ans, R.ans, L.suf + R.pref});

	return res;
}

data make_data(int val) {
	data res;
	res.sum = val;
	res.pref = res.suf = res.ans = max(0, val);
	return res;
}

void build(int ind, int start, int end) {
	if (start == end) {
		seg[ind] = make_data(arr[start]);
		return;
	}

	int mid = start + (end - start) / 2;
	build(2 * ind + 1, start, mid);
	build(2 * ind + 2, mid + 1, end);

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void pointUpdate(int ind, int start, int end, int node, int val) {
	if (start == end) {
		seg[ind] = make_data(val);
		return;
	}

	int mid = start + (end - start) / 2;
	if (node <= mid)
		pointUpdate(2 * ind + 1, start, mid, node, val);
	else
		pointUpdate(2 * ind + 2, mid + 1, end, node, val);

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

data rangeQuery(int ind, int start, int end, int L, int R) {
	if (start > R || end < L || start > end)
		return make_data(0);

	if (start >= L && end <= R)
		return seg[ind];

	int mid = start + (end - start) / 2;
	return combine(rangeQuery(2 * ind + 1, start, mid, L, R), rangeQuery(2 * ind + 2, mid + 1, end, L, R));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int N, Q, t, a, b;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	build(0, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		cin >> t >> a >> b;
		if (t == 1)
			pointUpdate(0, 0, N - 1, a - 1, b);
		else {
			cout << rangeQuery(0, 0, N - 1, a - 1, b - 1).ans  << "\n";
		}
	}
	return 0;
}
