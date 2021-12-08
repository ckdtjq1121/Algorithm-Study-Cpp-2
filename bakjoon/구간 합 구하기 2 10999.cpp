
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> a, tree, lazy;

int init(int node, int s, int e)
{
    if (s == e)
        return tree[node] = a[s];

    int mid = (s + e) / 2;

    return tree[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}

void lazy_propagation(int node, int s, int e)
{
    if (lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];

        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];

        lazy[node] = 0;
    }
}

int update(int node, int s, int e, int l, int r, int v)
{
    lazy_propagation(node, s, e);

    if (e < l || r < s)
        return tree[node];

    if (l <= s && e <= r)
    {
        tree[node] += (e - s + 1) * v;
        if (s < e)
        {
            lazy[2 * node] += v;
            lazy[2 * node + 1] += v;
        }

        return tree[node];
    }

    int mid = (s + e) / 2;
    return tree[node] = update(2 * node, s, mid, l, r, v) + update(2 * node + 1, mid + 1, e, l, r, v);
}

int query(int node, int s, int e, int l, int r)
{
    lazy_propagation(node, s, e);

    if (e < l || r < s)
        return 0;

    if (l <= s && e <= r)
        return tree[node];

    int mid = (s + e) / 2;
    return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    a = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    tree = vector<int>(4 * n, 0);
    lazy = vector<int>(4 * n, 0);

    init(1, 0, n - 1);

    for (int i = 0; i < m + k; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            update(1, 0, n - 1, l, r, v);
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r) << "\n";
        }
    }
}