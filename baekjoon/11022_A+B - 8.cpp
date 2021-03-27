//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    int T;
    int A, B;

    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i + 1, A, B, A + B);
    }
}