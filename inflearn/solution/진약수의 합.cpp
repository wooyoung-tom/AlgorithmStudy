//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    // sum 변수 또한 모든 진약수의 합은 1부터 시작
    int N, sum = 1;

    cin >> N;

    // 모든 수의 진약수이기 때문에 1 출력
    cout << "1";
    for (int i = 2; i < N; ++i) {
        if (N % i == 0) {
            cout << " + " << i;
            sum += i;
        }
    }

    // 마지막 합 출력
    cout << " = " << sum;

    return 0;
}