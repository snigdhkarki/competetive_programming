#include <iostream>

using namespace std;

int main() {
	long long n;
	int k;
	cin >> n >> k;
	bool touched[n];
	for (int i = 0; i < n; i++){
		touched[i] = false;
	}
	int e[k];
	for (int i = 0; i < k; i++) {
		cin >> e[i];
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++){
			if (i % e[j] == 0)
				touched[i] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (touched[i] == true)
			ans++;
	}

	cout << ans << endl;
	return 0;
}