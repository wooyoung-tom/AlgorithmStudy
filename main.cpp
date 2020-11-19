//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// 수열 A 의 크기 N (1 ≤ N ≤ 1,000,000)
int N;
vector<int> A;

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        A.push_back(num);
    }
}

void solution() {
    // A 의 중간값을 pivot 으로 설정
    int pivot = A[N / 2];
    
}

int main() {
    input();
    solution();
}