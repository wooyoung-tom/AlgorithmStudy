//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 4000 + 1

using namespace std;

// 배열의 크기 n (1 ≤ n ≤ 4000)
int n;
// 숫자 담아놓을 배열 선언 (어차피 배열 최대 크기가 n)
int A[MAX], B[MAX], C[MAX], D[MAX];

void input() {
    // 배열의 크기를 입력 받음
    scanf("%d", &n);

    // n 만큼 돌면서 배열 element 하나씩 받는다.
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }
}

void solution() {

}

int main() {
    input();
    solution();
}