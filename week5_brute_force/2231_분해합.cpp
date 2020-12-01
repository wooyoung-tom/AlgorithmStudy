//
// Created by 최우영 on 2020/12/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// N(1 ≤ N ≤ 1,000,000)
int N;

void input() {
    cin >> N;
}

void solution() {
    int answer = 0;

    // 생성자는 N 보다 작다.
    for (int i = 1; i < N; ++i) {
        // 현재 비교하려는 자연수
        int currentInteger = i;
        string currentString = to_string(currentInteger);

        // 현재 비교하려는 자연수의 자리수 모두 더한 값
        int sum = 0;
        for (int j = 0; j < currentString.length(); ++j) {
            char currentChar = currentString[j];
            sum += (currentChar - 48);
        }

        // N 에서 현재 자연수 뺀 값
        int target = N - currentInteger;
        // sum 과 target 이 같다면 해당 수가 분해합 중 가장 작은 수
        if (sum == target) {
            answer = currentInteger;
            break;
        }
    }

    cout << answer << "\n";
}

int main() {
    input();
    solution();
}