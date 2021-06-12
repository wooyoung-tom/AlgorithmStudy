//
// Created by 최우영 on 2021/05/05.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(const string &s) {
    stack<char> stack;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(' || s[i] == '[') {
            // 괄호 여는 것 나왔을 때 무조건 push
            stack.push(s[i]);
        } else if (s[i] == ')') {
            if (stack.empty() || stack.top() != '(') return false;
            if (stack.top() == '(') {
                stack.pop();
            }
        } else if (s[i] == ']') {
            if (stack.empty() || stack.top() != '[') return false;
            if (stack.top() == '[') {
                stack.pop();
            }
        }
    }

    if (stack.empty()) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;

    while (true) {
        getline(cin, input);

        if (input == ".") break;

        if (solution(input)) cout << "yes\n";
        else cout << "no\n";
    }
}
