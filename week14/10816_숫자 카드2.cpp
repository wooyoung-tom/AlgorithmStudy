//
// Created by 최우영 on 2021/02/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)
// M(1 ≤ M ≤ 500,000)
int N, M;
vector<int> card, intArr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        card.push_back(tmp);
    }

    // 입력받은 카드 벡터를 오름차순으로 정렬
    sort(card.begin(), card.end());

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> tmp;

        // card 벡터에서 tmp 에 대한 lower_bound 찾아준다.
        // 또한 tmp + 1 에 대한 lower_bound 찾아준다.
        auto low = lower_bound(card.begin(), card.end(), tmp);
        auto upper = lower_bound(card.begin(), card.end(), tmp + 1);

        cout << upper - low << " ";
    }
}