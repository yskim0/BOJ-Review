#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool a[2000][2000];
vector<int> g[2000];
vector<pair <int, int> > edges;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i  = 0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        a[from][to] = a[to][from] = true;
        edges.push_back(make_pair(to, from));
        edges.push_back(make_pair(from, to));
        g[from].push_back(to);
        g[to].push_back(from);
    }

    m*=2;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<m; j++) {

            // 간선 리스트
            // A-B
            int A = edges[i].first;
            int B = edges[i].second;

            // C-D
            int C = edges[j].first;
            int D = edges[j].second;

            if(A == B || A == C || A == D || B == C || B == D || C == D) continue;

            if(!a[B][C]) continue;

            // 인접 리스트
            // D와 연결되는 정점들 탐색
            for(int E : g[D]) {
                if (A == E || B == E || C == E || D == E) continue;
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
}