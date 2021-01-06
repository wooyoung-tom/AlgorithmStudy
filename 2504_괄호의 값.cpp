//
// Created by 최우영 on 2021/01/06.
//

#include <iostream>
#include <vector>
#include <stack>

#define MAX 30

using namespace std;

// 첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다.
// 단 그 길이는 1 이상, 30 이하이다.
char parenthesis[MAX];

stack<char> pStack;

int main() {
    scanf("%s", parenthesis);

    long long res = 0;
    int temp = 1;
    bool isPossible = true;

    for (int i = 0; parenthesis[i] != '\0'; ++i) {
        char current = parenthesis[i];

        if (current == '(') {
            temp *= 2;
            pStack.push(current);
        } else if (current == '[') {
            temp *= 3;
            pStack.push(current);
        } else if (current == ')') {
            // 불가능 할 때
            if (pStack.empty() || pStack.top() != '(') {
                isPossible = false;
                break;
            }
            // 가능 할 때
            if (parenthesis[i - 1] == '(') res += temp;
            pStack.pop();
            temp /= 2;
        } else if (current == ']') {
            // 불가능 할 때
            if (pStack.empty() || pStack.top() != '[') {
                isPossible = false;
                break;
            }
            // 가능 할 때
            if (parenthesis[i - 1] == '[') res += temp;
            pStack.pop();
            temp /= 3;
        }
    }

    // 가능하지 않다고 했거나 stack 이 비어있지 않으면 완성되지 않은 것
    if (!isPossible || !pStack.empty()) printf("%d", 0);
    else printf("%lld", res);
}