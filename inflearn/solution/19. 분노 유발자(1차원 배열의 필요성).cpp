//
// Created by 최우영 on 2021/01/08.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int h[101];
    int cnt = 0, max;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }

    max = h[n];
    for (int i = n - 1; i >= 1; --i) {
        if (h[i] > max) {
            max = h[i];
            cnt++;
        }
    }

    printf("%d", cnt);
}