//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    // 문자열의 최대 길이는 30이다.
    char a[31];
    int count = 0;

    scanf("%s", a);

    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] == '(') count++;
        else if (a[i] == ')') count--;

        if (count < 0) break;
    }

    if (count == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}