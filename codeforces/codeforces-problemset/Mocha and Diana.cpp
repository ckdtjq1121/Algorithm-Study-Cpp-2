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
vi pm;
vi pd;
int find_m(int u)
{
    if (u == pm[u])
        return u;

    return pm[u] = find_m(pm[u]);
}
int find_d(int u)
{
    if (u == pd[u])
        return u;

    return pd[u] = find_d(pd[u]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;

    pm = vector<int>(n);
    for (int i = 0; i < n; i++)
        pm[i] = i;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int ru = find_m(u), rv = find_m(v);
        if (ru != rv)
        {
            pm[ru] = rv;
        }
    }

    pd = vector<int>(n);
    for (int i = 0; i < n; i++)
        pd[i] = i;

    for (int i = 0; i < d; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int ru = find_d(u), rv = find_d(v);
        if (ru != rv)
        {
            pd[ru] = rv;
        }
    }

    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int rum = find_m(i), rvm = find_m(j), rud = find_d(i), rvd = find_d(j);
            // cout << rum << " " << rvm << " " << rud << " " << rvd << "\n";
            if (rum != rvm && rud != rvd)
            {
                ans.push_back({i, j});
                pm[rum] = rvm;
                pd[rud] = rvd;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1<< " " << ans[i].second + 1<< "\n";
    }
}