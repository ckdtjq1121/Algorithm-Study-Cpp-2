
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<int> dp;

vector<int> arr;

int topdown(int i, int conti)
{
    if (i <= -1)
        return 0;

    if (i == 0)
        return arr[i];
        
    int &ret = dp[i];
    if (ret != -1)
        return ret;

    if (conti == 2)
        return ret = topdown(i - 2, 1) + arr[i];
    else
        return ret = max(topdown(i - 1, 2), topdown(i - 2, 1)) + arr[i];
}
int bottomUp()
{
}

int main()
{
    cin >> n;

    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp = vector<int>(n, -1);
    int ans = 0;

    // bottom - up
    // ans = bottomUp();

    // top down
    ans = topdown(n - 1, 1);
    cout << ans << "\n";
}