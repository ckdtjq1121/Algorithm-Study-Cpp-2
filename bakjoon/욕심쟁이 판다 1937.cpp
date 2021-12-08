
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dp;
int n;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int rec(int y, int x)
{
    int& ret = dp[y][x];

    if(ret != -1)
    return ret;

    ret = 0;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];

        if(0 <= ny && ny < n && 0 <= nx && nx < n)
        if(grid[y][x] < grid[ny][nx])
        ret = max(ret, rec(ny, nx));
    }

    ret++;
    return ret;
}
int recAll()
{
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] == -1)
            ret = max(ret, rec(i, j));
        }
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;

    grid = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    dp = vector<vector<int>>(n, vector<int>(n, -1));

    int ans = recAll();
    cout << ans << "\n";
}