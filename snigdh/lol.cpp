#include <iostream>
#include <vector>
#include <utility> // For std::pair

class Pair {
public:
    int l; // First integer
    int r; // Second integer

    Pair(int left, int right) : l(left), r(right) {}

    // Define less than operator for sorting
    bool operator<(const Pair& other) const {
        if (l == other.l) {
            return r < other.r;
        }
        return l < other.l;
    }
};

std::vector<Pair> merge_sort(const std::vector<Pair>& arr);
std::vector<Pair> merge(const std::vector<Pair>& left, const std::vector<Pair>& right);

int main() {
    std::vector<Pair> d;
    int n;
    
    std::cin >> n; // Read number of pairs
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b; // Read each pair
        d.emplace_back(a, b); // Construct Pair and add to vector
    }

    // Sorting using merge sort
    std::vector<Pair> sorted_arr = merge_sort(d);
    
    // Output the sorted pairs
    for (const auto& pair : sorted_arr) {
        std::cout << pair.l << " " << pair.r << " ";
    }

    return 0;
}

std::vector<Pair> merge_sort(const std::vector<Pair>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    size_t mid = arr.size() / 2;
    std::vector<Pair> left_half = merge_sort(std::vector<Pair>(arr.begin(), arr.begin() + mid));
    std::vector<Pair> right_half = merge_sort(std::vector<Pair>(arr.begin() + mid, arr.end()));

    return merge(left_half, right_half);
}

std::vector<Pair> merge(const std::vector<Pair>& left, const std::vector<Pair>& right) {
    std::vector<Pair> merged;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) { // Use the comparison defined in Pair
            merged.push_back(left[i]);
            ++i;
        } else {
            merged.push_back(right[j]);
            ++j;
        }
    }

    // Append any remaining elements
    merged.insert(merged.end(), left.begin() + i, left.end());
    merged.insert(merged.end(), right.begin() + j, right.end());

    return merged;
}
