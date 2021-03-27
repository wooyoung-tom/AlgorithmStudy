//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <string>

using namespace std;

int alphabet[26];
string S;

void init() {
    for (int & i : alphabet) {
        i = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    cin >> S;

    for (int i = 0; S[i] != '\0' ; ++i) {
        // -1 이 아니면 이미 첫 번째 위치가 저장되어 있다는 뜻임
        if (alphabet[S[i] - 97] != -1) continue;

        // -1 이면 지금이 첫 번째 위치가 된다.
        alphabet[S[i] - 97] = i;
    }

    for (int i : alphabet) {
        cout << i << " ";
    }
}