// Problem: Inversion Count
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/INVCNT/
// Memory Limit: 1536 MB
// Time Limit: 3599 ms

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, x;
	cin >> T;
	while (T--) {
		cin >> N;

		indexed_set<int> cache;
		ll ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> x;
			cache.insert(x);
			ans += 1ll * ((int)cache.size() - cache.order_of_key(x) - 1);
		}
		cout << ans << "\n";
	}

	return 0;
}
