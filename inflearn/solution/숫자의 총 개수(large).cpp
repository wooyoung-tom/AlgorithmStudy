//
// Created by 최우영 on 2020/12/30.
//

#include <iostream>

using namespace std;

int main() {
    // 자연수 N(3<=N<=100,000,000)
    // sum: 누적되는 숫자 (9, 99, 999...)
    // c: 자리수 (1, 2, 3...)
    // d: 자리수의 개수 (9, 90, 900...)
    int N, sum = 0, c = 1, d = 9, res = 0;

    scanf("%d", &N);

    // 누적되는 수 + 자리수의 개수가 현재 입력된 수보다 작으면 바로 계산해버린다.
    while (sum + d < N) {
        res += (c * d);
        sum += d;
        c++;
        d *= 10;
    }

    res += (N - sum) * c;

    printf("%d\n", res);
}