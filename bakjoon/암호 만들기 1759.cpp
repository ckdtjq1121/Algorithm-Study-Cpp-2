#include <bits/stdc++.h>

using namespace std;

// 2^15개 brute force

vector<char> a;

// v개의 모음 필요, c개 의 자음 필요, l개의 문자 필요
// idx 부터 사용 가능
void rec(int v, int c, int l, vector<char> p, int idx)
{
    // l개의 문자열 완성
    if (l == 0)
    {
        // 모음 1개 이상 자음 2개 이상일때
        if (1 <= v && 2 <= c)
        {
            for (int i = 0; i < p.size(); i++)
                cout << p[i];
            cout << "\n";
        }

        return;
    }

    // 더 이상 문자열을 만들 수 없을 때
    if (idx >= a.size())
        return;

    for (int i = idx; i < a.size(); i++)
    {
        p.push_back(a[i]);
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            rec(v + 1, c, l - 1, p, i + 1);
        else
            rec(v, c + 1, l - 1, p, i + 1);

        p.pop_back();
    }

    return;
}
int main()
{
    int l, c;
    cin >> l >> c;

    a = vector<char>(c);
    for (int i = 0; i < c; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<char> ept;
    rec(0, 0, l, ept, 0);
}