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

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        if(n <= 2)
        {
            cout << 0 << "\n";
            continue;
        }
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m = 0, c = 0;

        bool inf = 1;
        vi cand;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] < a[i + 1])
            {
                cand.push_back(a[i + 1] - a[i]);
            }

            if(a[i] != a[i+1])
            inf = 0;
        }

        if(inf)
        {
            cout << 0 << "\n";
            continue;
        }

        if (cand.empty())
        {
            cout << -1 << "\n";
            continue;
        }

        bool fail = 0;
        vector<pair<int, int>> ans;
        for (int i = 0; i < cand.size(); i++)
        {
            vi b(n);
            b[0] = a[0];
            for (int j = 1; j < n; j++)
                b[j] = b[j - 1] + cand[i];

            vi diff(n);
            for (int j = 0; j < n; j++)
                diff[j] = b[j] - a[j];

            for (int j = 0; j < n; j++)
                if (diff[j] != 0)
                {
                    m = diff[j];
                    break;
                }

            // cout << a << "\n";
            // cout << b << "\n";
            // cout << diff << "\n";
            // cout << "\n";

            int mx = max(a);

            if (m == 0)
            {
                inf = 1;
                break;
            }

            if (mx >= m)
            {
                fail = 1;
                break;
            }

            ans.push_back({m, cand[i]});
        }

        if (inf)
        {
            cout << 0 << "\n";
            continue;
        }

        if (fail)
        {
            cout << -1 << "\n";
            continue;
        }

        sort(all(ans), greater<>());

 
        cout << ans[0].first << " " << ans[0].second << "\n";
    }
}