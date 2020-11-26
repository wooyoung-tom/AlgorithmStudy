//
// Created by 최우영 on 2020/11/25.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

typedef long long ll;

// 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다.
// (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
// 나무의 높이의 합은 항상 M을 넘기 때문에,
// 상근이는 집에 필요한 나무를 항상 가져갈 수 있다.
// 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.
ll N, M;
ll lower, upper, mid;
ll maxValue = 0;
vector<ll> treeHeights;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        ll tree;
        cin >> tree;

        if (maxValue < tree) maxValue = tree;

        treeHeights.push_back(tree);
    }
}

void solution() {
    ll answer = 0;

    lower = 0;
    upper = maxValue;

    while (lower <= upper) {
        ll sum = 0;
        mid = (lower + upper) / 2;

        for (int i = 0; i < N; ++i) {
            if (mid < treeHeights[i])
                sum += treeHeights[i] - mid;
        }

        if (sum >= M) {
            if (answer < mid) answer = mid;
            lower = mid + 1;
        } else upper = mid - 1;
    }

    cout << answer << "\n";

}

int main() {
    input();
    solution();
}