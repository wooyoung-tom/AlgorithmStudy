//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000)
int N;
vector<string> strVector;

bool compare(const string &first, const string &second) {
    // 1. 길이 짧은 순 정렬
    if (first.length() < second.length()) return true;
        // 2. 길이가 같을 때 사전순 정렬
    else if (first.length() == second.length()) return first < second;
        // 3. 길이 길 때
    else return false;
}

bool isPossible(const string &str) {
    for (auto & i : strVector) {
        if (str == i) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        if (isPossible(tmp)) strVector.push_back(tmp);
        else continue;
    }

    sort(strVector.begin(), strVector.end(), compare);

    for (auto & i : strVector) {
        cout << i << "\n";
    }
}