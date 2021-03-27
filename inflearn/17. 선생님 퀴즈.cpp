//
// Created by 최우영 on 2021/01/08.
//

#include <iostream>

using namespace std;

int main() {
    // 반 학생수인 자연수 N(1<=N<=10)
    int N;
    int card, res;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int tmp = 0;

        scanf("%d %d", &card, &res);

        for (int j = 1; j <= card; ++j) {
            tmp += j;
        }

        if (tmp == res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}