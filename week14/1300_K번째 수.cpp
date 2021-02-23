//
// Created by 최우영 on 2021/02/23.
//

#include <iostream>

using namespace std;

// 배열의 크기 N, N은 10^5보다 작거나 같은 자연수
int N, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> k;

    // left, right 설정
    int left = 1, right = k;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long num = 0;

        for (int i = 1; i <= N; ++i) {
            num += min(mid / i, N);
        }

        if (num < k) left = mid + 1;
        else {
            result = mid;
            right = mid - 1;
        }
    }

    cout << result;
}