//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    uint8_t min = 255, max = 0;
    int N, temp;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> temp;
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }

    cout << max - min;

    return 0;
}