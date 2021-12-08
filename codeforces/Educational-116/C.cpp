#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
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

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, k;
        cin >> n >> k;

        vi a(n);
        int d;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        k++;    // k+1 개의 화페를 사용

        int sum = 0;    // 현재 까지 사용한 화폐의 총 개수
        vi num(n, 0);   // i번째 화폐의 사용 개수
        for (int i = 0; i + 1 < n; i++)
        {
            int diff = a[i + 1] - a[i]; // 자리수 차이

            int d = 1;
            for (int j = 0; j < diff; j++)
                d *= 10;

            // d : 9, 99, 999, ...
            d--;    // 최대 사용 가능 개수

            // 남은 개수가 d보다 작은 경우 남은 개수의 화폐만 사용
            if (sum + d > k)
            {
                num[i] = k - sum;
                sum = k;
                break;
            }

            // d개의 화폐 사용 
            num[i] = d;
            sum += d;
        }
        // 남은 화폐의 개수를 마지막 화폐로 사용
        num[n - 1] = k - sum;

        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if(num[i] == 0)
            continue;

            ans += to_string(num[i]);
        }
        
        cout << ans << "\n";
    }
}