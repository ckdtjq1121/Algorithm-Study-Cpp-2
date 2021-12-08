#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 111;
const int INF = 1 << 30;

//capacity 배열
int c[MAX_V][MAX_V];
//flow 배열
int f[MAX_V][MAX_V];
//각 node의 parent를 저장할 배열
int parent[MAX_V];

int fordFulkerson(int source, int sink)
{
    int total = 0;

    while (true)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> Q;
        Q.push(source);
        parent[source] = source;

        while (!Q.empty() && parent[sink] == -1)
        {
            int here = Q.front();
            Q.pop();
            for (int there = 0; there < MAX_V; there++)
            {
                // 방문하지 않는 노드 중 유량이 남은 노드로 가서 경로를 만든다.
                if (c[here][there] - f[here][there] > 0 && parent[there] == -1)
                {
                    parent[there] = here;
                    Q.push(there);
                }
            }
        }

        //모든 경로를 다 찾고 끝냄.
        if (parent[sink] == -1)
            break;

        int mn = INF;
        //최소 유량을 찾습니다.
        for (int p = sink; p != source; p = parent[p])
        {
            mn = min(c[parent[p]][p] - f[parent[p]][p], mn);
        }
        //최소 유량만큼 추가합니다.
        for (int p = sink; p != source; p = parent[p])
        {
            f[parent[p]][p] += mn;
            f[p][parent[p]] -= mn;
        }
        total += mn;
    }
    return total;
}
int main()
{

    c[1][2] = 12;
    c[1][4] = 11;
    c[2][3] = 6;
    c[2][4] = 3;
    c[2][5] = 5;
    c[2][6] = 9;
    c[3][6] = 8;
    c[4][5] = 9;
    c[5][3] = 3;
    c[5][6] = 4;

    cout << fordFulkerson(1, 6) << "\n";
}
