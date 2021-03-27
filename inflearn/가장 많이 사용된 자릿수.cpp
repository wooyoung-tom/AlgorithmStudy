//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

#define MAX 10

using namespace std;

typedef long long ll;

// 해당 자연수의 갯수를 담아놓을 배열 선언
// 0~9 까지만 있으면 된다.
// 전역 변수이기 때문에 compile time 에 0으로 모두 초기화 된다.
ll cnt[MAX];

int main() {
    // 최대값 넣을 변수 두개 (갯수 최대값, 같을 경우의 큰 수)
    int maxCnt = -1, maxNum = -1;

    // 자연수의 길이는 100을 넘지 않습니다.
    ll num;
    scanf("%lld", &num);

    // 입력된 자연수가 0이 아닌 동안 루프
    while (num > 0) {
        // 10으로 나눈 나머지가 현재 자연수의 제일 끝자리 숫자
        ll end = num % 10;
        // 제일 끝자리 숫자의 인덱스 카운트 하나 올려줌
        cnt[end]++;

        // 마지막에 10 나누어 준다.
        num /= 10;
    }

    // 계산해 놓은 카운트 배열을 순회하면서 진행
    for (int i = 0; i < MAX; ++i) {
        if (maxCnt < cnt[i]) {
            maxNum = i;
            maxCnt = cnt[i];
        }
        else if (maxCnt == cnt[i]) {
            if (maxNum < i) maxNum = i;
        }
    }

    printf("%d", maxNum);
}