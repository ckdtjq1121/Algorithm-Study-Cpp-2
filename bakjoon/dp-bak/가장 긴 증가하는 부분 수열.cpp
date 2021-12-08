
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<int> dp;
vector<int> arr;

int bottomUp()
{
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
            dp[i] = dp[j] + 1;
        }
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