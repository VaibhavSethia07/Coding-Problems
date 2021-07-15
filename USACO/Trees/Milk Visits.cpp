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
const int PAR = 32;
int N, M, a, b;
string S;
char c;
vector<int> tree[MAXN];
int level[MAXN];
int parent[MAXN];
int pre[MAXN];
int LCA[MAXN][PAR];

// LCA
void dfs(int u, int p) {
	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		level[v] = level[u] + 1;
		parent[v] = u;
		pre[v] = pre[u] + (S[v - 1] == 'H');
		dfs(v, u);
	}
}

void init1() {
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
		for (int j = 0; j < PAR; j++) {
			LCA[i][j] = -1;
		}
	}
}

void init2() {

	for (int i = 1; i <= N; i++) {
		LCA[i][0] = parent[i];
	}

	for (int j = 1; j < PAR; j++) {
		for (int i = 1; i <= N; i++) {
			int par = LCA[i][j - 1];
			if (par != -1)
				LCA[i][j] = LCA[par][j - 1];
		}
	}
}

int binaryLifting(int a, int b) {
	if (level[a] > level[b])
		swap(a, b);

	int D = level[b] - level[a];

	while (D > 0) {
		int L = log(D) / log(2);
		b = LCA[b][L];
		D -= (1 << L);
	}

	if (a == b)
		return a;

	for (int j = PAR - 1; j >= 0; j--) {
		if (LCA[a][j] != -1 && LCA[a][j] != LCA[b][j]) {
			a = LCA[a][j];
			b = LCA[b][j];
		}
	}

	return LCA[a][0];
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> S;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	init1();
	pre[1] = (S[0] == '1');
	level[1] = 1;
	dfs(1, -1);
	init2();

	string ans = "";
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;

		int lca = binaryLifting(a, b);
		int noOfCow = (level[a] - level[lca]) + (level[b] - level[lca]) + 1;
		int noOfHolstein = (pre[a] - pre[lca]) + (pre[b] - pre[lca]) + (S[lca - 1] == 'H');
		int noOfGuernsey = noOfCow - noOfHolstein;

		if (c == 'H' && noOfHolstein)
			ans += '1';
		else if (c == 'G' && noOfGuernsey)
			ans += '1';
		else
			ans += '0';
	}

	cout << ans << "\n";

	return 0;
}
