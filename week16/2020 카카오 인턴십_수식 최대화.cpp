//
// Created by 최우영 on 2021/03/14.
//

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

// 0: +, 1: -, 2: *
int isUsedOperation[3];

vector<vector<char>> permutationOp;
unordered_map<char, int> opPriority;

vector<long long> result;

void setOperations(string expression) {
    vector<char> usedOp;

    // 수식에서 연산자만 골라본다.
    for (int i = 0; expression[i] != '\0'; ++i) {
        // 연산자가 나오면 사용되었다고 FLAG 수정
        if (expression[i] == '+') isUsedOperation[0] = true;
        else if (expression[i] == '-') isUsedOperation[1] = true;
        else if (expression[i] == '*') isUsedOperation[2] = true;
    }

    // 사용된 연산자 벡터에 넣어준다.
    if (isUsedOperation[0]) usedOp.push_back('+');
    if (isUsedOperation[1]) usedOp.push_back('-');
    if (isUsedOperation[2]) usedOp.push_back('*');

    // 사용된 연산자 벡터를 오름차순 정렬한다.
    sort(usedOp.begin(), usedOp.end());

    // 순열 수행
    do {
        permutationOp.push_back(usedOp);
    } while (next_permutation(usedOp.begin(), usedOp.end()));
}

// 숫자가 작을수록 높은 우선순위임
void setOperationsPriority(const vector<char> &permutation) {
    // 연산자 별 우선순위 지정
    for (int j = 0; j < permutation.size(); ++j) {
        if (permutation[j] == '+') opPriority['+'] = j;
        else if (permutation[j] == '-') opPriority['-'] = j;
        else if (permutation[j] == '*') opPriority['*'] = j;
    }
}

long long calculate(const string &expression) {
    // 문자 형식으로 된 숫자 받기 위한 지역변수
    string strNum;

    // 숫자와 연산자 담을 스택 필요
    stack<long long> numStack;
    stack<char> opStack;

    // 수식 순회
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            // 연산자가 나왔을 때 먼저 현재 strNum 을 숫자로 변환하여 저장한다.
            numStack.push(atoi(strNum.c_str()));
            // strNum 푸쉬했으니 초기화
            strNum = "";

            // 연산자 스택이 비어있는지 확인 후 비어있다면 연산자 스택에 push
            if (opStack.empty()) opStack.push(expression[i]);
                // 연산자 스택이 비어있지 않으면 우선순위를 확인해야 한다.
            else {
                // 스택의 top 에 있는 연산자가 우선순위가 작으면 현재 연산자를 스택에 push
                if (opPriority[opStack.top()] > opPriority[expression[i]]) {
                    opStack.push(expression[i]);
                } else { // top 이 현재보다 우선순위가 높거나 같을 때
                    // 스택이 비거나, top 의 우선순위가 현재보다 낮아질 때 까지 순회한다.
                    while (!opStack.empty() && opPriority[opStack.top()] <= opPriority[expression[i]]) {
                        long long res = 0;

                        // 숫자를 담은 stack 에서 상위 두개 꺼낸다.
                        long long rh = numStack.top();
                        numStack.pop();
                        long long lh = numStack.top();
                        numStack.pop();

                        // 상위 두개 꺼냈으면 연산을 수행한다.
                        if (opStack.top() == '*') res = lh * rh;
                        else if (opStack.top() == '+') res = lh + rh;
                        else if (opStack.top() == '-') res = lh - rh;

                        // 결과값을 stack 에 저장한다.
                        numStack.push(res);

                        // 마지막으로 현재 사용한 연산자를 스택에서 제거해준다.
                        opStack.pop();
                    }

                    // 모두 순회를 하게되면 현재 가지고 있던 연산자를 Stack 에 저장한다.
                    opStack.push(expression[i]);
                }
            }
        } else strNum += expression[i];
    }

    // expression 끝나는 것은 항상 숫자로 끝나기 때문에 push 추가해준다.
    numStack.push(atoi(strNum.c_str()));

    // 수식이 끝나면 Stack 에 남아있는 요소들이 있는지 확인한다.
    while (!opStack.empty()) {
        long long res = 0;

        long long rh = numStack.top();
        numStack.pop();
        long long lh = numStack.top();
        numStack.pop();

        // 상위 두개 꺼냈으면 연산을 수행한다.
        if (opStack.top() == '*') res = lh * rh;
        else if (opStack.top() == '+') res = lh + rh;
        else if (opStack.top() == '-') res = lh - rh;

        // 결과값을 stack 에 저장한다.
        numStack.push(res);

        // 마지막으로 현재 사용한 연산자를 스택에서 제거해준다.
        opStack.pop();
    }

    return numStack.top();
}

long long solution(string expression) {
    long long max = LONG_LONG_MIN;

    // 연산자들 세팅 후 순열 수행하는 함수
    setOperations(expression);

    // 순열의 개수만큼 순회해야 한다.
    for (int i = 0; i < permutationOp.size(); ++i) {
        // 연산자 별로 우선순위를 정해주는 작업
        setOperationsPriority(permutationOp[i]);

        // 우선순위를 정했으면 수식을 진행한다.
        // 결과값은 절대값으로 변환한다.
        long long res = abs(calculate(expression));
        if (max < res) max = res;
    }

    return max;
}

int main() {
    string expression = "100-200*300-500+20";
    solution(expression);
}