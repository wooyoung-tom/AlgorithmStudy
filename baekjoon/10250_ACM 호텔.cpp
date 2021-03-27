//
// Created by 최우영 on 2021/03/01.
//

#include <iostream>

using namespace std;

int T;

// 호텔의 층 수, 각 층의 방 수, 몇 번째 손님인지
// (1 ≤ H, W ≤ 99, 1 ≤ N ≤ H × W)
int H, W, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> H >> W >> N;

        int X, Y;
        if (N % H == 0) {
            X = N / H;
            Y = H;
        } else {
            X = N / H + 1;
            Y = N % H;
        }

        int roomNumber = Y * 100 + X;

        cout << roomNumber << "\n";
    }
}