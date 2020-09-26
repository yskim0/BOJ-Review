#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    stack<int> s;
    vector<int> a(n); // 0으로 초기화된 n개의 원소가지느 벡터 생성
    vector<int> ans(n); // 

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    s.push(0); // 
    for (int i =1; i<n; i++) {
        if(s.empty()){
            s.push(i);
        }
        while(!s.empty() && a[s.top()] < a[i]) {
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
