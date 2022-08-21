#include <bits/stdc++.h>
using namespace std;

class CraftyCarpenter {
private:
	int N;
	vector<int> cabinetSizes;
	unordered_map<int, int> cabinetAvailableSpace;
	unordered_map<int, int> itemCabinetNum;
	set<int> availableCabinets;

public:
	CraftyCarpenter() {

		string cabinetInput;
		getline(cin, cabinetInput);
		int num = 0;
		for (auto& ch : cabinetInput) {
			if (ch == ' ') {
				cabinetSizes.push_back(num);
				num = 0;
			} else {
				num = num * 10 + (ch - '0');
			}
		}

		if (cabinetInput != "")
			cabinetSizes.push_back(num);

		N = (int)cabinetSizes.size();

		for (int i = 1; i <= N; i++) {
			availableCabinets.insert(i);
			cabinetAvailableSpace[i] = cabinetSizes[i - 1];
		}
	}

	int getNearestAvailableCabinet() {
		if (availableCabinets.empty())
			return -1;

		return *availableCabinets.begin();
	}

	void addItemToCabinetHelper(int itemNum, int cabinetNum) {
		cabinetAvailableSpace[cabinetNum]--;
		itemCabinetNum[itemNum] = cabinetNum;

		if (cabinetAvailableSpace[cabinetNum] == 0) {
			availableCabinets.erase(cabinetNum);
		}
	}

	void removeItemFromCabinet(int itemNum, int cabinetNum) {
		cabinetAvailableSpace[cabinetNum]++;
		itemCabinetNum.erase(itemNum);

		if (cabinetAvailableSpace[cabinetNum] == 1) {
			availableCabinets.insert(cabinetNum);
		}
	}

	void addItemOutsideShop(int itemNum) {
		itemCabinetNum[itemNum] = -1;
	}

	void addItemToCabinet(int itemNum) {

		if (itemCabinetNum.count(itemNum)) {
			int cabinetNum = itemCabinetNum[itemNum];
			cout << cabinetNum << "\n";
			removeItemFromCabinet(itemNum, cabinetNum);
			addItemToCabinetHelper(itemNum, cabinetNum);
			return;
		}

		int cabinetNum = getNearestAvailableCabinet();

		if (cabinetNum == -1) {
			cout << "OUTSIDE\n";
			addItemOutsideShop(itemNum);
		} else {
			cout << "NEW\n";
			addItemToCabinetHelper(itemNum, cabinetNum);

		}
	}

	bool isValid(int itemNum) {
		return itemNum >= 0 && itemNum <= INT_MAX;
	}
};


int main() {

	CraftyCarpenter craftyCarpenter;

	int K, itemNum;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> itemNum;

		if (!craftyCarpenter.isValid(itemNum)) {
			cout << "INPUT_ERROR\n";
			continue;
		}

		craftyCarpenter.addItemToCabinet(itemNum);

	}


	return 0;
}
