//
// Created by 최우영 on 2021/01/05.
//

#include <iostream>
#include <vector>

#define MAX 11 + 1
#define INF_MIN -1000000000
#define INF_MAX 1000000000

using namespace std;

typedef long long ll;

// 수의 개수 N(2 ≤ N ≤ 11)
int N;
// A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100)
int A[MAX];
// 합이 N-1인 4개의 정수가 주어지는데,
// 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수
int operation[4];
int isVisited[4];

ll minNum = INF_MAX, maxNum = INF_MIN;

void input() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 4; ++i) {
        scanf("%d", &operation[i]);
    }
}

ll calculate(ll left, ll right, int op) {
    ll result;

    switch (op) {
        case 0:
            result = left + right;
            break;
        case 1:
            result = left - right;
            break;
        case 2:
            result = left * right;
            break;
        default:
            result = left / right;
            break;
    }

    return result;
}

void solve(int depth, ll cRes) {
    if (depth == N - 1) {
        if (cRes > maxNum) maxNum = cRes;
        if (cRes < minNum) minNum = cRes;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (isVisited[i] != operation[i]) {
            isVisited[i]++;

            ll newRes = calculate(cRes, A[depth + 1], i);

            solve(depth + 1, newRes);

            isVisited[i]--;
        }
    }
}

int main() {
    input();

    solve(0, A[0]);

    printf("%lld\n%lld", maxNum, minNum);
}