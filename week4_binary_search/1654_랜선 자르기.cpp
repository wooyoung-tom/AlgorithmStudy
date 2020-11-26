//
// Created by 최우영 on 2020/11/26.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

typedef long long ll;

int K, N;
vector<ll> length;

ll maxValue = 0;

void input() {
    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        ll centi;
        cin >> centi;

        maxValue = max(maxValue, centi);

        length.push_back(centi);
    }
}

void solution() {
    ll answer = 0;
    ll lower = 1;

    // 제일 긴 것을 긴 것만큼 자르지 못하기 때문에
    ll upper = maxValue;

    while (lower <= upper) {
        int count = 0;
        ll mid = (lower + upper) / 2;

        for (int i = 0; i < K; ++i) {
            int currentLength = length[i];
            while (currentLength >= 0) {
                if (currentLength - mid >= 0) count++;
                currentLength -= mid;
            }
        }

        if (count < N) {
            upper = mid - 1;
        } else if (count >= N) {
            answer = mid;
            lower = mid + 1;
        }
    }

    cout << answer << "\n";
}

int main() {
    input();
    solution();
}