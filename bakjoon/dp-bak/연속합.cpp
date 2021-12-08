
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<int> dp;

vector<int> arr;

int bottomUp()
{
    dp[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    cin >> n;

    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp = vector<int>(n);
    int ans = 0;

    // bottom - up
    ans = bottomUp();

    cout << ans << "\n";
}