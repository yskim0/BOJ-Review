#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[1001]; // 들렀다는 표시
vector<int> a[1001];

// 스택을 이용해서 갈 수 있는 만큼 최대한 많이 가고, 갈 수 없으면 이전 정점으로 돌아감
// 재귀 호출을 이용해서 구현함
void dfs(int node) {
    check[node] = true;
    for(int i = 0; i<a[node].size(); i++) {
        int next = a[node][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int comp = 0;
    for(int i = 1; i<=n; i++) {
        if(check[i] == false) {
            dfs(i);
            comp += 1;
        }
    }
    cout << comp << '\n';
    
}


// 인접 행렬을 이용한 구현임
// void dfs_2(int x) {
//     check[x] = true;
//     for(int i = 1;i<=n;i++) {
//         if(a[x][i] == 1 && check[i] == false) {
//             dfs(i);
//         }
//     }
// }