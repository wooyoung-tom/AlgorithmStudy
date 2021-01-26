//
// Created by 최우영 on 2021/01/26.
//

#include <iostream>

// 최대 1000글자
#define MAX 1001

std::string a, b;
int res[MAX][MAX];

int main() {
    // 두 개의 문자열 입력
    std::cin >> a >> b;

    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i - 1] == b[j - 1]) res[i][j] = res[i - 1][j - 1] + 1;
            else res[i][j] = std::max(res[i - 1][j], res[i][j - 1]);
        }
    }

    printf("%d", res[a.length()][b.length()]);
}