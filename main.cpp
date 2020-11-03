//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의의 수 N(1 ≤ N ≤ 100,000)
int N;

// 시작하는 시간과 끝나는 시간을 구조화
struct time_table {
    int start, end;
};

// 시간 담아놓을 vector
vector<time_table> time_v;

void input() {
    cin >> N;

    // 회의 수 N 만큼 입력받는다.
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        time_v.push_back(time_table{start, end});
    }
}

void solution() {
    //
}

int main() {
    input();
    solution();
}