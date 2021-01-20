// Copyright 2021 Ilya Tatsenko
#include<iostream>
#include<string>

#include"MyStack.h"
#include"postfix.h"


int function(char x) {
    switch (x) {
    case '(': return 0; break;
    case ')': return 1; break;
    case '+': return 2; break;
    case '-': return 2; break;
    case '*': return 3; break;
    case '/':return 3; break;
    case ' ':return 100; break;
    default: return -1;
    }
}
std::string infix2postfix(std::string x) {
    MyStack<char> st(x.size());
    std::string new_str;

    for (int i = 0; i < x.size(); i++) {
        if (function(x[i]) == 100) continue;
        if (function(x[i]) == -1) {
            if (x[i] == '.' || x[i + 1] == '.') {
                new_str += x[i];
                continue;
            } else {
                new_str += x[i];
                new_str += ' ';
                continue;
            }
        }
        if (function(x[i]) == 1) {
            while (function(st.get()) != 0) {
                new_str += st.pop();
                new_str += ' ';
            }
            st.pop();
            continue;
        }
        int t = function(x[i]);
        if (st.isEmpty() || t == 0 || t > function(st.get())) {
            st.push(x[i]);
            continue;
        } else if (function(st.get()) >= function(x[i])) {
            new_str += st.pop();
            new_str += ' ';
            st.push(x[i]);
            continue;
        }
        }
    if (!st.isEmpty()) {
        while (!st.isEmpty()) {
            new_str += st.pop();
            new_str += ' ';
        }
    }
     new_str.pop_back();
    return new_str;
}
