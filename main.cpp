#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 0: +, 1: -, 2: *
int isUsedOperation[3];
vector<char> usedOp;
vector<vector<char>> permutationOp;
unordered_map<char, int> opPriority;

stack<long long> numStack;
stack<char> opStack;

vector<long long> result;

long long solution(string expression) {
    long long answer = 0;

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

    // 순열의 갯수만큼 순회
    for (int i = 0; i < permutationOp.size(); ++i) {
        vector<char> cPermutation = permutationOp[i];

        // 우선순위를 연산자 별로 정해주는 작업
        for (int j = 0; j < cPermutation.size(); ++j) {
            if (cPermutation[j] == '+') opPriority['+'] = j;
            else if (cPermutation[j] == '-') opPriority['-'] = j;
            else if (cPermutation[j] == '*') opPriority['*'] = j;
        }

        // 우선순위를 정했으면 수식을 후위표기식으로 바꾸어 생각한다.
        string numStr = "";
        for (int j = 0; expression[j] != '\0'; ++j) {
            char currentChar = expression[j];

            if (currentChar == '+' || currentChar == '-' || currentChar == '*') {
                // 연산자가 나왔을 때 먼저 현재 numStr 을 저장한다.
                numStack.push(atoi(numStr.c_str()));

                numStr = "";

                // 연산자 스택이 비어있는지 확인하고 비어있다면 push
                if (opStack.empty()) opStack.push(currentChar);
                    // 연산자 스택이 비어있지 않다면 우선순위를 확인해야 한다.
                else {
                    int currentOp = opPriority[currentChar];

                    if (opPriority[opStack.top()] > currentOp) opStack.push(currentChar);
                    else {
                        // Stack 의 top 이 우선순위가 크면서 opStack 이 비어있지 않을 때
                        while (!opStack.empty() && (opPriority[opStack.top()] <= currentOp)) {
                            // 숫자 스택에서 상위 두개 뽑는다.
                            long long rightHand = numStack.top();
                            numStack.pop();
                            long long leftHand = numStack.top();
                            numStack.pop();

                            if (opStack.top() == '+') {
                                numStack.push(leftHand + rightHand);
                            } else if (opStack.top() == '-') {
                                numStack.push(leftHand - rightHand);
                            } else if (opStack.top() == '*') {
                                numStack.push(leftHand * rightHand);
                            }

                            opStack.pop();
                        }

                        opStack.push(currentOp);
                    }
                }
            } else {
                // 연산자가 아닐 때 숫자이므로 numStr 에 더해준다.
                numStr += currentChar;
            }
        }
    }

    return answer;
}

int main() {
    string expression = "100-200*300-500+20";
    solution(expression);
}