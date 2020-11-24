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

// N(1≤N≤100,000)
// M(1≤M≤100,000)
// 모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.
int N, M;
// 정수 담아놓을 벡터
vector<int> container;
vector<int> targetNumbers;

void input() {
    int temp;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> temp;
        container.push_back(temp);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> temp;
        targetNumbers.push_back(temp);
    }
}

void solution() {
    int pivot;

    // 먼저 container 를 오름차순으로 정렬
    sort(container.begin(), container.end());

    // pivot 을 container 의 중간값으로 놓는다.
    pivot = container[N / 2];

    // pivot 을 target 과 비교
    for (int i = 0; i < M; ++i) {
        bool isContain = false;
        int targetNumber = targetNumbers[i];

        // 1. targetNumber 가 pivot 보다 작다면
        if (targetNumber < pivot) {
            for (int j = 0; j < N / 2; ++j) {
                int containerNumber = container[j];
                if (targetNumber == containerNumber) {
                    isContain = true;
                    break;
                }
            }

            if (isContain)cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (targetNumber > pivot) {
            for (int j = N / 2 + 1; j < N; ++j) {
                int containerNumber = container[j];
                if (targetNumber == containerNumber) {
                    isContain = true;
                    break;
                }
            }
            if (isContain) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}

int main() {
    input();
    solution();
}