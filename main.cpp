//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>

#define MAX 11 + 1

using namespace std;

// 수의 개수 N(2 ≤ N ≤ 11)
int N;
// A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100)
int A[MAX];
// 합이 N-1인 4개의 정수가 주어지는데,
// 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수
int operation[4];

void input() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 4; ++i) {
        scanf("%d", &operation[i]);
    }
}

int main() {
    input();

    
}