//
// Created by 최우영 on 2021/03/02.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    stack<char> cStack;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (cStack.empty()) {
            // 스택이 비어있다면 문자 Stack 에 push
            cStack.push(s[i]);
            continue;
        }

        char topChar = cStack.top();
        if (topChar == s[i]) {
            // Stack 의 top 에 있는 문자가 현재 문자와 같다면
            cStack.pop();
        } else {
            // Stack 의 top 에 있는 문자가 현재 문자와 다르다면
            cStack.push(s[i]);
        }
    }

    if (cStack.empty()) answer = 1;
    else answer = 0;

    return answer;
}

int main() {
    string s = "cdcd";

    cout << solution(s);
}