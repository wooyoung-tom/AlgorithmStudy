//
// Created by 최우영 on 2020/12/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)
int N, M;
vector<int> deck;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;
        deck.push_back(card);
    }
}

void solution() {
    int maxValue = 0;

    for (int i = 0; i < N; ++i) {
        int firstCard = deck[i];
        for (int j = i + 1; j < N; ++j) {
            int secondCard = deck[j];
            for (int k = j + 1; k < N; ++k) {
                int thirdCard = deck[k];
                int sum = firstCard + secondCard + thirdCard;

                if (sum > M) continue;
                else if (sum == M) {
                    maxValue = M;
                    break;
                } else maxValue = max(maxValue, sum);
            }
        }
    }

    cout << maxValue;
}

int main() {
    input();
    solution();
}