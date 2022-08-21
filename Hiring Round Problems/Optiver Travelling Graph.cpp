#include <bits/stdc++.h>
using namespace std;

class TravellingGraph {
private:
	vector<pair<int, int>> graph[26];
	map<pair<int, int>, int> edgeMap;
	int src, dest, allowedTime;

	void print_error(int num) {
		if (num == 1) {
			cout << "E1\n";
		}
		else if (num == 2) {
			cout << "E2\n";
		}
		else {
			cout << "E3\n";
		}
		exit(0);
	}

	bool isGraphDisconnected(vector<int>& dist) {
		int N = (int)dist.size();
		for (int i = 0; i < N; i++) {
			if (!graph[i].empty() && dist[i] == INT_MAX)
				return true;
		}
		return false;
	}

	void print_path(stack<int>& path) {
		while (!path.empty()) {
			cout << (char)('A' + path.top());
			path.pop();
			if (!path.empty())
				cout << "->";
		}
	}

public:
	void getPoints() {
		string input;
		getline(cin, input);
		int N = (int)input.size();
		int i = 0;
		if (N < 6)
			print_error(1);

		while (i < N) {
			if (input[i] < 'A' || input[i] > 'Z') {
				i++;
				print_error(1);
			} else {
				src = input[i++] - 'A';

				if (graph[src].empty()) {
					print_error(2);
				}
			}

			if (input[i++] != '-' || input[i++] != '>') {
				print_error(1);
			}

			if (input[i] < 'A' || input[i] > 'Z') {
				i++;
				print_error(1);
			} else {
				dest = input[i++] - 'A';

				if (graph[dest].empty()) {
					print_error(2);
				}
			}

			if (input[i++] != ',') {
				print_error(1);
			}

			while (i < N) {
				allowedTime = allowedTime * 10 + (input[i++] - '0');
			}
		}
	}
	void makeGraph() {
		string input;
		getline(cin, input);
		int N = (int)input.size();
		int i = 0, u, v, wt;
		while (i + 6 <= N) {
			if (input[i++] != '[') {
				print_error(1);
			}
			if (input[i] < 'A' || input[i] > 'Z') {
				i++;
				print_error(1);
			} else {
				u = input[i++] - 'A';
			}

			if (input[i++] != ',') {
				print_error(1);
			}

			if (input[i] < 'A' || input[i] > 'Z') {
				i++;
				print_error(1);
			} else {
				v = input[i++] - 'A';
			}

			if (input[i++] != ',') {
				print_error(1);
			}

			wt = 0;
			while (i < N && input[i] != ']') {
				wt = wt * 10 + (input[i++] - '0');
			}

			if (u > v)
				swap(u, v);

			if (edgeMap.count({u, v}) && edgeMap[ {u, v}] != wt) {
				print_error(2);
			}

			graph[u].push_back({v, wt});
			graph[v].push_back({u, wt});
			edgeMap[ {u, v}] = wt;

			if (input[i++] != ']') {
				print_error(1);
			}
			i++;
		}
	}

	void dijkstraAlgorithm() {
		vector<int> dist(26, INT_MAX);
		vector<int> prevNode(26, -1);
		vector<int> possiblePaths;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		dist[src] = 0;
		pq.push({0, src});

		int u, dist_u, v, wt;
		while (!pq.empty()) {
			u = pq.top().second;
			dist_u = pq.top().first;
			pq.pop();

			if (dist[u] != dist_u)
				continue;

			for (auto& p : graph[u]) {
				v = p.first;
				wt = p.second;

				if (dist[v] > dist[u] + wt) {
					dist[v] = dist[u] + wt;
					prevNode[v] = u;
					pq.push({dist[v], v});
					if (v == dest) {
						possiblePaths.clear();
						possiblePaths.push_back(u);
					}
				} else if (v == dest && dist[v] == dist[u] + wt) {
					possiblePaths.push_back(u);
				}
			}
		}

		if (dist[dest] > allowedTime || (int)possiblePaths.size() > 1 || isGraphDisconnected(dist)) {
			print_error(3);
		}

		stack<int> path;
		int node = dest;
		while (node != -1) {
			path.push(node);
			node = prevNode[node];
		}

		print_path(path);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	TravellingGraph travellingGraph;
	travellingGraph.makeGraph();
	travellingGraph.getPoints();
	travellingGraph.dijkstraAlgorithm();

	return 0;
}
