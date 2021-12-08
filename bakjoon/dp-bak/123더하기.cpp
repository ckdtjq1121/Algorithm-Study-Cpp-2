
#include <bits/stdc++.h>

using namespace std;
vector<int> dp;
int topDown(int i)
{
    int &ret = dp[i];

    if (ret != -1)
        return ret;

    return ret = topDown(i - 1) + topDown(i - 2) + topDown(i - 3);
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        dp = vector<int>(n + 1, -1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        // bottom - up

        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        // top - down
        // topDown(n);
        cout << dp[n] << "\n";
    }
}