//
// Created by 최우영 on 2020/11/01.
//

// 백준 1931 (https://www.acmicpc.net/problem/1931)

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000 + 1

using namespace std;

int N;
int t_begin[MAX], t_end[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> t_begin[i] >> t_end[i];
    }
}

int schedule() {
    // 일찍 끝나는 순서대로 정렬한다.
    vector<pair<int, int>> order;
    for (int i = 0; i < N; i++) {
        order.push_back(make_pair(t_end[i], t_begin[i]));
    }
    sort(order.begin(), order.end());

    // earliest: 다음 회의가 시작할 수 있는 가장 빠른 시간
    // selected: 지금까지 선택한 회의 수
    int earliest = 0, selected = 0;
    for (int i = 0; i < order.size(); ++i) {
        int meeting_begin = order[i].second;
        int meeting_end = order[i].first;

        if (earliest <= meeting_begin) {
            // earliest 를 마지막 회의가 끝난 시간으로 갱신한다.
            earliest = meeting_end;
            ++selected;
        }
    }
    return selected;
}

int main() {
    input();
    int answer = schedule();

    cout << answer;
}