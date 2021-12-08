
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n;

vector<int> incr;
vector<int> decr;

vector<int> arr;

int bottomUp()
{
    for (int i = 0; i < n; i++)
    {
        incr[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && incr[i] < incr[j] + 1)
                incr[i] = incr[j] + 1;
            
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        decr[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i] && decr[i] < decr[j] + 1)
                decr[i] = decr[j] + 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << incr[i] << " " << decr[i] << "\n";
        ret = max(ret, incr[i] + decr[i] - 1);
    }

    return ret;
}
int main()
{
    cin >> n;

    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    incr = vector<int>(n);
    decr = vector<int>(n);

    int ans = 0;

    // bottom - up
    ans = bottomUp();

    cout << ans << "\n";
}