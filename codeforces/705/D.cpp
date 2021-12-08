#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const maxn = 2e5 + 5, max_val = 2e5 + 5;
ll mod = 1e9 + 7, ans = 1;
int nxt[max_val], n;
multiset <int> cnt[max_val];
map <int, int> cnt_divisor[maxn];

void add(int i, int x) {
    while (x != 1) {
        // nxt[x] x를 나눌수 있는 소인수
        int div = nxt[x], add = 0;
        // 나눌수 있는 만큼 나눈다.
        while (nxt[x] == div) add++, x = x / nxt[x];


        int lst = cnt_divisor[i][div];  // i번째 원소의 div 소인수의 개수
        cnt_divisor[i][div] += add;     // x에 있던 div의 개수 추가
        int lst_min = 0;
        // [1,n] 모든 원소가 div를 갖고 있다면 현재 div의 최소 개수를 저장
        if ((int)cnt[div].size() == n) {   
            lst_min = (*cnt[div].begin());
        }
        // lst개의 div 제거 후
        if (lst != 0) {
            cnt[div].erase(cnt[div].find(lst));
        }
        // lst + add의 div 추가
        cnt[div].insert(lst + add);
        // 현재 div의 최소 개수 + 1 ~ 갱신된 div의 최소 개수 만큼 ans *= div 
        if ((int)cnt[div].size() == n) {
            for (int j = lst_min + 1; j <= (*cnt[div].begin()); ++j) {
                ans = ans * (ll)div % mod;
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, l, x;
    cin >> n >> q;
    // 에라토스테네스의 체로 소인수 분해 해쉬 만들기
    // 소수 i의 배수들이 i를 가리키도록 한다.
    for (int i = 2; i < maxn; ++i) {
        if (nxt[i] == 0) {
            nxt[i] = i;
            if (i > 10000) continue;
            for (int j = i * i; j < maxn; j += i) {
                if (nxt[j] == 0) nxt[j] = i;
            }
        }
    }
    // [1,n] 원소 소인수 추가
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        add(i, x);
    }

    // l idx에 x의 소인수 추가
    for (int i = 1; i <= q; ++i) {
        cin >> l >> x;
        add(l, x);
        cout << ans << '\n';
    }

    return 0;
}