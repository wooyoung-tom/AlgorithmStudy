//
// Created by 최우영 on 2021/01/07.
//

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> map;

int main() {
    char a[101], b[101];

    scanf("%s %s", a, b);

    for (int i = 0; a[i] != '\0'; ++i) {
        map[a[i]]++;
    }

    for (int i = 0; b[i] != '\0'; ++i) {
        map[b[i]]--;
    }

    for (int i = 0; a[i] != '\0'; ++i) {
        if (map[a[i]] != 0) {
            printf("NO");
            exit(0);
        }
    }

    printf("YES");
}