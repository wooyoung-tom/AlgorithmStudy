//
// Created by 최우영 on 2021/03/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수의 개수 N(1 ≤ N ≤ 1,000,000)
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp = 0;
    vector<int> container;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        container.push_back(tmp);
    }

    sort(container.begin(), container.end());

    for (int i = 0; i < container.size(); ++i) {
        cout << container[i] << "\n";
    }
}