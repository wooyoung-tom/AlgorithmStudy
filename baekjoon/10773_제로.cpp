//
// Created by djdj7 on 2020-05-22.
//

#include <iostream>
#include <stack>

using namespace std;

int K;
int result;

void input_and_solution() {
    stack<int> _stack;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int current_num;
        cin >> current_num;
        if (current_num != 0) {
            _stack.push(current_num);
        } else {
            _stack.pop();
        }
    }
    while (!_stack.empty()) {
        result += _stack.top();
        _stack.pop();
    }

    cout << result;
}

int main() {
    input_and_solution();
}