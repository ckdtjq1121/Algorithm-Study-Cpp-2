#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
using namespace std;

#define X first
#define Y second
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    if (sum % 2 == 1)
    {
        // good array
        cout << 0 << "\n";
    }
    else
    {
        vi sorted;
        sorted = a;
        sort(all(sorted));

        int sum2 = 0;
        int i = 0;
        while (sum2 < sum / 2)
        {
            sum2 += sorted[i];
            i++;
        }

        i = 0;
        while (sum2 > sum / 2)
        {
            sum2 -= sorted[i];
            i++;
        }

        cout << sum2 << " " << sum / 2 << "\n";
        // bad - > remove one element
        if (sum2 == sum / 2)
        {
            int mi = a[0];
            int miidx = 0;
            for (int i = 0; i < n; i++)
            {
                if (mi > a[i])
                {
                    mi = a[i];
                    miidx = i + 1;
                }
            }

            cout << 1 << "\n";
            cout << miidx << "\n";
        }
        // good
        else
        {
            cout << 0 << "\n";
        }
    }
}