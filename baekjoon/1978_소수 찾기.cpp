//
// Created by 최우영 on 2021/03/27.
//

#include <iostream>
#include <cmath>

using namespace std;

int N;

bool isPrimeNumber(int targetNumber) {
    for (int i = 2; i <= sqrt(targetNumber); ++i) {
        if (targetNumber % i == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int answer = 0;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (num == 1) continue;
        else if (isPrimeNumber(num)) answer++;
    }

    cout << answer << "\n";
}