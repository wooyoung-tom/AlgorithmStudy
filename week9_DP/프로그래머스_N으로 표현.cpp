//
// Created by 최우영 on 2021/01/19.
//

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> memo[10];

int solution(int N, int number) {
    int answer = 0;

    for (int i = 0; i < 8; ++i) {
        answer = 10 * answer + N;
        memo[i].insert(answer);
        for (int j = 0; j < i; ++j) {
            int tmp = i - j - 1;
            for (auto it1 = memo[j].begin(); it1 != memo[j].end(); it1++) {
                for (auto it2 = memo[tmp].begin(); it2 != memo[tmp].end(); it2++) {
                    memo[i].insert(*it1 + *it2);
                    memo[i].insert(*it1 - *it2);
                    memo[i].insert((*it1) * (*it2));
                    if (*it2 != 0) memo[i].insert((*it1) / (*it2));
                }
            }

            auto it = memo[i].find(number);
            if (it != memo[i].end()) return i + 1;
        }
    }

    return -1;
}

int main() {
    cout << solution(2, 11);
}