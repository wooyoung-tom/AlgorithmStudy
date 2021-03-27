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
int cnt[MAX];

int main() {
    // 최대값 넣을 변수 두개 (갯수 최대값, 같을 경우의 큰 수)
    int maxCnt = -1, maxNum = -1;
    int digit;

    // 자연수의 길이는 100을 넘지 않습니다.
    // 문자열로도 컨트롤 가능하다.
    char num[101];
    scanf("%s", num);

    for (int i = 0; num[i] != '\0'; ++i) {
        digit = num[i] - 48;
        cnt[digit]++;
    }

    // 어차피 순차적으로 도니까 한번 더 검사할 필요가 없어짐.
    for (int i = 0; i < MAX; ++i) {
        if (cnt[i] >= maxCnt) {
            maxCnt = cnt[i];
            maxNum = i;
        }
    }

    printf("%d\n", maxNum);
}