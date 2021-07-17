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

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];

int diameter = 0;

int height(int node, int parent) {

	int left = 0, right = 0;
	for (auto& child : tree[node]) {
		if (child == parent)
			continue;
		int ht = height(child, node);
		if (ht > left) {
			if (left > right)
				right = left;
			left = ht;
		} else if (ht > right) {
			if (right > left)
				left = right;
			right = ht;
		}
	}

	diameter = max(diameter, left + right);
	return max(left, right) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, a, b;
	cin >> V;

	for (int i = 0; i < V - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	height(1, -1);

	cout << diameter;
	return 0;
}
