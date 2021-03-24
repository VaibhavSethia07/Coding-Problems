#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int n, m, curr_size, num;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];

void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
}

void flood_fill(int r, int c, int num) {

	if (r < 0 || r >= n || c < 0 || c >= m)
		return;

	if (grid[r][c] != num)
		return;

	if (vis[r][c])
		return;

	curr_size++;
	vis[r][c] = 1;

	flood_fill(r + 1, c, num);
	flood_fill(r, c + 1, num);
	flood_fill(r - 1, c, num);
	flood_fill(r, c - 1, num);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> num;
	input();
	cout<<"Connected Component size's: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				curr_size = 0;
				flood_fill(i, j, num);
				if (curr_size >= 1)
					cout << curr_size << "\n";
			}
		}
	}

	return 0;
}

