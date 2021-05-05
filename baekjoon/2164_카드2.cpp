//
// Created by 최우영 on 2021/05/05.
//

#include <iostream>
#include <deque>

using namespace std;

int N;

deque<int> cards;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cards.push_back(i);
    }

    while (true) {
        if (cards.size() == 1) break;
        cards.pop_front();
        if (cards.size() == 1) break;
        int front = cards.front();
        cards.pop_front();
        cards.insert(cards.end(), front);
    }

    cout << cards.front();
}