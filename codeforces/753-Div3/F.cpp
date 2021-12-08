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

int n, m;
char grid[2001][2001];
bool visited[2001][2001];
int dp[2001][2001];
int dfs(int i, int j)
{
    if (visited[i][j])
        return dp[i][j];

    if (i <= 0 || i > n || j <= 0 || j > m)
        return 0;

    visited[i][j] = 1;

    int& ret = dp[i][j];
    if (grid[i][j] == 'R')
        ret = dfs(i, j + 1);
    else if (grid[i][j] == 'L')
        ret = dfs(i, j - 1);
    else if (grid[i][j] == 'U')
        ret = dfs(i - 1, j);
    else
        ret = dfs(i + 1, j);

    return ret = ret + 1;
}
void dfsAll()
{
    int y, x, d;
    y = 0, x = 0, d = 0;
    memset(visited, 0, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j])
                continue;

            int ret = dfs(i, j);
            if (ret > d)
            {
                y = i;
                x = j;
                d = ret;
            }
        }
    }

    cout << y << " " << x << " " << d << "\n";
}
// union find
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> grid[i][j];
            }
        }

        dfsAll();
    }
}