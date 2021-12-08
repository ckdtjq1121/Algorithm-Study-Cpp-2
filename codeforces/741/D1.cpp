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
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vi psum1;
        vi psum2;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (i == 0)
                {
                    if (s[i] == '+')
                        psum1.push_back(1);
                    else
                        psum1.push_back(-1);
                }
                else
                {
                    if (s[i] == '+')
                        psum1.push_back(psum1.back() + 1);
                    else
                        psum1.push_back(psum1.back() - 1);
                }
            }
            else
            {
                if (i == 1)
                {
                    if (s[i] == '+')
                        psum2.push_back(-1);
                    else
                        psum2.push_back(1);
                }
                else
                {
                    if (s[i] == '+')
                        psum2.push_back(psum2.back() - 1);
                    else
                        psum2.push_back(psum2.back() + 1);
                }
            }
        }

        // cout << psum1 << "\n";
        // cout << psum2 << "\n";
        
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;

            l--, r--;

            int p = 0, m = 0;

            if (l % 2 == 0)
            {
                if (l != 0)
                {
                    p -= psum1[(l - 2) / 2];
                    m -= psum2[(l - 2) / 2];
                }
            }
            else
            {
                if (l == 1)
                {
                    p -= psum1[0];
                }
                else
                {
                    p -= psum1[l / 2];
                    m -= psum2[(l - 2) / 2];
                }
            }

            if (r % 2 == 0)
            {
                p += psum1[r / 2];
                m += psum1[(r - 2) / 2];
            }
            else
            {
                p += psum1[r / 2];
                m += psum1[r / 2];
            }

            cout << p << " " << m << "\n";
        }
    }
}