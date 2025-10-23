#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    int n;
    vector<ll> tree, lazy;
    vector<int> arr;

public:
    SegmentTree(int size, vector<int>& arr) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        this->arr = arr;
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {

             // leaf node
            tree[node] = arr[start];
            return;
        }
        int mid = start + ((end - start) >> 1);
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Propagate lazy updates
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) { // not a leaf
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    // Range update: add val to [l, r]
    void range_update(int node, int start, int end, int l, int r, ll val) {
        push(node, start, end);

        if (r < start || end < l) return; // no overlap
        if (l <= start && end <= r) {     // total overlap
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = start + ((end - start) >> 1);
        range_update(2 * node + 1, start, mid, l, r, val);
        range_update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Range sum query [l, r]
    ll query(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (r < start || end < l) return 0;       // no overlap
        if (l <= start && end <= r) return tree[node]; // total overlap

        int mid = start + ((end - start) >> 1);
        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }

    // Helper functions for easier usage
    void update_range(int l, int r, ll val) { range_update(0, 0, n - 1, l, r, val); }
    ll sum_query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int main() {
    int n = 8;
    vector<int> arr = {3, 2, 4, 5, 1, 1, 5, 3};
    SegmentTree st(n, arr);

    cout << st.sum_query(0, 3) << "\n"; // 14
    cout << st.sum_query(4, 5) << "\n"; // 2

    st.update_range(2, 2, -3); // update index 2 (0-based) to 1 (4->1)

    cout << st.sum_query(0, 3) << "\n"; // 11

    st.update_range(0, 7, 2); // add 2 to all elements

    cout << st.sum_query(0, 7) << "\n"; // 44

    return 0;
}
