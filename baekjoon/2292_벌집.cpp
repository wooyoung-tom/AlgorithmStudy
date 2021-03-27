//
// Created by 최우영 on 2021/03/02.
//

#include <iostream>

using namespace std;

typedef long long ll;

// N(1 ≤ N ≤ 1,000,000,000)
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // N 이 1일 경우에 1 출력 후 종료
    if (N == 1) {
        cout << "1";
        return 0;
    }

    ll depth = 1;
    ll start = 2, current = 2;

    while (true) {
        for (int i = start; i <= start + (depth * 6 - 1); ++i) {
            current++;
            if (i == N) {
                cout << depth + 1;
                return 0;
            }
        }
        start = current;
        depth++;
    }
}