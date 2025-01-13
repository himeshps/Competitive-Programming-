class SegmentTree {
    vector<long long int> tree;
    int n;
 
public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 0, 0, n - 1);
    }
 
    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node + 1, start, mid);
            build(a, 2 * node + 2, mid + 1, end);
            tree[node] =(tree[2 * node + 1] ^ tree[2 * node + 2]);
        }
    }
 
    long long int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) return 0; // Neutral for AND
        if (l <= start && end <= r) return tree[node];
        long long int mid = (start + end) / 2;
        return (query(l, r, 2 * node + 1, start, mid) ^ query(l, r, 2 * node + 2, mid + 1, end));
    }
 
    long long int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};
