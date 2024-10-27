#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

vector<int> ans;
unordered_set<string> dissubstr;
string S;

void search(string& T, vector<int> searcharr) {
	vector<int> newarr;
	for (int i : searcharr) {
		if (S.substr(i, T.length()) == T){
			newarr.push_back(i);
		}
	}

	// cout << T;
	int connectedstart = newarr[0];
	int connectedend = newarr[0];
	int remaining = S.length();
	// cout << remaining << " ";
	int regions = 0;
	for (int i : newarr) {
		int n = S.length();
		if (i < connectedend) {
			connectedend = i + T.length();
		}
		else {
			regions++;
			remaining = remaining - (connectedend - connectedstart);
			// cout << remaining << " ";
			connectedstart = i;
			connectedend = i + T.length();
		}
	}
	remaining = remaining - (connectedend - connectedstart);
	// cout << remaining << " ";
	regions = regions + remaining;
	// cout << regions << endl;
	if (ans[regions - 1] == 0 or T.length() < ans[regions - 1]){
		ans[regions - 1] = T.length();
	}

	for (int i : newarr) {
		if (i+T.length() >= S.length())
			continue;
		T.push_back(S.at(i + T.length()));
		if (dissubstr.count(T) == 0){
			search(T, newarr);
			dissubstr.insert(T);
		}
		T.pop_back();
	}
}

int main() {
	unordered_set<char> distinct;
	getline(cin, S);
	for (char c : S) {
		distinct.insert(c);
	}
	int n = S.length();
	vector<int> startarr;
	for (int i = 0; i < n; ++i) {
		startarr.push_back(i);
		ans.push_back(0);
	}
	string T;
	for (char dc : distinct) {
		T.push_back(dc);
		search(T, startarr);
		T.pop_back();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}