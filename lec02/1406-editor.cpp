// 2020.09.25
// 자료구조 1 강의 예제 복습
// BOJ 1406 - editor

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char a[600000];
    cin >> a;
    stack<char> left, right;
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        left.push(a[i]);
    }
    int m;
    cin >> m;
    while (m--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        } else if (cmd == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else if (cmd == 'P') {
            char c;
            cin >> c;
            left.push(c);
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    cout << '\n' ; 
    return 0;
    

}