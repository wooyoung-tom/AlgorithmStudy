//
// Created by djdj7 on 2020-05-25.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> pair_v;

void input() {
    cin >> N;
}

void hanoi(int n, int start, int by, int end) {
    if (n == 1) {
        pair_v.push_back(make_pair(start, end));
    } else {
        hanoi(n - 1, start, end, by);
        pair_v.push_back(make_pair(start, end));
        hanoi(n - 1, by, start, end);
    }
}

int main() {
    input();
    hanoi(N, 1, 2, 3);

    cout << pair_v.size() << "\n";
    for (int i = 0; i < pair_v.size(); ++i) {
        cout << pair_v[i].first << " " << pair_v[i].second << "\n";
    }
}