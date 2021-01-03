//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

// N이 주어진다. (1 ≤ N < 15)
int N;
// row 마다 놓을 위치 저장할 배열 선언
int row[15];
int res;

bool isPromising(int depth) {
    // 이전 queen 위치
    for (int i = 0; i < depth; ++i) {
        int oldColumn = row[i];
        int newColumn = row[depth];

        if (oldColumn == newColumn) return false;
        if (abs(depth - i) == abs(row[depth] - row[i])) return false;
    }

    return true;
}

void queen(int depth) {
    // depth 가 N 과 같아지면 성공한 것
    if (depth == N) {
        res++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        row[depth] = i;

        // 유망한지 확인
        if (isPromising(depth)) queen(depth + 1);
    }
}

int main() {
    scanf("%d", &N);

    queen(0);

    printf("%d", res);
}