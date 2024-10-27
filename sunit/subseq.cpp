#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int num[n];
	int longest[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		longest[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int most = 0;
		for (int j = i + 1; j < n; j++) {
			if (num[i] < num[j]) {
				if (longest[j] > most)
					most = longest[j];
			}
		}
		longest[i] += most;
	}

	for ( int i = 0; i < n; i++) {
		cout << longest[i] << " ";
	}
	cout << endl;
	return 0;
}