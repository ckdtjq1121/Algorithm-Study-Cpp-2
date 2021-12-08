
#include <bits/stdc++.h>

using namespace std;
vector<int> dp;
int topDown(int i)
{
    if (i <= 1)
        return 0;

    int &ret = dp[i];
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    if (i % 3 == 0)
        ret = min(ret, topDown(i / 3));

    if (i % 2 == 0)
        ret = min(ret, topDown(i / 2));

    ret = min(ret, topDown(i - 1));

    ret++;
    return ret;
}
int main()
{
    int n;
    cin >> n;

    dp = vector<int>(n + 1, -1);
    dp[1] = 0;

    // bottom - up

    // for (int i = 2; i <= n; i++)
    // {
    //     int ret = dp[i - 1];
    //     if (i % 2 == 0)
    //         ret = min(ret, dp[i / 2]);
    //     if (i % 3 == 0)
    //         ret = min(ret, dp[i / 3]);
    //     dp[i] = ret + 1;
    // }

    // top - down
    topDown(n);
    cout << dp[n] << "\n";
}