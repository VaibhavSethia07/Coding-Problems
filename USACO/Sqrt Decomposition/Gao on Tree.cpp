// Problem: Gao on a tree
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GOT/
// Memory Limit: 1536 MB
// Time Limit: 602 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
int values[MAXN];
int startTime[MAXN];
int endTime[MAXN];
int depth[MAXN];
int parent[MAXN];
int flat_tree[2 * MAXN];
int freq[MAXN];
int node_freq[MAXN];
int st[MAXN][20];
bool ans[MAXN];
const int block_sz = 1200;
int V, Q, ML, MR, a, b, c, Time, L, R, val;

struct Query {
	int idx, L, R, lca, val;
	bool flag;
};

Query queries[2 * MAXN];
bool compare(Query& q1, Query& q2) {
	int x = q1.L / block_sz;
	int y = q2.L / block_sz;

	if (x == y) {
		if (x & 1)
			return q1.R < q2.R;
		return q1.R > q2.R;
	}
	return x < y;
}

void add(int i) {
	int node = flat_tree[i];
	int x = values[node];
	node_freq[node]++;

	if (node_freq[node] == 1)
		freq[x]++;
	else
		freq[x]--;
}

void remove(int i) {
	int node = flat_tree[i];
	int x = values[node];
	node_freq[node]--;

	if (node_freq[node] == 1)
		freq[x]++;
	else
		freq[x]--;
}

bool addLCA(int lca, int c) {
	return values[lca] == c;
}

void ett(int u, int p) {
	parent[u] = ((p == 0) ? -1 : p);
	flat_tree[Time] = u;
	startTime[u] = Time++;
	depth[u] = depth[p] + 1;
	st[u][0] = parent[u];
	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		ett(v, u);
	}
	flat_tree[Time] = u;
	endTime[u] = Time++;
}

void initLCA() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= V; i++) {
			int par = st[i][j - 1];
			if (par != -1)
				st[i][j] = st[par][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b])
		swap(a, b);

	int D = depth[b] - depth[a];
	while (D > 0) {
		int L = log2(D);
		b = st[b][L];
		D -= 1 << L;
	}

	if (a == b)
		return a;

	for (int j = 19; j >= 0; j--) {
		if ((st[a][j] != st[b][j]) && st[a][j] != -1) {
			a = st[a][j];
			b = st[b][j];
		}
	}
	return st[a][0];
}

void reset() {
	for (int j = 0; j < 20; j++)
		for (int i = 1; i <= V; i++)
			st[i][j] = -1;

	for (int i = 0; i <= V; i++) {
		tree[i].clear();
		freq[i] = 0;
		node_freq[i] = 0;
		ans[i] = 0;
	}
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	while (cin >> V) {
		cin >> Q;
		reset();
		for (int i = 1; i <= V; i++)
			cin >> values[i];
		for (int i = 0; i < V - 1; i++) {
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}

		Time = 1;
		ett(1, 0);
		initLCA();

		for (int i = 0; i < Q; i++) {
			cin >> a >> b >> c;
			if (startTime[a] > startTime[b])
				swap(a, b);
			int lca = LCA(a, b);

			queries[i].lca = lca;
			queries[i].val = c;
			queries[i].idx = i;
			if (queries[i].lca == a) {
				queries[i].flag = 0;
				queries[i].L = startTime[a];
				queries[i].R = startTime[b];
			} else {
				queries[i].flag = 1;
				queries[i].L = endTime[a];
				queries[i].R = startTime[b];
			}
		}

		sort(queries, queries + Q, compare);

		ML = 1, MR = 0;
		for (int i = 0; i < Q; i++) {
			L = queries[i].L;
			R = queries[i].R;
			val = queries[i].val;
			while (ML > L)
				ML--, add(ML);
			while (MR < R)
				MR++, add(MR);
			while (ML < L)
				remove(ML), ML++;
			while (MR > R)
				remove(MR), MR--;

			if (queries[i].flag)
				ans[queries[i].idx] = freq[val] | addLCA(queries[i].lca, val);
			else
				ans[queries[i].idx] = freq[val];
		}

		for (int i = 0; i < Q; i++)
			if (ans[i])
				cout << "Find\n";
			else
				cout << "NotFind\n";
		cout << "\n";
	}

	return 0;
}
