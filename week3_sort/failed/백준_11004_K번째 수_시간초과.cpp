//
// Created by 최우영 on 2020/11/17.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)
int N, K;
// 숫자 담을 vector
vector<int> container;

bool compare(const int &first, const int &second) {
    return first < second;
}

void input() {
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        container.push_back(temp);
    }
}

void solution() {
    sort(container.begin(), container.end(), compare);

    cout << container[K - 1];
}

int main() {
    input();
    solution();
}