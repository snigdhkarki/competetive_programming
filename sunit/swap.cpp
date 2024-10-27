#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class CharCounter {
public:
    // Constructor to initialize the data structure with the string
    CharCounter(const std::string& str) {
        // Count characters
        for (char ch : str) {
            countMap[ch]++;
        }

        // Store distinct characters in a vector
        for (const auto& entry : countMap) {
            distinctChars.push_back(entry.first);
        }

        // Sort the distinct characters in descending order
        std::sort(distinctChars.begin(), distinctChars.end(), std::greater<char>());
    }

    // Function to get the count of a specific character
    int getCount(char ch) const {
        auto it = countMap.find(ch);
        if (it != countMap.end()) {
            return it->second; // Return the count if found
        }
        return 0; // Return 0 if the character is not present
    }

    // Function to get the nth largest character
    char getNthLargest(int n) const {
        if (n < 1 || n > distinctChars.size()) {
            throw std::out_of_range("Invalid position for nth largest character.");
        }
        return distinctChars[n - 1]; // n is 1-based
    }

    // Function to print all distinct characters and their counts
    void printCounts() const {
        for (const auto& entry : countMap) {
            std::cout << "Character: '" << entry.first << "', Count: " << entry.second << std::endl;
        }
    }

private:
    std::unordered_map<char, int> countMap; // Map to hold counts of each character
    std::vector<char> distinctChars;         // Vector to hold distinct characters in sorted order
};

void sortSubsequenceInPlace(std::string& str, const std::vector<int>& indices) {
    // Create a vector to hold the characters at the specified indices
    std::vector<char> subsequence;

    // Extract characters from the original string based on the given indices
    for (int index : indices) {
        if (index >= 0 && index < str.length()) {
            subsequence.push_back(str[index]);
        }
    }

    // Sort the extracted characters
    std::sort(subsequence.begin(), subsequence.end());

    // Place the sorted characters back into the original string at the specified indices
    for (size_t i = 0; i < indices.size(); ++i) {
        str[indices[i]] = subsequence[i];
    }
}

using namespace std;

int main() {
	string N;
	int k;
	cin >> N >> k;
  CharCounter charCounter(N);

	char largest = charCounter.getNthLargest(1);
	int nthlarge = 1;
	int largestavail = charCounter.getCount(largest);
	vector<int> tosort;
	vector<vector<int>> tosortlist;
	int nsize = N.length();
	int startindex = 0;
	int endindex = nsize - 1;

	for (int i = 0; i < k; i++) {
		while(N[startindex] == largest)
			startindex++;
		while(N[endindex] != largest)
			endindex--;
		if (startindex >= endindex) {
			nthlarge++;
			largest = charCounter.getNthLargest(nthlarge);
			largestavail = charCounter.getCount(largest);
			if (tosort.size() != 1) {
				tosortlist.push_back(tosort);
			}
			tosort.clear();
			endindex = nsize - 1;
			while(N[startindex] == largest)
				startindex++;
			while(N[endindex] != largest)
				endindex--;
		}
		char temp = N[startindex];
		N[startindex] = N[endindex];
		N[endindex] = temp;
		tosort.push_back(endindex);
		startindex++;
		endindex--;
		largestavail--;
		
		if (largestavail == 0) {
			nthlarge++;
			largest = charCounter.getNthLargest(nthlarge);
			largestavail = charCounter.getCount(largest);
			if (tosort.size() != 1) {
				tosortlist.push_back(tosort);
			}
			tosort.clear();
			endindex = nsize - 1;
		}
		// cout << N << endl;
	}
	for (vector<int> toso: tosortlist) {
		// for (int i: toso)
		// 	cout << i << " ";
		sortSubsequenceInPlace(N, toso);
	}
	cout << N << endl;
}