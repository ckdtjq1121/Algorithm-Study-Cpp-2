
#include <bits/stdc++.h>

using namespace std;
vector<int> a;
vector<int> tree, lazy, lazy_update;

// xor segment tree init
int init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = a[start];

    int mid = (start + end) / 2;

    return tree[node] = init(2 * node, start, mid) ^ init(2 * node + 1, mid + 1, end);
}
// [s, e]번째 update에 대한 update
void lazy_update_propagation(int node, int start, int end)
{
    // i번째 update에서 range로 변환을 하는 방법

    // lazy_update가 있다면
    if(lazy_update[node] != 0)
    {

    }
}

// tree의 [s, e]에 대한 업데이트
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
// i번째 update[l,r]를 실행 중
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
// i번쨰 구간에 대한 query
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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    cin >> a[i];

    tree = vector<int>(4*n, 0);
    lazy = vector<int>(4*n, 0);

    init(1, 0, n-1);

    vector<pair<int, int> > updateList(m);
    for(int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;

        updateList[i].first = l;
        updateList[i].second = r;
        
        update(1, 0, n-1, l, r, x);
    }

    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        if(t ==  1)
        {
            // [l,r] 의 update에 xor v를 한다
            // -> even time xor v -> 0, odd time xor v -> v
            int l, r, v;
            cin >> l >> r >> v;

            
        }
        else if(t == 2)
        {
            int s, e;
            cin >> s >> e;

            cout << query(1, 0, n-1, s, e) << "\n";
        }
    }
}