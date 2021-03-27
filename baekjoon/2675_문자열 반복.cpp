//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <string>

using namespace std;

// 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)
// 반복 횟수 R(1 ≤ R ≤ 8)
int T, R;
string S;

string solve() {
    string answer = "";
    for (int i = 0; S[i] != '\0'; ++i) {
        // R 만큼 반복해야 함
        for (int j = 0; j < R; ++j) {
            answer += S[i];
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> R >> S;
        cout << solve() << "\n";
    }
}