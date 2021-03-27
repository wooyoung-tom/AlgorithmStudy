//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <climits>

using namespace std;

// 1 ≤ w, h ≤ 1,000
int x, y, w, h;
int distanceArr[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int min = INT_MAX;

    cin >> x >> y >> w >> h;

    // 직선으로 가는 것이 가장 빠름
    distanceArr[0] = x;
    distanceArr[1] = w - x;
    distanceArr[2] = h - y;
    distanceArr[3] = y;

    for (int i : distanceArr) {
        if (min > i) min = i;
    }

    cout << min;
}