// Problem: Problem 2. Barn Painting
// Contest: USACO - USACO 2017 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=766
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

const int MAXN = 2e5 + 5;
int V, K, a, b;
vector<int> tree[MAXN];
ll dp[MAXN][4];
int colored[MAXN];

void dfs(int node, int parent) {
	int sz = tree[node].size() - ((parent == -1) ? 0 : 1);
	int color = colored[node];

	if (sz == 0) {
		if (color) {
			dp[node][color] = 1;
		} else {
			dp[node][1] = dp[node][2] = dp[node][3] = 1;
		}
		return;
	}

	unordered_set<int> colorsLeft;
	colorsLeft.insert(1); colorsLeft.insert(2); colorsLeft.insert(3);

	for (auto& child : tree[node]) {
		if (child == parent)
			continue;
		dfs(child, node);
		if (colored[child])
			colorsLeft.erase(colored[child]);
	}

	if (color) {
		if (colorsLeft.count(color) == 0)
			return;
		dp[node][color] = 1;
		for (auto& child : tree[node]) {
			if (child == parent)
				continue;
			dp[node][color] *= (dp[child][color % 3 + 1] + dp[child][(color + 1) % 3 + 1]);
			dp[node][color] %= mod;
		}
	} else {
		for (auto& new_color : colorsLeft) {
			dp[node][new_color] = 1;
			for (auto& child : tree[node]) {
				if (child == parent)
					continue;
				dp[node][new_color] *= (dp[child][new_color % 3 + 1] + dp[child][(new_color + 1) % 3 + 1]);
				dp[node][new_color] %= mod;
			}
		}
	}
}

void dfs2(int node, int parent) {

	for (auto& child : tree[node]) {
		if (child == parent)
			continue;

		dfs2(child, node);

		dp[node][1] *= (dp[child][2] + dp[child][3]) % mod;
		dp[node][2] *= (dp[child][3] + dp[child][1]) % mod;
		dp[node][3] *= (dp[child][1] + dp[child][2]) % mod;

		dp[node][1] %= mod;
		dp[node][2] %= mod;
		dp[node][3] %= mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);

	cin >> V >> K;

	for (int i = 0; i < V - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		colored[a] = b;
	}

	dfs(1, -1);

	cout << (dp[1][1] + dp[1][2] + dp[1][3]) % mod;

	/* Editorial Solution */

	for (int i = 1; i <= V; i++) {
		dp[i][1] = dp[i][2] = dp[i][3] = 1;
	}

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		dp[a][1] = 0;
		dp[a][2] = 0;
		dp[a][3] = 0;
		dp[a][b] = 1;
	}

	dfs2(1, -1);

	cout << (dp[1][1] + dp[1][2] + dp[1][3]) % mod;

	return 0;
}
