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

// 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)
int N, C;
vector<int> house;

int lower, upper;
int maxValue = 0;

void input() {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        if (maxValue < x) maxValue = x;

        house.push_back(x);
    }
}

void solution() {
    int distance = 0;

    // 오름차순으로 정렬
    sort(house.begin(), house.end());

    // 최소거리 및 최대거리
    lower = 1;
    upper = maxValue - house[0];

    while (lower <= upper) {
        // 시작점에 공유기를 설치 한 후 시작한다고 가정.
        int result = 1;
        int start = house[0];

        int mid = (lower + upper) / 2;

        for (int i = 1; i < N; ++i) {
            if (house[i] - start >= mid) {
                start = house[i];
                result++;
            }
        }

        if (result >= C) {
            distance = mid;
            lower = mid + 1;
        } else {
            upper = mid - 1;
        }
    }

    cout << distance << "\n";
}

int main() {
    input();
    solution();
}