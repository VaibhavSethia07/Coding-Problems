// Problem: Problem 1. Promotion Counting
// Contest: USACO - USACO 2017 January Contest, Platinum
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=696
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
template <class T> using indexed_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;

namespace std {
void swap(indexed_set<int>& a, indexed_set<int>& b) {
	a.swap(b);
}
}

const int MAXN = 1e5 + 5;
int V, a, b;
vector<int> tr[MAXN];
vector<int> arr;
vector<int> ans;
indexed_set<int> sub_tree[MAXN];

void dfs(int u, int p) {
	sub_tree[u].insert(arr[u]);

	for (auto& v : tr[u]) {
		if (v == p)
			continue;
		dfs(v, u);
		if ((int)sub_tree[v].size() > (int)sub_tree[u].size())
			std::swap(sub_tree[u], sub_tree[v]);
		for (auto& x : sub_tree[v])
			sub_tree[u].insert(x);
	}

	ans[u] = (int)sub_tree[u].size() - (sub_tree[u].order_of_key(arr[u]) + 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);

	cin >> V;
	arr.resize(V + 1);
	ans.resize(V + 1);
	for (int i = 1; i <= V; i++)
		cin >> arr[i];

	vector<int> dummy;
	dummy = arr;
	sort(all(dummy));
	map<int, int> compress;
	for (int i = 1; i <= V; i++)
		compress[dummy[i]] = i;

	for (int i = 1; i <= V; i++) {
		arr[i] = compress[arr[i]];
	}

	for (int b = 2; b <= V; b++) {
		cin >> a;
		tr[a].push_back(b);
	}

	dfs(1, -1);

	for (int i = 1; i <= V; i++)
		cout << ans[i] << "\n";

	return 0;
}
