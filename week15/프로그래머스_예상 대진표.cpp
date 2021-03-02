//
// Created by 최우영 on 2021/03/02.
//

#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;

    while (true) {
        // 차이가 1 일 때
        if (abs(a - b) == 1) {
            if (min(a, b) % 2 == 0) {
                // 1 작은 수가 짝수이면 한 번 더 올라가야 한다.
                a /= 2;
                b = b / 2 + 1;
            } else {
                // 1 작은 수가 홀수이면 끝난다.
                break;
            }
        } else {
            // 한 칸 올라간다.
            if (a % 2 == 0) a /= 2;
            else a = a / 2 + 1;

            if (b % 2 == 0) b /= 2;
            else b = b / 2 + 1;
        }

        answer++;
    }

    return answer;
}

int main() {
    int N = 8, A = 1, B = 8;

    cout << solution(N, A, B);
}