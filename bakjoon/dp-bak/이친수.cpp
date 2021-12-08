
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 10007;

int n;

vector<vector<ll>> dp;

ll topDown(int i, int j)
{
    if (i == 0 && j == 1)
        return 1;

    if (i == 0 && j == 0)
        return 0;

    ll &ret = dp[i][j];

    if (ret != -1)
        return ret;

    if (j == 0)
        ret = topDown(i - 1, 0) + topDown(i - 1, 1);
    else
        ret = topDown(i - 1, 0);

    return ret;
}
ll bottomUp()
{
    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    return dp[n - 1][0] + dp[n - 1][1];
}
int main()
{
    cin >> n;
    dp = vector<vector<ll>>(n, vector<ll>(2, -1));

    ll ans = 0;

    // bottom - up
    // ans = bottomUp();

    // top - down
    ans = topDown(n - 1, 0) + topDown(n - 1, 1);

    cout << ans << "\n";
}