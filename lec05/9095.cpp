#include <iostream>
using namespace std;

int go(int sum, int goal) {
    if(sum > goal) return 0;
    if(sum == goal) return 1;
    int now = 0;
    for(int i = 1; i<=3; i++) {
        now += go(sum+i, goal);
    }
    return now;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int goal; cin >> goal;
        cout << go(0, goal) <<'\n';
    }
    return 0;
}