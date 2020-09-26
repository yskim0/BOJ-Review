#include <iostream>
#include <string>

struct Queue {
    int data[10000];
    int size = 0;
    int begin, end;
    Queue () {
        begin = 0;
        end = 0;
    }

    void push(int num) {
        data[end] = num;
        end += 1;
    }

    bool empty () {
        if (end - begin == 0) {
            return true;
        } else {
            return false;
        }
    }

    int size() {
        return end- begin;
    }

    int front () {
        return data[begin];
    }

    int back() {
        return data[end - 1];
    }

    int pop() {
        if (empty()) {
            return -1;
        } else {
            begin += 1;
            return data[begin - 1];
        }
    }
};