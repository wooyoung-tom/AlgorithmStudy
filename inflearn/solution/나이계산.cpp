//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    // Input Example (780316-2376152)
    // Output Example (42 W)
    char a[20];
    int year, age;

    scanf("%s", &a);

    // 일곱번 째 숫자가 1 또는 2 이면, 1900년대 생이다.
    if (a[7] == '1' || a[7] == '2') {
        // a[0] 과 a[1] 은 char 자료형이므로 숫자로 변환하여야 한다.
        year = 1900 + ((a[0] - 48) * 10 + (a[1] - 48));
    }
        // 일곱번 째 숫자가 1 또는 2가 아니면, 2000년대 생이다.
    else {
        year = 2000 + ((a[0] - 48) * 10 + (a[1] - 48));
    }

    age = 2019 - year + 1;
    printf("%d ", age);

    if (a[7] == '1' || a[7] == '3') printf("M\n");
    else printf("W\n");

    return 0;
}