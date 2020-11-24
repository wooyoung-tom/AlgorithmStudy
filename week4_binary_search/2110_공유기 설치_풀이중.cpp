//
// Created by 최우영 on 2020/11/24.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)
int N, C;
vector<int> housePoint;

void input() {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        housePoint.push_back(x);
    }
}

void solution() {

}

int main() {
    input();
    solution();
}