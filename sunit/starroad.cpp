#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stars;

int main() {
	int n;
	cin >> n;

	int count[n];
	vector<int> edge[n];
	class ext {
	public:
		int index;
		ext(int i) : index(i) {}

		bool operator<(const ext& other) const {
			return stars[index] < stars[other.index];
		}
	};

	for(int i = 0; i < n; i++) {
		int st;
		cin >> st;
		stars.push_back(st);
		count[i] = 0;
	}

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		count[a]++;
		count[b]++;
	}

	vector<ext> extvert;

	for (int i = 0; i < n; i++) {
		if (count[i] == 1) {
			extvert.push_back(ext(i));
		}
	}

	sort(extvert.begin(), extvert.end());
	//bfs
	queue<int> q;
	
}