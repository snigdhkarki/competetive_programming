#include <iostream>
#include <algorithm>

class elem {
public:
	int v1;
	int v2;

	elem() {}
	elem(int v1, int v2) : v1(v1), v2(v2) {}

	bool operator < (const elem& other) const {
		int score1 = 0, score2 = 0;
		if (v1 > other.v1) {
			score1++;
		}
		else if (v1 < other.v1) {
			score2++;
		}
		if (v2 > other.v2) {
			score1++;
		}
		else if (v2 < other.v2) {
			score2++;
		}
		if (v1 > other.v2) {
			score1++;
		}
		else if (v1 < other.v2) {
			score2++;
		}
		if (v2 > other.v1) {
			score1++;
		}
		else if (v2 < other.v1) {
			score2++;
		}
		return score1 < score2;
	}
};

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		elem v[n];
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			elem e(a, b);
			v[i] = e;
		}
		sort(v, v + n);
		for (int i = 0; i < n; i++) {
			cout << v[i].v1 << " " << v[i].v2 << " ";
		}
		cout << endl;
	}
	return 0;
}