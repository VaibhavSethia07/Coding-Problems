// Problem: Factor Tree
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/FCTRE
// Memory Limit: 256 MB
// Time Limit: 7500 ms

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
vector<int> tree[MAXN];
vector<pair<int, int>> adj[1000005];
int A[MAXN];
int freq[1000005];
int startTime[MAXN];
int endTime[MAXN];
int flat_tree[2 * MAXN];
int node_freq[MAXN];
int mod_inv[1000005];

int depth[MAXN];
int parent[MAXN];
int st[MAXN][20];
int ML, MR, T, N, Q, a, b, L, R, Time;
const int block_sz = 1200;
int happyQ = 1;
struct Query {
	int idx, L, R, lca, a, b;
	bool flag;
};

Query queries[MAXN];
int ans[MAXN];

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

void init() {
	mod_inv[0] = 1;
	mod_inv[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		mod_inv[i] = (mod - (mod / i) * 1ll * mod_inv[mod % i] % mod) % mod;
	}

	adj[1].push_back({1, 0});
	for (int i = 2; i <= 1000000; i++) {
		if (adj[i].size() == 0) {
			adj[i].push_back({i, 1});
			for (long long int j = 2 * i; j <= 1000000; j += i) {
				int x = j;
				int cnt = 0;
				while (x % i == 0)
					cnt++, x /= i;
				adj[j].push_back({i, cnt});
			}
		}
	}
}

void ett(int u, int p) {
	parent[u] = ((p == 0) ? -1 : p);
	depth[u] = depth[p] + 1;
	flat_tree[Time] = u;
	startTime[u] = Time++;
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
		for (int i = 1; i <= N; i++) {
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
	while (D) {
		int L = log2(D);
		b = st[b][L];
		D -= (1 << L);
	}

	if (a == b)
		return a;

	for (int j = 19; j >= 0; j--) {
		if (st[a][j] != -1 && (st[a][j] != st[b][j]))
			a = st[a][j], b = st[b][j];
	}
	return st[a][0];
}

void add(int i) {
	int node = flat_tree[i];
	node_freq[node]++;
	int x = A[node];

	if (node_freq[node] == 1) {
		for (auto p : adj[x]) {
			int prev = freq[p.first];
			freq[p.first] += p.second;
			int curr = freq[p.first];
			happyQ = (happyQ * 1ll * mod_inv[prev + 1]) % mod;
			happyQ = (happyQ * 1ll * (curr + 1)) % mod;
		}
	} else {
		for (auto p : adj[x]) {
			int prev = freq[p.first];
			freq[p.first] -= p.second;
			int curr = freq[p.first];
			happyQ = (happyQ * 1ll * mod_inv[prev + 1]) % mod;
			happyQ = (happyQ * 1ll * (curr + 1)) % mod;
		}
	}

	if (happyQ < 0)
		happyQ += mod;
	happyQ %= mod;

}

void remove(int i) {
	int node = flat_tree[i];
	node_freq[node]--;
	int x = A[node];

	if (node_freq[node] == 1) {
		for (auto p : adj[x]) {
			int prev = freq[p.first];
			freq[p.first] += p.second;
			int curr = freq[p.first];
			happyQ = (happyQ * 1ll * mod_inv[prev + 1]) % mod;
			happyQ = (happyQ * 1ll * (curr + 1)) % mod;
		}
	} else {
		for (auto p : adj[x]) {
			int prev = freq[p.first];
			freq[p.first] -= p.second;
			int curr = freq[p.first];
			happyQ = (happyQ * 1ll * mod_inv[prev + 1]) % mod;
			happyQ = (happyQ * 1ll * (curr + 1)) % mod;
		}
	}

	if (happyQ < 0)
		happyQ += mod;
	happyQ %= mod;
}

int addLCA(int lca) {
	int x = A[lca];
	int newHappyQ = happyQ;
	for (auto p : adj[x]) {
		int prev = freq[p.first];
		int curr = prev + p.second;
		newHappyQ = (newHappyQ * 1ll * mod_inv[prev + 1]) % mod;
		newHappyQ = (newHappyQ * 1ll * (curr + 1)) % mod;
	}

	if (newHappyQ < 0)
		newHappyQ += mod;
	newHappyQ %= mod;
	return newHappyQ;
}

void reset(int N) {
	for (int i = 1; i <= 1000000; i++) {
		freq[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		tree[i].clear();
		node_freq[i] = 0;
		for (int j = 0; j < 20; j++)
			st[i][j] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> T;
	while (T--) {
		cin >> N;
		reset(N);
		for (int i = 0; i < N - 1; i++) {
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		for (int i = 1; i <= N; i++)
			cin >> A[i];

		Time = 1;
		ett(1, 0);
		initLCA();
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			cin >> a >> b;
			if (startTime[a] > startTime[b])
				swap(a, b);
			queries[i].idx = i;
			queries[i].lca = LCA(a, b);

			if (queries[i].lca == a) {
				queries[i].L = startTime[a];
				queries[i].R = startTime[b];
				queries[i].flag = 0;
			} else {
				queries[i].L = endTime[a];
				queries[i].R = startTime[b];
				queries[i].flag = 1;
			}

		}
		happyQ = 1, ML = 1, MR = 0;
		sort(queries, queries + Q, compare);

		for (int i = 0; i < Q; i++) {
			L = queries[i].L;
			R = queries[i].R;
			int lca = queries[i].lca;

			while (ML > L)
				ML--, add(ML);
			while (MR < R)
				MR++, add(MR);
			while (ML < L)
				remove(ML), ML++;
			while (MR > R)
				remove(MR), MR--;

			if (queries[i].flag == 0)
				ans[queries[i].idx] = happyQ % mod;
			else
				ans[queries[i].idx] = addLCA(lca) % mod;
			ans[queries[i].idx] %= mod;
		}

		for (int i = 0; i < Q; i++)
			cout << ans[i] << "\n";
	}
	return 0;
}
