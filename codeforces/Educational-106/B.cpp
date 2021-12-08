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
        string s;
        cin >> s;

        int n = s.size();
        vi one;
        vi zero;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                one.push_back(i);
            else
                zero.push_back(i);
        }

        vi remove;
        int i = 0, j = 0;
        while (i < one.size() && j < zero.size())
        {
            if (zero[j] < one[i])
                j++;
            else
            {
                if (!remove.empty())
                {
                    if (remove.back() + 1 < one[i])
                    {
                        remove.push_back(one[i]);
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    remove.push_back(one[i]);
                    i++;
                }
            }
        }

        while (j < zero.size())
        {
            remove.push_back(zero[j]);
            j++;

            if (remove.back() + 1 >= zero[j])
                break;
        }

        // cout << remove << "\n";

        string res = "";
        j = 0;
        for (int i = 0; i < n; i++)
        {
            if (j < remove.size() && i < remove[j])
            {
                res.push_back(s[i]);
            }
            else if (j < remove.size())
                j++;
            else
                res.push_back(s[i]);
        }
        // cout << res << "\n";

        bool ans = 1;
        bool isone = 0;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == '0' && isone)
            {
                ans = 0;
                break;
            }
            if (res[i] == '1')
                isone = 1;
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}