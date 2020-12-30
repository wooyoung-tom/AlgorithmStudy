//
// Created by 최우영 on 2020/12/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3^k이며,
// 이때 1 ≤ k < 8이다.
int N;

void star(int i, int j, int num) {
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        printf(" ");
    } else {
        if (num / 3 == 0) printf("*");
        else star(i, j, num / 3);
    }
}

void input() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            star(i, j, N);
        }
        printf("\n");
    }
}

void solution() {

}

int main() {
    input();
    solution();
}