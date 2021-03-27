//
// Created by 최우영 on 2020/12/30.
//

#include <iostream>

using namespace std;

int main() {
    // 자연수 N(3<=N<100,000)
    int N;
    int cnt = 0;

    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        int temp = i;

        while (temp > 0) {
            // 10 을 나누면 한자리 씩 지워진다고 생각하면 됨.
            temp /= 10;
            cnt++;
        }
    }

    printf("%d\n", cnt);
}