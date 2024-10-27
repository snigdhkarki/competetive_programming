#include <iostream>
#include <algorithm>

using namespace std;

int findLargestSmallerOrEqualIndex(int arr[], int size, int x) {
    int left = 0, right = size - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int getCost(int arr[], int l, int r) {
	int cost = 0;
	if ((l - r + 1) % 2 == 0) {
		cost = arr[l] + arr[r];
		l++;
		r--;
	}
	else {
		cost = arr[r];
		r--;
	}
	while(l < r){
		int newcost = arr[l] + arr[r];
		if (newcost > cost)
			cost = newcost;
		l++;
		r--;
	}
	return cost;
}

int main() {
	int n, q;
	cin >> n >> q;
	int A[n];
	pair<int, int> Q[q];
	long long ans[q];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	for (int i = 0; i < q; i++){
		int val;
		cin >> val;
		Q[i] = make_pair(val, i);
		ans[i] = 0;
	}
	sort(Q, Q+q);
	int checkedInd = -1;
	for (int i = 0; i < q; i++){
		int last = findLargestSmallerOrEqualIndex(A, n, Q[i].first);
		for (int ed = checkedInd + 1; ed <= last; ed++) {
			for (int st = 0; st < ed; st++){
				if (getCost(A, st, ed) <= Q[i].first)
					ans[i] += (A[ed] - A[st]);
			}
		}
	}
	long long final[q];
	for (int i = 0; i < q; i++) {
		final[Q[i].second] = ans[i];
	}
	for (int i = 0; i < q; i++) {
		cout << final[i] << endl;
	}
	return 0;
}