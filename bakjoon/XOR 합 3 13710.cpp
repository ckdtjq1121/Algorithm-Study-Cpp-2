
#include <bits/stdc++.h>

#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    int sum = 0;
    vector<int> b(32, 0);
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;

        for(int j = 0; j < 32; j++)
        {
            if(e & 1)
            b[j]++;

            e >>= 1;

            if(e == 0)
            break;
        }

    }

    cout << ans << "\n";
} 