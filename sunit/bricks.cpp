#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

//source chatgpt
using namespace std;

struct Stack {
    int top; // The length of the top brick in the stack
    list<int> bricks; // List to store bricks in the stack
};

int main() {
    int N;
    long long x;
    cin >> N >> x;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the brick lengths
    sort(A.begin(), A.end());

    // This will hold our stacks
    vector<Stack> stacks;

    // Process each brick
    for (int i = 0; i < N; ++i) {
        int current_brick = A[i];

        // Try to place it in an existing stack
        bool placed = false;
        for (Stack &s : stacks) {
            if (current_brick + x <= s.top) {
                s.bricks.push_back(current_brick);
                s.top = current_brick; // Update the top of the stack
                placed = true;
                break;
            }
        }

        // If it wasn't placed, create a new stack
        if (!placed) {
            Stack new_stack;
            new_stack.top = current_brick;
            new_stack.bricks.push_back(current_brick);
            stacks.push_back(new_stack);
        }
    }

    // Output the result
    cout << stacks.size() << endl;
    for (const Stack &s : stacks) {
        cout << s.bricks.size() << " ";
        for (auto it = s.bricks.rbegin(); it != s.bricks.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
