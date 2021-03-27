//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>

using namespace std;

int scales[8];

void solve() {
    string answer;
    for (int i = 0; i < 7; ++i) {
        int cInt = scales[i];
        int nInt = scales[i + 1];

        if (cInt + 1 == nInt) {
            // 현재 정수에 1 더한 값이 다음 정수와 같을 때
            answer = "ascending";
        } else if (cInt - 1 == nInt) {
            // 현재 정수에 1 뺀 값이 다음 정수와 같을 때
            answer = "descending";
        } else {
            // 현재 정수에 1을 더하거나 뺀 값이 아닐 때
            answer = "mixed";
            break;
        }
    }

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; ++i) {
        cin >> scales[i];
    }

    solve();
}