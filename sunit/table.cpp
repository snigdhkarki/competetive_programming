#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int perm = 0;
vector<int> a;
vector<int> b;
int al, bl;

void solve(int r1i, int r2i, int k, int ai, int bi) {
	// cout << r1i << r2i << k << ai << bi << endl;

	if (k == 2 * n){
		if (ai < al && a[ai] == k)
			return;
		perm++;
		return;
	}
	if (r1i == r2i) {
		if (bi < bl && b[bi] == k)
			return;
		if (ai < al && a[ai] == k) {
			solve(r1i + 1, r2i, k + 1, ai++, bi);
		}
		else {
			solve(r1i + 1, r2i, k + 1, ai, bi);
		}
		return;
	}

	if (r1i < n) {
		// cout << "c1" << k << a[ai] << b[bi] <<endl;
		if (bi < bl && b[bi] == k) {}
		else {
			if (ai < al && a[ai] == k) {
				solve(r1i + 1, r2i, k + 1, ai + 1, bi);
			}
			else {
				solve(r1i + 1, r2i, k + 1, ai, bi);
			}
		}
	}

	if (r2i < n) {
		// cout << "c2" << k << a[ai] << b[bi] <<endl;
		if (ai < al && a[ai] == k) {}
		else {
			if (bi < bl && b[bi] == k) {
				solve(r1i, r2i + 1, k + 1, ai, bi + 1);
			}
			else {
				solve(r1i, r2i + 1, k + 1, ai, bi);
			}
		}
	}
}

int main() {
	cin >> n;

	cin >> al;
	if (al > n) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < al; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	cin >> bl;
	if (bl > n) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < bl; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (b[0] == 1) {
		cout << 0;
		return 0;
	}

	int r1i = 1, r2i = 0;
	solve(r1i, r2i, 2, 0, 0);

	cout << perm << endl;

}