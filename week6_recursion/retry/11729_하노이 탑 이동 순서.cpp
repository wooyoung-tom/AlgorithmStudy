//
// Created by 최우영 on 2020/12/30.
//

#include <iostream>
#include <vector>

using namespace std;

// 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)
int N;
// 옮긴 횟수
int K;
// 옮긴 방향 담을 vector
vector<pair<int, int>> doVector;

void hanoi(int num, int start, int end, int mid) {
    if (num == 1) {
        K++;
        doVector.push_back(make_pair(start, end));
        return;
    }

    hanoi(num - 1, start, mid, end);
    K++;
    doVector.push_back(make_pair(start, end));
    hanoi(num - 1, mid, end, start);
}

void input() {
    scanf("%d", &N);

    hanoi(N, 1, 3, 2);

    printf("%d\n", K);

    for (int i = 0; i < doVector.size(); ++i) {
        printf("%d %d\n", doVector[i].first, doVector[i].second);
    }
}

int main() {
    input();
    solution();
}