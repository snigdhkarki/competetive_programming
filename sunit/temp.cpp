#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int main() {
    std::string input = "aebqd";
    std::vector<int> indices = {4, 2, 1}; // Indices of characters to sort

    sortSubsequenceInPlace(input, indices);

    std::cout << "Modified String: " << input << std::endl; // Outputs the modified string

    return 0;
}
