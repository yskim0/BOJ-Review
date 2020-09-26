#include <iostream>
#include <string>

using namespace std;

struct Stack
{
    int data[10000];
    int size;
    Stack() {
        size = 0;
    }

    void push(int num) {
        data[size] = num;
        size += 1;
    }

    bool empty() {
        if (size == 0) return true;
        else return false;
    }

    int top() {
        if(!empty()) return data[size-1];
        else return -1;
    }

    int pop() {
        if(!empty()) {
            size -= 1;
            return data[size];
        }
        else return -1;
    }

};

