//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다.
// (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
// 나무의 높이의 합은 항상 M을 넘기 때문에,
// 상근이는 집에 필요한 나무를 항상 가져갈 수 있다.
// 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.
int N, M;
vector<int> treeHeights;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int tree;
        cin >> tree;
        treeHeights.push_back(tree);
    }
}

void solution() {

}

int main() {
    input();
    solution();
}