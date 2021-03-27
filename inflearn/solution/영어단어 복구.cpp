//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    // 영어단어의 길이(공백포함)는 100을 넘지 않는다
    char a[101], b[101];
    int position = 0;

    // 줄바꿈을 기준으로 문자열을 입력받는다.
    // gets 는 unsafe API 인데?
    gets(a);

    for (int i = 0; a[i] != '\0'; ++i) {
        // 공백을 기준으로 나눈다.
        if (a[i] != ' ') {
            // 대문자
            if (a[i] >= 65 && a[i] <= 90) {
                b[position++] = a[i] + 32;
            }
                // 소문자
            else {
                b[position++] = a[i];
            }
        }
    }
    // 현재 b 배열은 마지막이 \0 으로 끝나는 것이 아니기 때문에
    // 문자열이라고 볼 수 없다. -> 마지막 position 자리에 \0 넣어주어야 한다.
    b[position] = '\0';

    printf("%s\n", b);

    return 0;
}