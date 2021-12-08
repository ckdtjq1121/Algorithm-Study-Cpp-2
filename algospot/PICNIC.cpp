#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int, int>> edge;
int pairing(vector<bool> visited, int i)
{
    bool end = 1;
    for (int j = 0; j < n; j++)
        if (!visited[j])
            end = 0;

    if(end)
    return 1;

    int ret = 0;
    for (int j = i + 1; j < m; j++)
    {
        int u = edge[j].first, v = edge[j].second;

        if (!visited[u] && !visited[v])
        {
            visited[u] = 1;
            visited[v] = 1;
            ret += pairing(visited, j);
            visited[u] = 0;
            visited[v] = 0;
        }
    }

    return ret;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> m;

        edge = vector<pair<int, int>>(m);
        for (int i = 0; i < m; i++)
            cin >> edge[i].first >> edge[i].second;

        vector<bool> visited(n, false);
        int ans = pairing(visited, -1);

        cout << ans << "\n";
    }
}
