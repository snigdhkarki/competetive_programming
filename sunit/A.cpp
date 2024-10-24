#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		if (a > b ) {
			cout << a << endl;
			continue;
		}
		int x = b - a;
		if (x > a) {
			cout << 0 << endl;
		}
		else {
			cout << a - x << endl;
		}
	}
	return 0;
}