// Problem: Problem 1. Cow Land
// Contest: USACO - USACO 2019 February Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=921
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
long arr[MAXN];
int parent[MAXN];
int depth[MAXN];
int LCA[MAXN][20];

long fen[MAXN];
int inTime[MAXN];
int outTime[MAXN];
int V, Q, t, a, b, Time;

void dfs1(int u, int p) {
	parent[u] = p;
	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		depth[v] = depth[u] + 1;
		dfs1(v, u);
	}
}

void init() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < 20; j++) {
			LCA[i][j] = -1;
		}
	}

	for (int i = 1; i < MAXN; i++)
		LCA[i][0] = parent[i];

	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= V; i++) {
			int par = LCA[i][j - 1];
			if (par != -1)
				LCA[i][j] = LCA[par][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b])
		swap(a, b);

	int D = depth[b] - depth[a];
	while (D) {
		int L = log(D) / log(2);
		b = LCA[b][L];
		D -= 1 << L;
	}
	if (a == b)
		return a;

	for (int i = 19; i >= 0; i--) {
		if (LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]) {
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

void update(int i, int x) {
	while (i < MAXN) {
		fen[i] ^= x;
		i += i & (-i);
	}
}

int query(int i) {
	int xr = 0;
	while (i > 0) {
		xr ^= fen[i];
		i -= i & (-i);
	}
	return xr;
}

void dfs2(int u, int p) {
	inTime[u] = Time++;
	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		dfs2(v, u);
	}
	outTime[u] = Time - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);

	cin >> V >> Q;
	for (int i = 1; i <= V; i++)
		cin >> arr[i];

	for (int i = 1; i < V; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs1(1, -1);
	init();

	Time = 1;
	dfs2(1, -1);

	for (int i = 1; i <= V; i++) {
		update(inTime[i], arr[i]);
		update(outTime[i] + 1, arr[i]);
	}

	for (int i = 1; i <= Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			update(inTime[a], arr[a]);
			update(outTime[a] + 1, arr[a]);
			arr[a] = b;
			update(inTime[a], arr[a]);
			update(outTime[a] + 1, arr[a]);
		} else {
			cin >> a >> b;
			int L = lca(a, b);
			cout << (query(inTime[a])^query(inTime[b])^arr[L]) << "\n";
		}
	}

	return 0;
}
