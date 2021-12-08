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
        int h, m;
        cin >> h >> m;

        string t;
        cin >> t;

        int ch = stoi(t.substr(0, 2));
        pair<int, int> ph;
        ph.first = ch / 10;
        ph.second = ch % 10;

        int cm = stoi(t.substr(3, 2));
        pair<int, int> pm;
        pm.first = cm / 10;
        pm.second = cm % 10;

        bool end = 0;
        // 0 1 2 5 8
        if (ph.first == 0 || ph.first == 1 || ph.first == 2 || ph.first == 5 || ph.first == 8)
            if (ph.second == 0 || ph.second == 1 || ph.second == 2 || ph.second == 5 || ph.second == 8)
                if (pm.first == 0 || pm.first == 1 || pm.first == 2 || pm.first == 5 || pm.first == 8)
                    if (pm.second == 0 || pm.second == 1 || pm.second == 2 || pm.second == 5 || pm.second == 8)
                        // 뒤집은 시간이 정상적일때
                        if (ph.second * 10 + ph.first < m && pm.second * 10 + pm.first < h)
                            end = 1;

        if (end)
        {
            cout << ph.first << ph.second << ":" << pm.first << pm.second << "\n";
            continue;
        }

        for (int i = 0; i < m * h; i++)
        {
            pm.second++;

            // hour++, minute set 00
            if (pm.first * 10 + pm.second == m)
            {
                ph.second++;

                pm.first = 0;
                pm.second = 0;
            }
 
            // 자리수 올림
            pm.first += pm.second / 10;
            pm.second = pm.second % 10;

            // hour set 00
            if (ph.first * 10 + ph.second == h)
            {
                ph.first = 0;
                ph.second = 0;
            }   

            ph.first += ph.second / 10;
            ph.second = ph.second % 10;

            if (ph.first == 0 || ph.first == 1 || ph.first == 2 || ph.first == 5 || ph.first == 8)
                if (ph.second == 0 || ph.second == 1 || ph.second == 2 || ph.second == 5 || ph.second == 8)
                    if (pm.first == 0 || pm.first == 1 || pm.first == 2 || pm.first == 5 || pm.first == 8)
                        if (pm.second == 0 || pm.second == 1 || pm.second == 2 || pm.second == 5 || pm.second == 8)
                            if (ph.second * 10 + ph.first < m && pm.second * 10 + pm.first < h)
                                break;
        }

        cout << ph.first << ph.second << ":" << pm.first << pm.second << "\n";
    } 
}