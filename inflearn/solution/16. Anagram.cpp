//
// Created by 최우영 on 2021/01/07.
//

#include <iostream>

using namespace std;

int a[60], b[60];

int main() {
    char str[100];
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; ++i) {
        // ASCII 범위가 대문자일 때
        if (str[i] >= 65 && str[i] <= 90) {
            a[str[i]-64]++;
        }
            // ASCII 범위가 소문자일 때
        else a[str[i]-70]++;
    }

    for (int i = 0; str[i] != '\0'; ++i) {
        // ASCII 범위가 대문자일 때
        if (str[i] >= 65 && str[i] <= 90) {
            b[str[i]-64]++;
        }
            // ASCII 범위가 소문자일 때
        else b[str[i]-70]++;
    }

    for (int i = 1; i < 52; ++i) {
        if (a[i] != b[i]) {
            printf("NO\n");
            exit(0);
        }
    }

    printf("YES\n");
}