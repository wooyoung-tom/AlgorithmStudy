//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

// 자연수를 입력받아 뒤집어서 리턴하는 함수
int reverse(int x) {
    int res = 0;

    while (x > 0) {
        int tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }

    return res;
}

// 자연수를 입력받아 소수인지 확인하는 함수
bool isPrime(int x) {
    // 1은 소수가 아니다.
    if (x == 1) return false;
    // 1과 자기 자신은 무조건 약수이니까 제외하고,
    // 2부터 자기 자신 바로 앞까지 진행
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    // 자연수의 개수 N(3<=N<=100)
    int N;
    int num;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        int rNum = reverse(num);
        if (isPrime(rNum)) printf("%d ", rNum);
    }
}