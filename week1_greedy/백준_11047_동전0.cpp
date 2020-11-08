//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>

using namespace std;

// 1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000
int N, K;
vector<int> A;

void input() {
    cin >> N >> K;
    // Container A 에 동전 입력받아 넣어준다.
    for (int i = 0; i < N; ++i) {
        int input_coin;
        cin >> input_coin;
        A.push_back(input_coin);
    }
}

int solution() {
    bool complete = false;
    int selected = 0;
    // 큰 것 부터 확인한다.
    // 중복 되어야 하기때문에 계속해서 진행하여야 한다.
    while (!complete) {
        for (int i = A.size() - 1; i >= 0; --i) {
            int current_coin = A[i];
            // 현재 동전이 목표 금액보다 크다면 필요없으니
            // 해당 동전 Container 에서 지운다.
            if (K - current_coin < 0) {
                A.pop_back();
            }
            // 현재 동전이 목표 금액과 같다면 고르고 끝내면 된다.
            else if (K - current_coin == 0) {
                selected++;
                complete = true;
                break;
            }
            // 현재 동전이 목표 금액보다 작다면,
            // K 에서 현재 동전 금액을 빼고, selected 하나 증가시킨다.
            else {
                K -= current_coin;
                selected++;
                break;
            }
        }
    }
    return selected;
}

int main() {
    input();

    int result = solution();

    cout << result;
}