// Problem: Problem 1. Social Distancing
// Contest: USACO - USACO 2020 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1038
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

bool isPossible(vector<pair<ll, ll>>& farms, int M, int N, ll d) {
	ll prev = farms[0].f;
	int cnt = 1;
	int i = 0;
	while (i < M) {
		if (cnt == N)
			return true;
		if (prev + d <= farms[i].s) {
			prev = max(prev + d, farms[i].f);
			cnt++;
		} else
			i++;
	}

	return cnt >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);

	int N, M;
	cin >> N >> M;
	vector<pair<ll, ll>> farms(M);
	for (int i = 0; i < M; i++)
		cin >> farms[i].f >> farms[i].s;
	sort(all(farms));

	ll start = 1, end = 1e18, ans = 1;
	while (start <= end) {
		ll mid = start + (end - start) / 2;
		if (isPossible(farms, M, N, mid)) {
			ans = mid;
			start = mid + 1;
		} else
			end = mid - 1;
	}
	cout << ans;

	return 0;
}
