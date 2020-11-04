//
// Created by 최우영 on 2020/11/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의 시작 시간, 끝나는 시간 정보 담은 구조체
struct meet_info {
    int start, end;
};

// 회의의 수 N(1 ≤ N ≤ 100,000)
int N;
vector<meet_info> info_v;   // 회의 시간 정보 구조체 담는 벡터

bool compare(const meet_info &first, const meet_info &second) {
    return first.end < second.end;
}

void input() {
    // N 입력받는다.
    cin >> N;

    // N 개 만큼 회의 정보 입력 받는다.
    for (int i = 0; i < N; ++i) {
        int start, end;     // 일시적으로 사용할 temp 변수
        cin >> start >> end;
        // 입력받은 시작 시간과 종료 시간 구조화해서 벡터에 push
        info_v.push_back(meet_info{start, end});
    }
}

void solution() {
    // 결과 담을 변수
    int selected = 0;

    // 현재 끝나는 시간
    int current_end = 0;

    // 정보 담아놓은 벡터를 회의 종료 시간의 오름차순으로 정렬
    // 가장 먼저 끝나는 시간 순서대로 하는 것이 더 Optimal 하다.
    sort(info_v.begin(), info_v.end(), compare);

    // 정렬된 vector 순회
    for (int i = 0; i < info_v.size(); ++i) {
        // 1. 가장 첫 번째 회의 시간은 가장 빠른 시간에 끝나기 때문에 뽑는다.
        // 뽑고 나서는 끝나는 시간에 대해서 갱신해야 한다.
        if (i == 0) {
            selected++;
            current_end = info_v[i].end;
        }
        // 2. 그 후 부터는 현재 종료 시간과 시작 시간을 비교하여 가능 한지 체크한다.
        else {
            // 2-1. 시작 시간이 현재 종료시간보다 빠르면 회의실 사용 불가능.
            if (info_v[i].start < current_end) continue;
                // 2-2. 시작 시간이 현재 종료시간보다 느리면 회의실 사용 가능하다.
            else {
                selected++;
                current_end = info_v[i].end;
            }
        }
    }

    cout << selected << "\n";
}

int main() {
    input();
    solution();
}