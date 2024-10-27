#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stars;
vector<int> connections;
vector<vector <int>> edge;
vector<int> extvert;
int ans = 0;

int subseq(vector<int>& seq) {
	int n = seq.size();
	int longest[n];
	for (int i = 0; i < n; i++) {
		longest[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int most = 0;
		for (int j = i + 1; j < n; j++) {
			if (stars[seq[i]] < stars[seq[j]]) {
				if (longest[j] > most)
					most = longest[j];
			}
		}
		longest[i] += most;
	}
	int longestseq = 0;
	for ( int i = 0; i < n; i++ ){
		if (longest[i] > longestseq)
			longestseq = longest[i];
	}
	return longestseq;
}

void dfs(int vert, vector<int>& seq) {
	// cout << "dfs" << endl;
	for (int newvert : edge[vert]) {
		// cout << "dfs loop"<< newvert << endl;
		if (seq.size() !=0 && newvert == seq.back()) {
			// cout << "dfs mid" << endl;
			if (connections[vert] == 1) {
				seq.push_back(vert);
				int newans = subseq(seq);
				seq.pop_back();
				if (newans > ans) 
					ans = newans;
				return;
			}
			else {
				continue;
			}
		}
		// cout << "dfs end" << endl;
		seq.push_back(vert);
		dfs(newvert, seq);
		seq.pop_back();
	}
	return;
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int st;
		cin >> st;
		stars.push_back(st);
		connections.push_back(0);
		edge.push_back(vector<int> ());
	}

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
		connections[a - 1]++;
		connections[b - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (connections[i] == 1) {
			extvert.push_back(i);
		}
	}

	// for (int exti : extvert) {
	// 	for (int i : edge[exti]) {
	// 		cout << i;
	// 	}
	// 	cout << endl;
	// }

	for (int exti : extvert) {
		vector<int> seq;
		dfs(exti, seq);
	}

	cout << ans << endl;

	return 0;	
}