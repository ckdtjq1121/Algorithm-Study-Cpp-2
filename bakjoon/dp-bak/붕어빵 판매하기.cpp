
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dp;
vector<int> arr;
int topDown(int i)
{
    int &ret = dp[i];

    if (ret != -1)
        return ret;

    ret = arr[i];
    for (int j = 1; j < i; j++)
    {
        ret = max(ret, topDown(i-j) + arr[j] );
    }

    return ret;
}

int main()
{

    cin >> n;

    arr = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp = vector<int>(n + 1, -1);

    // bottom - up
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i] = arr[i];
    //     for (int j = 1; j < i; j++)
    //     {
    //         dp[i] = max(dp[i], dp[i - j] + arr[j]);
    //     }
    // }
 
    // top - down
    topDown(n);
    cout << dp[n] << "\n";
}