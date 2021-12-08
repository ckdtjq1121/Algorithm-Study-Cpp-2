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

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
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
        int n;
        cin >> n;

        vi alive(n, 1);
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (gcd(a[i], a[(i + 1) % n]) == 1)
                q.push({i, (i + 1) % n});
        }


        // 살아이쓴 바로 뒤에놈만 앞에 놈을 죽일 수 있음
        vi ans;
        while (!q.empty())
        {
            int u = q.front().first;
            int v = q.front().second;

            q.pop();
            
            // 죽이려는 놈이 살아 있어야 킬 가능
            if (alive[u])
            {
                // 앞에놈 킬
                ans.push_back(v+1);
                alive[v] = 0;

                // 살아있는 바로 앞에놈을 찾음
                int next = v + 1;
                while (!alive[next % n] && next % n != u)
                    next++;
                
                // 죽일 수 있다면 리스트에 추가
                if (gcd(a[u], a[next % n]) == 1)
                {
                    q.push({u, next % n});
                }
            }
        }

        cout << ans.size() << " ";
        cout << ans << "\n";
    }
}
