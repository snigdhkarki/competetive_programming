#include <iostream>
#include <algorithm>

using namespace std;

int n;
int perm = 0;

void solve(int ai, int bi, int k, int r1, int r2) {
	if (k == 2 * n){
		perm++;
		return;
	}
	if (ai == bi) {
		solve(ai + 1, bi, k + 1, k, r2);
		return;
	}
	if (k > r1) {
		solve(ai + 1, bi, k + 1, k, r2);
	}
	if (k > r2) {
		solve(ai, bi + 1, k + 1, r1, k);
	}
}

int main() {
	cin >> n;
	int al, bl;

	cin >> al;
	if (al > n) {
		cout << 0;
		return 0;
	}
	int a[al];
	for (int i = 1; i < al; i++) {
		cin >> a[i];
	}

	cin >> bl;
	if (bl > n) {
		cout << 0;
		return;
	}
	int b[bl];
	for (int i = 1; i < bl; i++) {
		cin >> b[i];
	}

	sort(a, a + al);
	sort(b, b + bl);

	int ai = 1, bi = 0;
	solve(ai, bi, 2, 1, 0);

	cout << perm;

}