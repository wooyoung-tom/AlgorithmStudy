//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    int A, B;

    while (true) {
        scanf("%d %d", &A, &B);

        if (A == 0 && B == 0) break;

        printf("%d\n", A + B);
    }
}