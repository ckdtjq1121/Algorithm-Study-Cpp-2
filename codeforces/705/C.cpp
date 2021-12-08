#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int get(int x, int k) {
    return (k - x % k) % k;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        // S에 있는 알파벳의 개수 cnt
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;

        // [i] 가 k배수가 되기 위해 필요한 개수
        int sum = 0, flag = 1;
        for (int i = 0; i < 26; ++i) {
            sum += get(cnt[i], k);
        }

        // 이미 충족을 한다면 바로 출력
        if (sum == 0) {
            cout << s << '\n';
            flag = 0;
        }
        // 절대 만들 수 없음
        if (n % k != 0) {
            cout << -1 << '\n';
            continue;
        }
        // 접미사를 brute force로 바꾸며 답 찾기
        for (int i = n - 1; i >= 0 && flag; --i) {
            sum -= get(cnt[s[i] - 'a'], k);
            cnt[s[i] - 'a']--;
            sum += get(cnt[s[i] - 'a'], k);
            for (int j = s[i] - 'a' + 1; j < 26; ++j) {
            // s[i] alpabet을 ㅃㅐ고 s[j]로 대체
                int lst_sum = sum;
                sum -= get(cnt[j], k);
                cnt[j]++;
                sum += get(cnt[j], k);

                // i+1개 + sum(충족시키기 위해 필요한 개수) <= n (문자열의 길이)  // 이때 최적으로 만들 수 있음
                if (i + sum + 1 <= n) {

                    // i-1 까지는 기존의 것 출력
                    for (int pos = 0; pos < i; ++pos) {
                        cout << s[pos];
                    }
                    // i번째 것은 j번째 것으로 대체
                    cout << char('a' + j);

                    // 필요한 알파벳들로 add를 채움
                    string add = "";
                    for (int w = 0; w < 26; ++w) {
                        int f = get(cnt[w], k);
                        while (f) {
                            f--;
                            add += char('a' + w);
                        }
                    }
                    // 개수가 모자란 부분은 a로만 더 채움 (j까지 + sum 도 k의 배수 + rest element 도 K의 배수가 된다)
                    while ((int)add.size() + i + 1 < n) {
                        add += "a";
                    }

                    // 자유롭게 배치 할 수 있으니 lexically smallest 를 만들기 위해 정렬
                    sort(add.begin(), add.end());
                    cout << add << '\n';
                    flag = 0;
                    break;
                }

                cnt[j]--;
                sum = lst_sum;
            }
        }
    }
    return 0;
}