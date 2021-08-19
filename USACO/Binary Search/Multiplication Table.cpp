// Problem: Multiplication Table
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2422
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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

bool isValidMid(ll mid, ll N) {
	ll cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt += min(N, mid / i);
	}
	return cnt >= ((N * N) / 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N;
	cin >> N;

	ll start = 1, end = N * N, ans = LLONG_MAX;
	while (start <= end) {
		ll mid = start + (end - start) / 2;
		if (isValidMid(mid, N)) {
			ans = mid;
			end = mid - 1;
		} else
			start = mid + 1;
	}
	cout << ans;
	return 0;
}
