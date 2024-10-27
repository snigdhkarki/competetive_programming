#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class SegmentTree {
    vector<ll> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;
        
        propagate(node, start, end);
        if (start >= l && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        ll p1 = queryRange(2 * node + 1, start, mid, l, r);
        ll p2 = queryRange(2 * node + 2, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void update(int l, int r, ll val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    ll query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    // Store inverse permutation for type 1 updates
    vector<int> P(N), P_inv(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;  // 0-based indexing
        P_inv[P[i]] = i;  // Store inverse permutation
    }
    
    // Create two segment trees
    SegmentTree regular(N);    // For regular array
    SegmentTree permuted(N);   // For permuted array
    
    vector<ll> results;
    while (Q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--; r--;  // 0-based indexing
        
        if (type < 2) {
            ll c;
            cin >> c;
            
            if (type == 0) {
                // Regular update
                regular.update(l, r, c);
                // Update permuted array accordingly
                vector<pair<int, int>> ranges;
                int curr_start = -1;
                
                // Find continuous ranges in permuted array
                for (int i = l; i <= r; i++) {
                    if (curr_start == -1) curr_start = P_inv[i];
                    else if (P_inv[i] != P_inv[i-1] + 1) {
                        permuted.update(curr_start, P_inv[i-1], c);
                        curr_start = P_inv[i];
                    }
                }
                if (curr_start != -1) {
                    permuted.update(curr_start, P_inv[r], c);
                }
            } else {
                // Permuted update
                permuted.update(l, r, c);
                // Update regular array accordingly
                vector<pair<int, int>> ranges;
                int curr_start = -1;
                
                // Find continuous ranges in regular array
                for (int i = l; i <= r; i++) {
                    if (curr_start == -1) curr_start = P[i];
                    else if (P[i] != P[i-1] + 1) {
                        regular.update(curr_start, P[i-1], c);
                        curr_start = P[i];
                    }
                }
                if (curr_start != -1) {
                    regular.update(curr_start, P[r], c);
                }
            }
        } else {
            if (type == 2) {
                results.push_back(regular.query(l, r));
            } else {
                results.push_back(permuted.query(l, r));
            }
        }
    }
    
    // Output results
    for (ll result : results) {
        cout << result << '\n';
    }
    
    return 0;
}