//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int rArr[42];

int main() {
    int num;
    int rCnt = 0;

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &num);

        // 나머지가 이전에 나온 적 없을 때
        if (rArr[num % 42] == 0) {
            rArr[num % 42]++;
            rCnt++;
        }
    }

    printf("%d", rCnt);
}