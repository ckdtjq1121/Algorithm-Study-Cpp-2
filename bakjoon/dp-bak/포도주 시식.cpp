
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<vector<int>> dp;
vector<int> dp2;
vector<int> arr;
int topDown(int i, int j)
{
    if (i == 0)
    {
        if (j == 0)
            return 0;
        else
            return arr[i];
    }

    int &ret = dp[i][j];

    if (ret != -1)
        return ret;

    if (j == 0)
        ret = max({topDown(i - 1, 0), topDown(i - 1, 1), topDown(i - 1, 2)});
    else if (j == 1)
        ret = topDown(i - 1, 0) + arr[i];
    else
        ret = topDown(i - 1, 1) + arr[i];

    return ret;
}

int topDown2(int i)
{
    if (i == 0)
    return arr[0];

    if(i == 1)
    return arr[0] + arr[1];

    if(i == 2)
    return max({topDown2(i - 1), topDown2(i - 2) + arr[i], 0 + arr[i - 1] + arr[i]});

    int &ret = dp2[i];

    if (ret != -1)
        return ret;

    ret = max({topDown2(i - 1), topDown2(i - 2) + arr[i], topDown2(i - 3) + arr[i - 1] + arr[i]});
    return ret;
}
int bottomUp()
{
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
int main()
{
    cin >> n;

    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp = vector<vector<int>>(n, vector<int>(3, -1));
    dp2 = vector<int>(n, -1);
    int ans = 0;

    // bottom - up
    // ans = bottomUp();

    // top - down
    // ans = max({topDown(n - 1, 0), topDown(n - 1, 1), topDown(n - 1, 2)});

    // top down 2
    ans = topDown2(n-1);
    cout << ans << "\n";
}