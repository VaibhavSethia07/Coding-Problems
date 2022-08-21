#include <bits/stdc++.h>
using namespace std;

class TreeOfErrors {
private:
	constexpr static int MAXN = 26;
	int nodesCount = 0;
	int edgesCount = 0;
	vector<vector<int>> tree;
	vector<int> parent;
	vector<int> childrenCount;

	void init() {
		tree.resize(MAXN);
		parent.resize(MAXN, -1);
		childrenCount.resize(MAXN);
	}

	void printError(int num) {
		if (num == 1)
			cout << "E1\n";
		else if (num == 2)
			cout << "E2\n";
		else if (num == 3)
			cout << "E3\n";
		else if (num == 4)
			cout << "E4\n";
		else
			cout << "E5\n";
		exit(0);
	}

	void duplicatePairCheck(int u, int v) {
		if (parent[v] == u)
			printError(2);
	}

	void childrenCountCheck(int u) {
		if (childrenCount[u] > 2)
			printError(3);
	}

	void multipleRootsCheck() {
		int parentCount = 0;
		for (int i = 0; i < MAXN; i++) {
			if (parent[i] == -1 && !tree[i].empty()) {
				parentCount++;
			}
		}

		if (parentCount > 1)
			printError(4);
	}

	void cycleCheck() {
		if (edgesCount >= nodesCount) {
			printError(5);
		}
	}

	void addEdgeToTree(int u, int v) {
		if (parent[u] == -1 && childrenCount[u] == 0)
			nodesCount++;

		if (parent[v] == -1 && childrenCount[v] == 0)
			nodesCount++;

		tree[u].push_back(v);
		tree[v].push_back(u);
		parent[v] = u;
		childrenCount[u]++;
		edgesCount++;

	}

public:
	TreeOfErrors() {
		init();

		string input;
		getline(cin, input);

		int N = (int)input.size();

		int i = 0, u, v;
		while (i + 4 < N) {
			if (input[i++] != '(') {
				printError(1);
			}

			if (input[i] < 'A' || input[i] > 'Z') {
				printError(1);
			} else {
				u = input[i++] - 'A';
			}

			if (input[i++] != ',') {
				printError(1);
			}

			if (input[i] < 'A' || input[i] > 'Z') {
				printError(1);
			} else {
				v = input[i++] - 'A';
			}

			if (u == v)
				printError(1);

			duplicatePairCheck(u, v);
			addEdgeToTree(u, v);
			childrenCountCheck(u);
			cycleCheck();

			if (input[i++] != ')') {
				printError(1);
			}
			i++;
		}

		multipleRootsCheck();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	TreeOfErrors treeOfErrors;

	return 0;
}
