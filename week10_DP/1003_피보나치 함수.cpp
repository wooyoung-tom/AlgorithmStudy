//
// Created by 최우영 on 2021/01/25.
//

#include <iostream>

using namespace std;

struct Counter {
    int zero, one;
};

int T;
Counter res[41];

void init() {
    res[0] = Counter{1, 0};
    res[1] = Counter{0, 1};

    for (int i = 2; i <= 40; ++i) {
        res[i].zero = res[i - 1].zero + res[i - 2].zero;
        res[i].one = res[i - 1].one + res[i - 2].one;
    }
}

int main() {
    int tmp;

    scanf("%d", &T);

    init();

    for (int i = 0; i < T; ++i) {
        scanf("%d", &tmp);

        printf("%d %d\n", res[tmp].zero, res[tmp].one);
    }
}