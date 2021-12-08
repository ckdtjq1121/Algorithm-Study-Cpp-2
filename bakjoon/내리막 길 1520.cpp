
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dp;
int n, m;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int rec(int y, int x)
{
    if (y == n - 1 && x == m - 1)
        return 1;

    int &ret = dp[y][x];

    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < m)
            if (grid[y][x] > grid[ny][nx])
                ret += rec(ny, nx);
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;

    grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    dp = vector<vector<int>>(n, vector<int>(m, -1));
    cout << rec(0, 0) << "\n";
}