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

const int MAXN = 1e5 + 5;
vector<int> tree[MAXN];


ll days = 0;
void dfs(int u, int p) {
	long sz = tree[u].size() - ((p == -1) ? 0 : 1);

	long cows = 1;
	while (cows < (sz + 1)) {
		days++;
		cows <<= 1;
	}

	days += sz;

	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		dfs(v, u);
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("ouput.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, a, b;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, -1);
	cout << days ;

	return 0;
}
