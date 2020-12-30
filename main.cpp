//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)
int N;
// 옮긴 횟수
int K;

void hanoi(int num, int start, int end, int mid) {
    if (num == 1) {
        printf("%d -> %d\n", start, end);
        return;
    }

    hanoi(num - 1, start, mid, end);
    printf("%d -> %d\n", start, end);
    hanoi(num - 1, mid, end, start);
}

void input() {
    scanf("%d", &N);

    hanoi(N, 1, 3, 2);
}

void solution() {

}

int main() {
    input();
    solution();
}