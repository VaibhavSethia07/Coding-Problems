// Problem: D - Pond
// Contest: AtCoder - AtCoder Beginner Contest 203（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc203/tasks/abc203_d?lang=en
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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

int solve(int guess, vector<vector<int>>& grid, int N, int K) {
	vector<vector<int>> bin(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bin[i][j] = grid[i][j] <= guess;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i - 1 >= 0)
				bin[i][j] += bin[i - 1][j];
			if (j - 1 >= 0)
				bin[i][j] += bin[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0)
				bin[i][j] -= bin[i - 1][j - 1];
		}
	}

	int mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = bin[i][j];
			if (i - K >= 0)
				sum -= bin[i - K][j];
			if (j - K >= 0)
				sum -= bin[i][j - K];
			if (i - K >= 0 && j - K >= 0)
				sum += bin[i - K][j - K];
			mx = max(mx, sum);
		}
	}

	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> grid(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	int start = 0, end = 1e9, ans = 1e9;
	while (start <= end) {
		int guess = start + (end - start) / 2;
		if (solve(guess, grid, N, K) >= (K * K + 1) / 2) {
			ans = guess;
			end = guess - 1;
		} else {
			start = guess + 1;
		}
	}

	cout << ans << "\n";
	return 0;
}
