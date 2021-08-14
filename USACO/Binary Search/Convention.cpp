// Problem: Problem 1. Convention
// Contest: USACO - USACO 2018 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

void input(vi& v, int N) {
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

bool isArrangementPossible(int Time, vi& v, int N, int M, int C) {
	int cnt = 0;
	int i = 0;
	while (i < N) {
		int cap = 0;
		int mn = 1e9;
		int mx = 0;
		while (cap < C && i < N && max(mx, v[i]) - min(mn, v[i]) <= Time) {
			mn = min(mn, v[i]);
			mx = max(mx, v[i]);
			i++;
			cap++;
		}
		// cout<<mx<<" "<<mn<<" "<<Time<<"\n";
		if (mx - mn <= Time)
			cnt++;
		if (cnt > M)
			return false;
	}
	return cnt <= M;
}

void solve(vi& v, int N, int M, int C) {
	sort(all(v));

	int start = 0, end = 1e9, ans = 1e9;
	while (start <= end) {
		int Time = start + (end - start) / 2;
		if (isArrangementPossible(Time, v, N, M, C)) {
			// cout<<Time<<"\n";
			ans = Time;
			end = Time - 1;
		} else
			start = Time + 1;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	int N, M, C;
	cin >> N >> M >> C;
	vi v(N);
	input(v, N);
	solve(v, N, M, C);

	return 0;
}
