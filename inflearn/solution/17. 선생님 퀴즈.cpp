//
// Created by 최우영 on 2021/01/08.
//

#include <iostream>

using namespace std;

int main() {
    int N, sum, m, ans;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &m, &ans);
        sum = 0;
        for (int j = 1; j <= m; ++j) {
            sum += j;
        }

        if (ans == sum) printf("YES\n");
        else printf("NO\n");
    }
}