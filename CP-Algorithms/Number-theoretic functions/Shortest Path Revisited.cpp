// Problem: Shortest Path Revisited
// Contest: HackerEarth - Algorithms - Graphs - Shortest Path Algorithms
// URL: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> graph[MAXN];
ll cost[MAXN][20];

void dijkstra(int src, int K) {

	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>> pq;

	cost[src][0] = 0;
	pq.push({0ll, {src, 0}});

	while (!pq.empty()) {
		int curr_city = pq.top().second.first;
		int offers = pq.top().second.second;
		ll curr_cost = -pq.top().first;
		pq.pop();

		if (cost[curr_city][offers] != curr_cost)
			continue;

		for (auto p : graph[curr_city]) {
			int nxt_city = p.first;
			ll wt = (long long)p.second;

			// I do not use special offer
			if (cost[nxt_city][offers] == -1) {
        
				cost[nxt_city][offers] = cost[curr_city][offers] + wt;
				pq.push({ -cost[nxt_city][offers], {nxt_city, offers}});

			} else if (cost[nxt_city][offers] > cost[curr_city][offers] + wt) {
        
				cost[nxt_city][offers] = cost[curr_city][offers] + wt;
				pq.push({ -cost[nxt_city][offers], {nxt_city, offers}});

			}

			if (offers == K)
				continue;

			// If I use special offer
			if (cost[nxt_city][offers + 1] == -1) {
        
				cost[nxt_city][offers + 1] = cost[curr_city][offers];
				pq.push({ -cost[nxt_city][offers + 1], {nxt_city, offers + 1}});

			} else if (cost[nxt_city][offers + 1] > cost[curr_city][offers]) {
        
				cost[nxt_city][offers + 1] = cost[curr_city][offers];
				pq.push({ -cost[nxt_city][offers + 1], {nxt_city, offers + 1}});

			}
		}
	}
}

int main() {
	int V, E, K, a, b, w;
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}

	memset(cost, -1, sizeof(cost));
	dijkstra(1, K);

	for (int i = 1; i <= V; i++) {
		ll result = 1e18;
		for (int j = 0; j <= K; j++) {
			if (cost[i][j] == -1)
				continue;
			result = min(result, cost[i][j]);
		}
		cout << result << " ";
	}

	return 0;
}


