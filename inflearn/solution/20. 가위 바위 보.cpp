//
// Created by 최우영 on 2021/01/08.
//

#include <iostream>

using namespace std;

int main() {
    int N;
    int a[101], b[101];

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i]) printf("D\n");
        else if (a[i] == 1 && b[i] == 3) printf("A\n");
        else if (a[i] == 2 && b[i] == 1) printf("A\n");
        else if (a[i] == 3 && b[i] == 2) printf("A\n");
        else printf("B\n");
    }
}