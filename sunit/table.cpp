#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int variations = 0;
int N;
int Al, Bl;
unordered_map<int, int> A, B;

void fillTable(int a, int b, int n) {
	cout << a << " " << b << " "<< n << endl;
	if (a < N) {
		if (A.find(n) != A.end()) {
			// if (B.find(n) == B.end())
			fillTable(a+1, b, n+1);
		}
		else if (B.find(n) != B.end()) {
			if (a > b)
				fillTable(a, b+1, n+1);
		}
		else {
			if (a > b)
				fillTable(a, b+1, n+1);
			fillTable(a+1, b, n+1);
		}
	}
	else {
		if (A.find(n) == A.end()) {
			if (n!=2*N){
				if (b < N)
					fillTable(a, b+1, n+1);
			}
			else {
				variations = (variations+1)%998244353;
			}
		}
	}
	return;
}

int main() {
	cin >> N;
	cin >> Al;
	for (int i = 0; i < Al; i++) {
		int x;
		cin >> x;
		A[x] = 1;
	}
	cin >> Bl;
	for (int i = 0; i < Bl; i++) {
		int x;
		cin >> x;
		B[x] = 1;
	}

	fillTable(0, 0, 1);
	cout << variations << endl;

	return 0;
}