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

    vector<int> b(32, 0);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        for(int j = 0; j < 32; j++)
        {
            if(tmp & 1)
            b[j]++;

            tmp >>= 1;

            if(tmp == 0)
            break;
        }
    }

    // 각 비트가 0과 1 일때 만나는 경우의수 = 0의 개수 * 1의 개수
    int ans = 0;
    for(int i = 0; i < 32; i++)
        ans += b[i] * (n-b[i]) * (1 << i);

    cout << ans << "\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}