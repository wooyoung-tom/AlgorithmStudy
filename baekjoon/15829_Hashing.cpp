//
// Created by 최우영 on 2021/03/03.
//

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int L;
string str;

#define M 1234567891

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H = 0;
    ll R = 1;

    cin >> L;
    cin >> str;

    for (int i = 0; str[i] != '\0'; ++i) {
        // 모든 문자가 소문자로 입력된다.
        // 97을 빼면 a 가 0이 되며, 96을 빼서 a 를 1로 만든다.
        H = (H + (str[i] - 96) * R) % M;
        R = (R * 31) % M;
    }

    cout << H << "\n";
}