
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dp;
const int MOD = 1e9;

// 길이가 i, 마지막 숫자가 j인 계단의 개수
int topDown(int i, int j)
{

    if (j < 0 || j > 9)
        return 0;

    if (i == 1)
        return 1;

    int &ret = dp[i][j];

    if (ret != -1)
        return ret;

    return ret = (topDown(i - 1, j - 1) + topDown(i - 1, j + 1)) % MOD;
}

int main()
{

    cin >> n;

    dp = vector<vector<int>>(n + 1, vector<int>(10, -1));

    int ans = 0;
    // bottom - up

    // base case
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    // recursion
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;
            if (j > 0 )
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;

            if (j < 9)
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;

        }
    }
    // debug
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    // sum every case
    for (int i = 0; i < 10; i++)
        ans = (ans + dp[n][i]) % MOD;

    // top - down
    // for (int i = 1; i < 10; i++)
    //     ans = (ans + topDown(n, i)) % MOD;

    cout << ans << "\n";
}