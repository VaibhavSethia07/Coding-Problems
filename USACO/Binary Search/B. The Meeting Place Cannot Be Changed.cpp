// Problem: B. The Meeting Place Cannot Be Changed
// Contest: Codeforces - Codeforces Round #403 (Div. 2, based on Technocup 2017 Finals)
// URL: https://codeforces.com/contest/782/problem/B
// Memory Limit: 256 MB
// Time Limit: 5000 ms

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
ll MAXN = 1e6;

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


void input(vector<double>& v, int N) {
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

bool canUnite(double Time, vector<double>& pos, vector<double>& speed, int N) {
	vector<pair<double, double>> range(N);

	for (int i = 0; i < N; i++) {
		range[i].f = pos[i] - Time * speed[i];
		range[i].s = pos[i] + Time * speed[i];
	}

	double mn = -1e12, mx = 1e12;
	for (int i = 0; i < N; i++) {
		mn = max(mn, range[i].f);
		mx = min(mx, range[i].s);
	}
	return mn <= mx;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<double> pos(N);
	vector<double> speed(N);
	input(pos, N);
	input(speed, N);

	double start = 0, end = 1e12, ans = 0;
	for (int i = 0; i < 200; i++) {
		double Time = start + (double)(end - start) / 2.00;
		if (canUnite(Time, pos, speed, N)) {
			ans = Time;
			end = Time - 1;
		} else
			start = Time + 1;
	}
	cout << fixed << setprecision(12) << ans;

	return 0;
}
