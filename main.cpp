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

int K, N;
vector<int> length;

int maxValue = 0;

void input() {
    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        int centi;
        cin >> centi;

        maxValue = max(maxValue, centi);

        length.push_back(centi);
    }
}

void solution() {
    int answer = 0;
    int lower = 1;
    int upper = maxValue;

    while (lower <= upper) {
        int count = 0;
        int mid = (lower + upper) / 2;

        for (int i = 0; i < K; ++i) {
            int currentLength = length[i];
            while (currentLength >= 0) {
                if (currentLength - mid >= 0) count++;
                currentLength -= mid;
            }
        }

        if (count <= N) {
            answer = mid;
            lower = mid + 1;
        } else upper = mid - 1;
    }

    cout << answer << "\n";
}

int main() {
    input();
    solution();
}