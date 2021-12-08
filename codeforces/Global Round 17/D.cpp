#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

using vi = vector<int>;
using vp = vector<pii>;
using vvi = vector<vi>;
using vvp = vector<vp>;

template <typename T>
T _read()
{
    T i;
    cin >> i;
    return i;
}
template <typename... T>
tuple<T...> _reads() { return {_read<T>()...}; }
//template<typename T, size_t...I> void _write(const T& i, index_sequence<I...>) { (..., (cout << (I ? " " : "") << get<I>(i))); }
template <typename... T>
void _writes(tuple<T...> i) { _write(i, make_index_sequence<sizeof...(T)>()); }
template <typename T>
T max(vector<T> v) { return *max_element(all(v)); }
template <typename T>
T min(vector<T> v) { return *min_element(all(v)); }
template <typename T>
istream &operator>>(istream &in, vector<T> &i)
{
    for (auto &i : i)
        in >> i;
    return in;
}
template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &i)
{
    in >> i.X >> i.Y;
    return in;
}
template <typename... T>
istream &operator>>(istream &in, tuple<T...> &i)
{
    i = _reads<T...>();
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> i)
{
    for (auto &i : i)
        out << i << ' ';
    return out;
}
template <typename T, typename U>
ostream &operator<<(ostream &out, pair<T, U> i)
{
    out << i.X << ' ' << i.Y;
    return out;
}
template <typename... T>
ostream &operator<<(ostream &out, tuple<T...> i)
{
    _writes(i);
    return out;
}

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int n;
    // cin >> n;

    // int even = 0, odd = 0;
    // vi a(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> a[i];

    //     if(a[i] % 2 == 0)
    //     even++;
    //     else
    //     odd++;
    // }

    // // 아무것도 안고르는 경우
    // int ans = 1;
    // // 홀수 1개 이상 + 짝수 0 ~ n 개를 고르는 경우
    // ans += (((1 << odd)-1) << even);

    // // 홀수 0개 + 짝수 0 ~ n
    // // Sum(a) == Sum(b)
    // // (6,2), (14,6), (14,2) - > n(n-1) / 2 - 1 의 약수 가 존재 하면 
    // cout << ans << "\n";




    // test

    // int n;
    // cin >> n;

    // vi a(n);
    // vi b(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> a[i];

    //     b[i] = a[i]*(a[i]-1) / 2 - 1;
    // }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i+1; j < n; j++)
    //     {
    //         if(b[i] % a[j] == 0)
    //         cout << "Find " << a[i] << " " << a[j] << "\n";
    //     }
    // }

    int n;
    cin >> n;

    const int mx = 30;
    vector<int> cnt(mx, 0);
    for(int i =0; i < n; i++){
        int x;
        cin >> x;

        cnt[__builtin_ctz(x)]++;
    }

    int rem = n;
    for(int i = 0; i < 30; i++)
    {
        int cur = 0;
        rem -= cnt[i];

        int curPow = 2; 
        for(int j = 0; j < rem; j++)
        {
            curPow = (curPow << 1) % MOD;
        }

    }
} 

