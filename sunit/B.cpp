#include <iostream>
#include <algorithm>

using namespace std;

void solve(int n, int k) {
	int cans[n];
	for (int i = 0; i < n; i++) {
		cin >> cans[i];
	}
	sort(cans, cans + n);
	int currentindex = 0, subtract = 0;
	unsigned long long removed = 0, presses = 0, removable = 0;
	while (1){
		removable = (cans[currentindex] - subtract) * (n - currentindex);
		if (removed + removable >= k) {
			presses += (k - removed);
			break;
		}
		else {
			removed += removable;
			presses += removable;
			subtract = cans[currentindex];
		}
		while (cans[currentindex] - subtract == 0) {
			presses++;
			currentindex++;
		}
	}
	cout << presses << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		solve(n , k);
	}
}