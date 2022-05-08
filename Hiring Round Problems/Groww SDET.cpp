/*Problem:
You are given N strings consisting of small letter English alphabets.2 strings are considered to have the same prefix if the first 2 (or more)
characters of both the strings match.

Your are allowed to do the following operation on a string at two most twice:
	Remove the last character of the string and concatenate it to the front.

For example, str="abcde", you can make str="eabcd" (by doing the operation 1 time).

Determine the maximum number of strings that can have the same prefix if you are allowed to perform the given operation M times.

Note: Strings of length 1 are not considered to have the same prefix.

Example:
T=1
N=4
M=3
S=["ackerh","hack","hackearth","earth"]

Approach: 3 strings can have the preix 'ha' by applying the
given operation 1 time on 1st string
Therefore the answer is 3

Constraints:
1<=T<=10
1<=N<=1e4
0<=M<=2e4
1<=len(Si)<=10;

Sample Input
1
8
12
mb
okmj
elgmxrwrty
bm
wgescb
lvi
xt
xgtzjk


Sample Output
2

You can get a maximum of 2 strings with the same prefix (mb)
by applying the given operation on the 1st string  1 time.
So the answer is 2.
*/

#include <bits/stdc++.h>
using namespace std;

void preprocess(vector<string>& v, int N) {
	for (int i = 0; i < N; i++) {
		if (v[i].size() > 4) {
			string S = "";
			S += v[i][0];
			S += v[i][1];
			S += v[i][v[i].length() - 2];
			S += v[i][v[i].length() - 1];
			v[i] = S;
		}
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << " ";
	cout << "\n";
}

void solve(vector<string>& v, int N, int M) {
	unordered_map<string, vector<pair<int, int>>> cache;
	vector<string> v0(N), v1(N), v2(N);

	for (int i = 0; i < N; i++) {
		if (v[i].length() == 1)
			continue;
		string S = "";
		S += v[i][0];
		S += v[i][1];
		cout << S << " ";
		v0[i] = S;
		cache[S].push_back({i, 0});
	}
	cout << "\n";

	for (int i = 0; i < N; i++) {
		if (v[i].length() == 1)
			continue;

		string S = "";
		int L = v[i].length();
		if (L == 2) {
			S += v[i][1];
			S += v[i][0];
		} else if (L == 3) {
			S += v[i][2];
			S += v[i][0];
			// S += v[i][1];
		} else {
			S += v[i][3];
			S += v[i][0];
			// S += v[i][1];
			// S += v[i][2];
		}
		cout << S << " ";
		cache[S].push_back({i, 1});
		v1[i] = S;
	}
	cout << "\n";

	for (int i = 0; i < N; i++) {
		if (v[i].length() == 1)
			continue;

		string S = "";
		int L = (int)v[i].length();
		if (L == 2) {
			S += v[i][0];
			S += v[i][1];
		} else if (L == 3) {
			S += v[i][1];
			S += v[i][2];
			// S += v[i][0];
		} else {
			S += v[i][2];
			S += v[i][3];
			// S += v[i][0];
			// S += v[i][1];
		}
		cout << S << " ";
		cache[S].push_back({i, 2});
		v2[i] = S;
	}
	cout << "\n";

	for (auto& p : cache) {
		cout << p.first << ": ";
		for (auto& q : p.second)
			cout << q.second << " ";
		cout << "\n";
	}

	unordered_set<int> store;
	//cost=0
	for (int i = 0; i < N; i++) {
		if (cache[v0[i]].size() < 2)
			continue;

		int j = 1;
		vector<pair<int, int>> arr = cache[v0[i]];
		int L = arr.size();
		if (arr[0].second == 0 && arr[j].second == 0)
			store.insert(arr[0].first);

		while (j < L && arr[j].second == 0) {
			store.insert(arr[j].first);
			j++;
		}
	}

	//cost=1
	for (int i = 0; i < N; i++) {
		if (cache[v1[i]].size() < 2)
			continue;

		int j = 1;
		vector<pair<int, int>> arr = cache[v1[i]];
		int L = arr.size();

		if (arr[0].second == 0) {
			int cnt = 0;
			while (j < L && arr[j].second < 1) {
				j++;
			}
			while (j < L && arr[j].second == 1 && M) {
				if (store.count(arr[j].first)) {
					;
				} else {
					cnt++;
					M--;
					store.insert(arr[j].first);
				}
				j++;
			}
			if (cnt) {
				if (cnt == 1 && store.count(arr[0].first)) {
					store.erase(store.find(arr[0].first));
				} else {
					store.insert(arr[0].first);
				}
			}
		} else if (arr[0].second == 1 && M >= 2) {
			int cnt = 0;
			while (j < L && arr[j].second < 1) {
				j++;
			}
			while (j < L && arr[j].second == 1 && M) {
				if (store.count(arr[j].first)) {
					;
				} else {
					cnt++;
					M--;
					store.insert(arr[j].first);
					if (cnt == 1 && M) {
						M--;
						store.insert(arr[0].first);
					}
				}
				j++;
			}

		}
	}

	//cost=2
	for (int i = 0; i < N; i++) {
		if (cache[v2[i]].size() < 2)
			continue;

		int j = 1;
		vector<pair<int, int>> arr = cache[v2[i]];
		int L = arr.size();

		if (arr[0].second == 0) {
			int cnt = 0;
			while (j < L && arr[j].second < 1) {
				j++;
			}
			while (j < L && arr[j].second == 2 && M >= 2) {
				if (store.count(arr[j].first)) {
					;
				} else {
					cnt++;
					M -= 2;
					store.insert(arr[j].first);
				}
				j++;
			}
			if (cnt) {
				if (cnt == 1 && store.count(arr[0].first)) {
					store.erase(store.find(arr[0].first));
				} else {
					store.insert(arr[0].first);
				}
			}
		} else if (arr[0].second == 1 && M >= 3) {
			int cnt = 0;
			while (j < L && arr[j].second < 2) {
				j++;
			}
			while (j < L && arr[j].second == 2 && M >= 2) {
				if (store.count(arr[j].first)) {
					;
				} else {
					cnt++;
					M -= 2;
					store.insert(arr[j].first);
					if (cnt == 1 && M) {
						M--;
						store.insert(arr[0].first);
					}
				}
				j++;
			}

		} else if (arr[0].second == 2 && M >= 4) {
			int cnt = 0;
			while (j < L && arr[j].second == 2 && M >= 4) {
				if (store.count(arr[j].first)) {
					;
				} else {
					cnt++;
					M -= 2;
					store.insert(arr[j].first);
					if (cnt == 1 && M >= 2) {
						M -= 2;
						store.insert(arr[0].first);
					}
				}
				j++;
			}

		}
	}

	cout << store.size() << "\n";
	for (auto& x : store)
		cout << x << " ";
	cout << "\n";
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<string> v(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		preprocess(v, N);
		solve(v, N, M);
	}
}
