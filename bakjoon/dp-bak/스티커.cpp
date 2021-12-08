
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 10007;

int n;
vector<vector<ll>> arr;
vector<vector<ll>> dp;

ll topDown(int i, int j)
{
    if (i < 0)
        return 0;
    cout << i << " " << j << "\n";
    if (i == 1 && j == 1)
        return arr[i][j] + arr[0][0];

    if (i == 1 && j == 0)
        return arr[i][j] + arr[1][0];

    if (i == 0)
        return arr[i][j];

    ll &ret = dp[i][j];

    if (ret != -1)
        return ret;

    if (i == 0)
        ret = max({topDown(1, j - 1), topDown(1, j - 2), topDown(0, j - 2)}) + arr[i][j];
    else
        ret = max({topDown(0, j - 1), topDown(0, j - 2), topDown(1, j - 2)}) + arr[i][j];

    return ret;
}
ll bottomUp()
{
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            dp[1][i] = dp[0][0] + arr[1][i];
            dp[0][i] = dp[1][0] + arr[0][i];
        }
        else
        {
            dp[1][i] = max({dp[0][i - 1], dp[0][i - 2], dp[1][i - 2]}) + arr[1][i];
            dp[0][i] = max({dp[1][i - 1], dp[0][i - 2], dp[1][i - 2]}) + arr[0][i];
        }
    }

    return max(dp[1][n - 1], dp[0][n - 1]);
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n;
        arr = vector<vector<ll>>(2, vector<ll>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        dp = vector<vector<ll>>(2, vector<ll>(n, -1));
        ll ans = 0;

        // bottom - up - OK
        // ans = bottomUp();

        // top - down
        ans = max(topDown(1, n - 1), topDown(0, n - 1));

        cout << ans << "\n";
    }
}