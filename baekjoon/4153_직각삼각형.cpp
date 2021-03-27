//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a = -1, b = -1, c = -1;
    long long sA, sB, sC;

    vector<long long> lengthVector;

    while (true) {
        cin >> a >> b >> c;

        // 셋 다 0, 0, 0 입력되면 프로그램 종료
        if (a == 0 && b == 0 && c == 0) break;

        lengthVector.push_back(a);
        lengthVector.push_back(b);
        lengthVector.push_back(c);

        sort(lengthVector.begin(), lengthVector.end());

        sA = lengthVector[0] * lengthVector[0];
        sB = lengthVector[1] * lengthVector[1];
        sC = lengthVector[2] * lengthVector[2];

        if (sA + sB == sC) cout << "right\n";
        else cout << "wrong\n";

        // 끝났으면 벡터 초기화
        lengthVector.clear();
    }
}