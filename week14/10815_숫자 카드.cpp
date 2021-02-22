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

void input() {
    int tmp;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        card.push_back(tmp);
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        intArr.push_back(tmp);
    }

    // 입력받은 카드 벡터를 오름차순으로 정렬
    sort(card.begin(), card.end());
}

bool binarySearch(int target) {
    int left = 0, right = N;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < card[mid]) {
            right = mid - 1;
        } else if (target > card[mid]) {
            left = mid + 1;
        }

        if (target == card[mid]) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    // M 개의 정수를 돌면서 BS
    for (int i = 0; i < M; ++i) {
        if (binarySearch(intArr[i])) {
            cout << "1" << " ";
        } else {
            cout << "0" << " ";
        }
    }
}