
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

vector<int> tr[MAXN];
int V, Q, a, b;
int parent[MAXN];
int depth[MAXN];
int LCA[MAXN][20];

void dfs(int u, int p) {
	parent[u] = p;
	for (auto& v : tr[u]) {
		if (v == p)
			continue;
		depth[v] = 1 + depth[u];
		dfs(v, u);
	}
}

void init() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < 20; j++)
			LCA[i][j] = -1;
	}

	for (int i = 1; i <= V; i++)
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

	for (int j = 19; j >= 0; j--) {
		if (LCA[a][j] != -1 && LCA[a][j] != LCA[b][j]) {
			a = LCA[a][j];
			b = LCA[b][j];
		}
	}

	return LCA[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	cin >> V >> Q;
	for (int i = 2; i <= V; i++) {
		cin >> b;
		tr[b].push_back(i);
	}

	dfs(1, -1);
	init();

	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";

	}
	return 0;
}
