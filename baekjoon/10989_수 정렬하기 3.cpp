//
// Created by 최우영 on 2021/03/09.
//

#include <iostream>

using namespace std;

// 수의 개수 N(1 ≤ N ≤ 10,000,000)
int N;
// 숫자는 10000 이하이다.
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        // 해당 숫자 인덱스 값을 1 늘려준다.
        arr[num]++;
    }

    // 숫자가 가장 큰 경우가 10000 일 때이다.
    for (int i = 0; i <= 10000; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            printf("%d \n", i);
        }
    }
}