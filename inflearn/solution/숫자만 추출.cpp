//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    // 문자열의 길이는 50을 넘지 않습니다.
    char a[100];

    int result = 0, count = 0;

    scanf("%s", &a);

    // 문자열을 배열에 read 하게되면, 마지막 요소는 \0 이 들어가게 된다.
    for (int i = 0; a[i] != '\0'; ++i) {
        // 숫자가 되는 조건 (ASCII 범위 확인)
        if (a[i] >= 48 && a[i] <= 57) {
            // 앞자리 부터 하나씩 추가하면서 진행한다.
            result = result * 10 + (a[i] - 48);
        }
    }

    printf("%d\n", result);

    // 약수 구하기
    for (int i = 1; i <= result; ++i) {
        if (result % i == 0) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}