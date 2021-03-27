//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    // 첫째 줄에 두 정수 H와 M이 주어진다. (0 ≤ H ≤ 23, 0 ≤ M ≤ 59)
    int H, M;

    scanf("%d %d", &H, &M);

    // Case 1. 45분 뺀 것이 0보다 크거나 같을 때
    if (M - 45 >= 0) {
        // H변화 없이, M만 45분 뒤로 한 후 출력
        printf("%d %d", H, M - 45);
    }
        // Case 2. 45분 뺀 것이 0보다 작을 때
    else {
        // H를 하나 빼야한다.
        int cHour = H - 1;
        // M에서 45분 뺀 값의 절대값을 60에서 뺀다.
        int cMinute = 60 - (abs(M - 45));

        // Case 2-1. cHour 가 0보다 작아졌을 때 바뀐 H는 23이 되어야 함.
        if (cHour < 0) cHour = 23;

        printf("%d %d", cHour, cMinute);
    }
}