// Problem: Give Away
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GIVEAWAY/
// Memory Limit: 1536 MB
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

const int MAXN = 1e5 + 5;
const int block_sz=1200;
int arr[5 * MAXN];
int N, Q, t, a, b, c;
vector<int> blocks[450];

int binarySearch(int idx, int x) {
	int start = 0, end = blocks[idx].size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (blocks[idx][mid] == x)
			return mid;
		else if (blocks[idx][mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		blocks[i / block_sz].push_back(arr[i]);
	}
	
	for (int i = 0; i < 450; i++)
		sort(all(blocks[i]));

	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> t >> a >> b;
		if (t == 0) {
			cin >> c;
			a--, b--;
			int L = a / block_sz;
			int R = b / block_sz;
			int ans = 0;
			if (L == R) {
				for (int i = a; i <= b; i++) {
					if (arr[i] >= c)
						ans++;
				}
			} else {
				for (int i = a; i < (L + 1)*block_sz; i++) {
					if (arr[i] >= c)
						ans++;
				}

				for (int i = L + 1; i < R; i++) {
					ans += blocks[i].size() - (lower_bound(all(blocks[i]), c) - blocks[i].begin());
				}
				for (int i = R * block_sz; i <= b; i++) {
					if (arr[i] >= c)
						ans++;
				}
			}
			cout << ans << "\n";
		} else {
			a--;
			int blk = a / block_sz;
			int idx = binarySearch(blk, arr[a]);
			blocks[blk][idx] = b;
			arr[a] = b;

			sort(all(blocks[blk]));
		}
	}


	return 0;
}
