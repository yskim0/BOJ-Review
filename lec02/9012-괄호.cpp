#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--) {
        string s;
        cin >> s;
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if (cnt<0) {
                cout << "NO\n";
            } 
        }
        if (cnt == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}