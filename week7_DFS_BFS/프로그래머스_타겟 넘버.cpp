//
// Created by 최우영 on 2021/01/07.
//

#include <iostream>
#include <vector>
#include <stack>

#define MAX 30

using namespace std;

char operation[] = {'+', '-'};
int tmp[20];
int res;

vector<int> tmpNumbers;
int tmpTarget;
int tmpSize;

bool checkTarget() {
    int tmpRes = 0;
    for (int i = 0; i < tmpSize; ++i) {
        tmpRes += tmp[i];
    }
    return tmpRes == tmpTarget;
}

void dfs(int depth) {
    if (depth == tmpSize) {
        if (checkTarget()) res++;
        return;
    }

    for (int i = 0; i < 2; ++i) {
        if (operation[i] == '+') {
            tmp[depth] = tmpNumbers[depth];
        } else {
            tmp[depth] = -tmpNumbers[depth];
        }

        dfs(depth + 1);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    tmpNumbers = numbers;
    tmpTarget = target;
    tmpSize = numbers.size();

    dfs(0);

    answer = res;

    return answer;
}

int main() {
    vector<int> v = {1, 1, 1, 1, 1};
    int t = 3;
    solution(v, t);
}