#include <iostream>
#include <algorithm>

using namespace std;

long long l;

class coordinates {
public:
	long long x, y;
	coordinates() {}
	coordinates(long long x, long long y) : x(x), y(y) {}

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
	long long n, m;
	cin >> l >> n >> m;
	coordinates a[n];
	coordinates b[m];
	for (long long i = 0; i < n; i++) {
		char c;
		long long coord;
		cin >> c >> coord;
		if (c == 'U') {
			a[i] = coordinates(coord, l);
		} else {
			a[i] = coordinates(l, coord);
		}
	}
	for (long long i = 0; i < m; i++) {
		char c;
		long long coord;
		cin >> c >> coord;
		if (c == 'U') {
			b[i] = coordinates(coord, l);
		} else {
			b[i] = coordinates(0, coord);
		}
	}
	sort(a, a + n);
	sort(b, b + m);
	// for (long long i = 0; i < n; i++) {
	// 	cout << a[i].x << " " << a[i].y << endl;
	// }
	// for (long long i = 0; i < m; i++) {
	// 	cout << b[i].x << " " << b[i].y << endl;
	// }

	long long searchstart = 0;
	for (long long i = 0; i < n; i++) {
		if (a[i].x == l) {
			searchstart = i + 1;
		}
		else {
			break;
		}
	}

	long long intersected = 0;
	long long count = n + m * searchstart + 1;
	// cout << "count start:" << count << endl;
	for (long long j = 0; j < m; j++) {
		count += intersected;
		for (long long i = searchstart; i < n; i++) {
			if (intersect(a[i], b[j])) {
				intersected++;
				count++;
				if (i == n - 1){
					searchstart = i + 1;
				}
			}
			else {
				searchstart = i;
				break;
			}
		}
		count++;
		// cout << long intersected<<searchstart<<"count:" << count << endl;
	}
	cout << count << endl;
	return 0;
}