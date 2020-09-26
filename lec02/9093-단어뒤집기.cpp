#include <iostream>
#include <string>
#include <stack>

using namespace std; 

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; // test case
    cin.ignore();
    
    while (t--) {
        string str;
        getline(cin, str);

        stack<char> s;
        for (char ch : str) {
            if (ch == ' ' || ch == '\n') {
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ch; //이거 안하면 어떻게 될까?
            } else {
                s.push(ch);
            }
        }

    }

    return 0;
}