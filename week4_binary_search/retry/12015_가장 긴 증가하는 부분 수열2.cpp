//
// Created by 최우영 on 2020/11/23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// 수열 A 의 크기 N (1 ≤ N ≤ 1,000,000)
// (1 ≤ Ai ≤ 1,000,000)
int N;
vector<int> A;

void input() {}

void solution() {
    int temp;
    int length = 0;

    // 벡터에 최소값 하나를 넣는다.
    A.push_back(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> temp;

        if (temp > A.back()) {
            A.push_back(temp);
            length++;
        } else {
            auto index = lower_bound(A.begin(), A.end(), temp);
            *index = temp;
        }
    }

    cout << length;
}

int main() {
//    input();
    solution();
}