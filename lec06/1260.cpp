#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int node) {
    check[node] = true;
    cout << node << ' ';
    for(int i = 0; i<a[node].size(); i++) {
        int next = a[node][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

// 큐를 이용해서 지금 위치에서 갈 수 있는 것을 모두 큐에 넣는 방식임.
// 큐에 넣을 때 방문했다고 체크해야 함
void bfs(int node) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[node] = true; // 먼저 체크!!
    q.push(node);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(int i = 0; i<a[tmp].size(); i++) {
            int next = a[tmp][i];
            if(check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

// 인접행렬을 이용한 bfs
// void bfs(int node) {
//     queue<int> q;
//     memset(check, false, sizeof(check));
//     check[node] = true; // 먼저 체크!!
//     q.push(node);
//     while(!q.empty()) {
//         int tmp = q.front();
//         q.pop();
//         cout << tmp << ' ';
//         for(int i=1;i<=n; i++) { // 이 부분이 다름
//             if(a[x][i]==1 && check[i] == false) { // 이 부분이 다름
//                 check[i] = true;
//                 q.push(i);
//             }
//         }
//     }
// }


int main() {
    int n, m, start;
    cin >> n >> m >> start;
    for(int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i<=n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    cout << '\n';
    bfs(start);
    cout << '\n';
}