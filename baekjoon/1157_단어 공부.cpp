//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <string>
#include <climits>

using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            // 소문자일 경우
            cnt[input[i] - 97]++;
        } else {
            // 대문자일 경우
            cnt[input[i] - 65]++;
        }
    }

    bool isSingle = true;
    int maxCnt = INT_MIN;
    char maxChar = 0;

    // 알파벳 개수 체크
    for (int i = 0; i <= 26; ++i) {
        if (cnt[i] > maxCnt) {
            // 현재 최대값보다 크다면 바꿔줌
            maxCnt = cnt[i];
            maxChar = char (i + 65);
            isSingle = true;
        } else if (cnt[i] == maxCnt) {
            // 최대값이랑 같으면?
            isSingle = false;
        }
    }

    if (isSingle) {
        cout << maxChar;
    } else {
        cout << "?";
    }
}