//
// Created by 최우영 on 2020/12/02.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// N은 10,000보다 작거나 같은 자연수
typedef long long ll;
int N;

void input() {
    cin >> N;
}

void solution() {
    int counter = 0;
    ll answerNum;
    string answerStr;

    for (int i = 0; i < N; ++i) {
        // 최소 범위, 최대 범위 설정
        ll minRange = i * 1000;
        ll maxRange = (i + 1) * 1000;
        // i * 1000 부터 maxRange 까지
        for (int j = minRange; j < maxRange; ++j) {
            const string currentNumStr = to_string(j);
            // 최소 세개 이상 포함이므로 666만 들어가면 된다.
            // 666 이 포함되어 있을 때 counter 1 늘려 나간다.
            if (currentNumStr.find("666") != string::npos) {
                counter++;
                if (counter == N) {
                    answerStr = currentNumStr;
                    break;
                }
            }
        }
    }

    cout << answerStr << "\n";
}

int main() {
    input();
    solution();
}