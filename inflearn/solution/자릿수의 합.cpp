//
// Created by 최우영 on 2020/12/29.
//

#include <iostream>

using namespace std;

int digit_sum(int x) {
    int temp, res = 0;

    while (x > 0) {
        // 10 나누고 남은 값을 res 에 더한다.
        temp = x % 10;
        res += temp;
        x = x / 10;
    }

    return res;
}

int main() {
    // 자연수의 개수 N(3<=N<=100)
    int N;
    // num: 입력받는 자연수, sum: 해당 자연수의 자릿수 합
    int num, sum;
    // max: 가장 큰 자릿수 합, maxNum: 입력받은 수 중에 자릿수 합이 가장 큰 수
    int max = 0, maxNum = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);

        sum = digit_sum(num);

        if (max < sum) {
            max = sum;
            maxNum = num;
        } else if (max == sum) {
            if (maxNum < num) maxNum = num;
        }
    }

    cout << maxNum;
}