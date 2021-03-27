//
// Created by 최우영 on 2021/03/02.
//

#include <iostream>

using namespace std;

// 첫 번째 줄에 Test case 의 수 T가 주어진다.
// 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다
int T, k, n;
int apartment[15][15];

void initApartment() {
    // i -> 층수
    for (int i = 0; i <= 14; ++i) {
        // j -> 호수
        for (int j = 1; j <= 14; ++j) {
            if (i == 0) {
                // 0층이라면 호수 그대로
                apartment[i][j] = j;
            } else {
                // 다른 층이라면 아래 층에 영향을 받는다.
                int downStair = i - 1;
                for (int l = 1; l <= j; ++l) {
                    apartment[i][j] += apartment[downStair][l];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initApartment();

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> k >> n;
        cout << apartment[k][n] << "\n";
    }
}