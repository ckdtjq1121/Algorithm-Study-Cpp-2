
#include <bits/stdc++.h>

using namespace std;

// [0, x] xor
int solve(int x)
{
    int ret = 0;

    for(int i = (x/4)*4; i <= x; i++)
    ret ^= i;

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        // [l-1, r] xor
        int l, r;
        cin >> l >> r;

        int ans = solve(r) ^ solve(l-1);

        cout << ans << "\n";
    }
}