//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    int num;
    int max = 0, idx;

    for (int i = 1; i <= 9; ++i) {
        scanf("%d", &num);

        if (max < num) {
            max = num;
            idx = i;
        }
    }

    printf("%d\n%d", max, idx);
}