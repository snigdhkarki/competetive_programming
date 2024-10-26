#include <iostream>
#include <algorithm>

using namespace std;

class range{
public:
	int start;
	int end;

	range() {}
	
	range(int s, int e) {
		start = s;
		end = e;
	}

	bool operator<(const range& other) const {
		return start < other.start;
	}
};

int main() {
	int n;
	cin >> n;

	int start1 = 100, start2 = -100;
	int end1 = 100, end2 = -100;

	range arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
		if (arr[i].start < start1) {
			start1 = arr[i].start;
			end1 = arr[i].end;
		}
		else if (arr[i].start == start1 && arr[i].end < end1) {
			start1 = arr[i].start;
			end1 = arr[i].end;
		}
		if (arr[i].end > end2) {
			start2 = arr[i].start;
			end2 = arr[i].end;
		}
		else if (arr[i].end == end2 && arr[i].start > start2) {
			start2 = arr[i].start;
			end2 = arr[i].end;
		}
	}

	for (int i = 0; i < n; i++) {
		int start = arr[i].start;
		int end = arr[i].end;
		int news1 = start1, newe1 = end1, news2 = start2, newe2 = end2;
		bool hasans = false;

		if (start > start1) 
			news1 = start;
		if (end < end1)
			newe1 = end;
		hasans = (news1 <= newe1);	
		if (hasans) {
			// cout << hasans << news1 << newe1 << " fridge 1" <<endl;
			start1 = news1;
			end1 = newe1;
			continue;
		}

		if (start > start2) 
			news2 = start;
		if (end < end2)
			newe2 = end;
		hasans = (news2 <= newe2);	
		if (hasans) {
			// cout << hasans << news2 << newe2 << " fridge 2" << endl;
			start2 = news2;
			end2 = newe2;
			continue;
		}
		if (!hasans) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << start1 << " " << start2 << endl;
	return 0;
}