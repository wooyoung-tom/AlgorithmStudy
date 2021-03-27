//
// Created by 최우영 on 2021/01/08.
//

#include <iostream>

using namespace std;

int main() {
    int a[10], b[10];
    int aSum = 0, bSum = 0;
    char winner = 'D';

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 10; ++i) {
        if (a[i] == b[i]) {
            aSum++;
            bSum++;
        } else if (a[i] > b[i]) {
            aSum += 3;
            winner = 'A';
        } else if (a[i] < b[i]) {
            bSum += 3;
            winner = 'B';
        }
    }

    printf("%d %d\n", aSum, bSum);

    if (aSum == bSum) printf("%c", winner);
    else if (aSum > bSum) printf("A");
    else if (aSum < bSum) printf("B");
}