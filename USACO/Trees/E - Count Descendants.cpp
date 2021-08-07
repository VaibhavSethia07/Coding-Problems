// Problem: E - Count Descendants
// Contest: AtCoder - AISing Programming Contest 2021（AtCoder Beginner Contest 202）
// URL: https://atcoder.jp/contests/abc202/tasks/abc202_e
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
const int MAXN = 2e5 + 5;

int V, Q, a, b, Time;
vector<int> tree[MAXN];
vector<int> depthList[MAXN];
int inTime[MAXN];
int outTime[MAXN];
int depth[MAXN];

void dfs(int u, int p) {
	inTime[u] = Time++;
	depthList[depth[u]].push_back(Time - 1);
	for (auto& v : tree[u]) {
		if (v == p)
			continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
	outTime[u] = Time - 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	for (int b = 2; b <= V; b++) {
		cin >> a;
		tree[a].push_back(b);
	}

	dfs(1, -1);

	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> a >> b;
		cout << upper_bound(all(depthList[b]), outTime[a]) - lower_bound(all(depthList[b]), inTime[a]) << "\n";
	}

	return 0;
}
