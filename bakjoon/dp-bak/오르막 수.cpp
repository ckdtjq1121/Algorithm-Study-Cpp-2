
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<vector<int>> dp;

int topDown(int i, int j)
{
    if(i == 0)
    return 1;

    int& ret = dp[i][j];

    if(ret != -1)
    return ret;

    ret = 0;
    for(int k = 0; k <= j; k++)
        ret = (ret + topDown(i-1, k) ) % MOD;

    return ret;
}
int bottomUp()
{
    for (int i = 0; i < 10; i++)
        dp[0][i] = i + 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[n - 1][9];
}
int main()
{
    cin >> n;
    dp = vector<vector<int>>(n, vector<int>(10, -1));

    int ans = 0;

    // bottom - up - OK
    // ans = bottomUp();

    // top - down - OK
    for (int i = 0; i < 10; i++)
        ans = (ans + topDown(n - 1, i)) % MOD;

    cout << ans << "\n";
}