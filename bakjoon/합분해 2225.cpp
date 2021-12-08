#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000000;
int n, k;
vector<vector<int>> dp;
//  b개의 정수로 sum a 를 만드는 경우의 수
int rec(int a, int b)
{
    if (b == 0)
    {
        if (a == 0) // b개의 원소로 sum n을 만들었을 때만 count
            return 1;
        else
            return 0;
    }

    int &ret = dp[a][b];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i <= a; i++)
    {
        ret = (ret + rec(a - i, b - 1)) % MOD;
    }

    return ret;
}
int main()
{
    cin >> n >> k;

    dp = vector<vector<int>>(n + 1, vector<int>(k+1, -1));

    cout << rec(n, k) << "\n"; 
} 