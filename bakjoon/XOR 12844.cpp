
#include <bits/stdc++.h>

using namespace std;
vector<int> a;
vector<int> tree, lazy;

// xor segment tree init
int init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = a[start];

    int mid = (start + end) / 2;

    return tree[node] = init(2 * node, start, mid) ^ init(2 * node + 1, mid + 1, end);
}

void lazy_propagation(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] ^= ((end - start) % 2) ? 0 : lazy[node];
        // 리프 노드가 아니면
        if (start < end)
        {
            lazy[2 * node] ^= lazy[node];
            lazy[2 * node + 1] ^= lazy[node];
        }

        lazy[node] = 0;
    }
}

int update(int node, int start, int end, int left, int right, int val)
{
    // 이전에 있던 lazy
    lazy_propagation(node, start, end);

    // 범위 밖 -> 그대로
    if (end < left || right < start)
        return tree[node];

    // 범위 안 -> update
    if (left <= start && end <= right)
    {
        tree[node] ^= ((end - start) % 2) ? 0 : val;
        // Not leaf node -> lazy propagation to childs
        if (start < end)
        {
            lazy[2 * node] ^= val;
            lazy[2 * node + 1] ^= val;
        }

        return tree[node];
    }

    int mid = (start + end) / 2;
    return tree[node] = update(2 * node, start, mid, left, right, val) ^ update(2 * node + 1, mid + 1, end, left, right, val);
}

int query(int node, int start, int end, int left, int right)
{
    // 이전에 있던 lazy
    lazy_propagation(node, start, end);

    // 범위 밖 -> 항등원
    if (end < left || right < start)
        return 0;

    // 범위 안
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return query(2 * node, start, mid, left, right) ^ query(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    tree = vector<int>(4 * (n + 1), 0);
    lazy = vector<int>(4 * (n + 1), 0);
    init(1, 1, n);

    int m;
    cin >> m;

    int q, l, r, k;
    for (int i = 0; i < m; i++)
    {
        cin >> q;

        if (q == 1)
        {
            cin >> l >> r >> k;
            l++, r++;
            update(1, 1, n, l, r, k);
        }
        else if (q == 2)
        {
            cin >> l >> r;
            l++, r++;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}