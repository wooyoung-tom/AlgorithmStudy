//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    // 자연수의 개수 N(2<=N<=200,000)
    int N;
    int cnt = 0;

    scanf("%d", &N);

    // 1은 소수가 아니기 때문에 2부터 돌아야 한다.
    for (int i = 2; i <= N; ++i) {
        // 소수인지 아닌지 판별하는 변수 선언
        bool isPrime = true;

        // 해당 수의 제곱근까지만 돌면 소수인지 아닌지 알 수 있다.
        for (int j = 2; j*j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) cnt++;
    }

    printf("%d", cnt);
}