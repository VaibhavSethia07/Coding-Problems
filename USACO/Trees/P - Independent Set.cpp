// Problem: P - Independent Set
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_p
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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

/* These template codes have been taken from cp-algorithms */
ll extEuclid(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll d = extEuclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}

ll modInverse(ll a, ll n) {
	ll x, y;
	extEuclid(a, n, x, y);
	return x;
}

ll linearCong(ll a, ll b, ll n) {
	ll d = __gcd(a, n);

	if (b % d)
		return -1;
	a /= d; b /= d; n /= d;
	ll a_inv = modInverse(a, n);
	ll ans = (b * a_inv) % n;
	if (ans < 0)
		ans += n;
	return ans;
}

void divisors(map<int, int>& d, ll N) {
	for (int div : {2, 3, 5}) {
		int cnt = 0;
		if (N % div == 0) {
			while ((N % div) == 0) {
				N /= div;
				cnt++;
			}
			d[div] = cnt;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (ll div = 7; div * div <= N; div += increments[i++]) {
		if ((N % div) == 0) {
			int cnt = 0;
			while ((N % div) == 0) {
				N /= div;
				cnt++;
			}
			d[div] = cnt;
		}
		if (i == 8)
			i = 0;
	}
	if (N > 1)
		d[N] = 1;
}

/* Print the string of digits without leading zero */
void norm(string& str) {
	bool zero = true;

	for (auto& c : str) {
		if (c != '0')
			zero = false;
		if (c != '0' || !zero)
			cout << c;
	}
}

struct DSU {
	vector<int> parent;
	vector<int> sz;
	void init(int N) {sz = vector<int>(N, 1); parent = vector<int>(N); for (int i = 0; i < N; i++) parent[i] = i;}
	int find(int x) {vector<int> anc; while (x != parent[x]) {anc.push_back(x); x = parent[x];} for (int i = 0; i < (int)anc.size(); i++) parent[anc[i]] = x; return x;}
	bool unite(int a, int b) {if (find(a) == find(b)) return false; a = find(a); b = find(b); if (sz[b] > sz[a])swap(a, b); parent[b] = a; sz[a] += sz[b]; return true;}
};

int kruskal(int N, vector<vector<int>>& edges) {
	sort(all(edges));
	int cost = 0;
	DSU D;
	D.init(N);
	for (int i = 0; i < (int)edges.size(); i++) {
		if (D.unite(edges[i][1], edges[i][2]))
			cost += edges[i][0];
	}
	return cost;
}

ll modProd(ll a, ll b, ll m) {
	ll result = 0;

	while (b) {
		if (b & 1)
			result = (result + a) % m;
		b >>= 1;
		a = (a + a) % m;
	}
	return result;
}

ll modBinExp(ll a, ll b, ll m) {
	ll result = 1;

	while (b) {
		if (b & 1)
			result = modProd(result, a, m) % m;
		b >>= 1;
		a = modProd(a, a, m) % m;
	}
	return result;
}

void input(vl& v, int N) {
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

const int MAXN = 1e5 + 5;
int V, a, b;
vector<int> tree[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];
// 1-->Black color
// 2-->White color

void dfs(int node, int parent) {
	int sz = tree[node].size() - ((parent == -1) ? 0 : 1);

	dp1[node] = 1;
	dp2[node] = 1;
	if (sz == 0)
		return;

	for (auto& child : tree[node]) {
		if (child == parent)
			continue;
		dfs(child, node);
		dp1[node] *= dp2[child];
		dp2[node] *= (dp1[child] + dp2[child]) % mod;

		dp1[node] %= mod;
		dp2[node] %= mod;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	for (int i = 0; i < V - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, -1);

	cout << (dp1[1] + dp2[1]) % mod << "\n";

	return 0;
}
