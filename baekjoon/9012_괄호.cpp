//
// Created by djdj7 on 2020-05-21.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int T;
vector<string> str_v;

void input() {
    string input_str;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> input_str;
        str_v.push_back(input_str);
    }
}

void solution() {
    stack<char> _stack;
    for (int i = 0; i < str_v.size(); ++i) {
        string current_str = str_v[i];
        for (int j = 0; j < current_str.length(); ++j) {
            char current_char = current_str[j];
            if (current_char == '(') {
                _stack.push(current_char);
            } else {
                if (!_stack.empty()) {
                    if (_stack.top() == '(') {
                        _stack.pop();
                    }
                } else {
                    _stack.push(current_char);
                }
            }
        }
        if (!_stack.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        while (!_stack.empty()) {
            _stack.pop();
        }
    }
}

int main() {
    input();
    solution();
}