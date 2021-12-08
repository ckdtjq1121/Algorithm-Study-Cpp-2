
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;
vector<int> dp;
int topDown(int i)
{
    int &ret = dp[i];

    if (ret != -1)
        return ret;

    return ret = (topDown(i - 2) + topDown(i - 1)) % MOD;
}
int main()
{
    int n;
    cin >> n;

    dp = vector<int>(n + 1, -1);
    dp[1] = 1;
    dp[2] = 2; 

    // top down
    // topDown(n);

    // bottom up
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    cout << dp[n] << "\n";
}