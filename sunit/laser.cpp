#include <iostream>
#include <algorithm>

using namespace std;

int l;

class coordinates {
public:
	int x, y;
	coordinates() {}
	coordinates(int x, int y) : x(x), y(y) {}

	bool operator<(const coordinates& other) const {
		if (x == other.x) {
			if (x == 0) {
				return y > other.y;
			}
			else {
				return y < other.y;
			}
		}
		else {
			return x > other.x;
		}
	}
};

bool intersect(coordinates c1, coordinates c2) {
	return c1.x > c2.x;
}

int main() {
	int n, m;
	cin >> l >> n >> m;
	coordinates a[n];
	coordinates b[m];
	for (int i = 0; i < n; i++) {
		char c;
		int coord;
		cin >> c >> coord;
		if (c == 'U') {
			a[i] = coordinates(coord, l);
		} else {
			a[i] = coordinates(l, coord);
		}
	}
	for (int i = 0; i < m; i++) {
		char c;
		int coord;
		cin >> c >> coord;
		if (c == 'U') {
			b[i] = coordinates(coord, l);
		} else {
			b[i] = coordinates(0, coord);
		}
	}
	sort(a, a + n);
	sort(b, b + m);
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].x << " " << a[i].y << endl;
	// }
	// for (int i = 0; i < m; i++) {
	// 	cout << b[i].x << " " << b[i].y << endl;
	// }

	int searchstart = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].x == l) {
			searchstart = i + 1;
		}
		else {
			break;
		}
	}

	int intersected = 0;
	int count = n + m * searchstart + 1;
	cout << "count start:" << count << endl;
	for (int j = 0; j < m; j++) {
		count += intersected;
		for (int i = searchstart; i < n; i++) {
			if (intersect(a[i], b[j])) {
				intersected++;
				count++;
			}
			else {
				searchstart = i;
				break;
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}