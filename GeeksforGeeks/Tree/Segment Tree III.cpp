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
int seg[4 * MAXN];
int arr[MAXN];

int combine(int a, int b) {
	return max(a, b);
}

void build(int ind, int start, int end) {
	if (start == end) {
		seg[ind] = arr[start];
		return;
	}

	int mid = start + (end - start) / 2;
	build(2 * ind + 1, start, mid);
	build(2 * ind + 2, mid + 1, end);

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void pointUpdate(int ind, int start, int end, int node, int val) {
	if (start == end) {
		seg[ind] = val;
		return;
	}

	int mid = start + (end - start) / 2;
	if (node <= mid)
		pointUpdate(2 * ind + 1, start, mid, node, val);
	else
		pointUpdate(2 * ind + 2, mid + 1, end, node, val);

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int rangeQuery(int ind, int start, int end, int L, int R, int x) {

	if (start > R || end < L || start > end || seg[ind] < x)
		return -1;

	if (start >= L && end <= R) {

		while (start != end) {
			int mid = start + (end - start) / 2;
			if (seg[2 * ind + 1] > x) {
				ind = 2 * ind + 1;
				end = mid;
			} else {
				ind = 2 * ind + 2;
				start = mid + 1;
			}
		}
		return start;
	}

	int mid = start + (end - start) / 2;
	int left = rangeQuery(2 * ind + 1, start, mid, L, R, x);
	if (left != -1)
		return left;
	return rangeQuery(2 * ind + 2, mid + 1, end, L, R, x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int N, Q, t, a, b, x;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	build(0, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		cin >> t >> a >> b;
		if (t == 1)
			pointUpdate(0, 0, N - 1, a - 1, b);
		else {
			cin >> x;
			cout << rangeQuery(0, 0, N - 1, a - 1, b - 1, x)  << "\n";
		}
	}
	return 0;
}
