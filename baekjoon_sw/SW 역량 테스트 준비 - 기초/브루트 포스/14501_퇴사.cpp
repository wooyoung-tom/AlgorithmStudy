//
// Created by djdj7 on 2020-05-28.
//

/*
 * Brute Force
 * 상담을 안하고 다음날로 넘어가느냐, 상담을 하고 그 후로 넘어가느냐
 * 브루트 포스 대체적으로 모두 DFS 사용하는 느낌이 있음.
 */

#include <iostream>

using namespace std;

typedef struct {
    int day;
    int t;
    int p;
} INFO;

int N;
int total_price;
INFO info_list[16];

void input() {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int temp_t, temp_p;
        cin >> temp_t >> temp_p;
        info_list[i] = {i, temp_t, temp_p};
    }
}

void dfs(int current_day, int current_price) {
    if (current_day >= N + 1) {
        total_price = max(total_price, current_price);
        return;
    }
    if (current_day + info_list[current_day].t <= N + 1) {
        dfs(current_day + info_list[current_day].t, current_price + info_list[current_day].p);
    }
    if (current_day + 1 <= N + 1) {
        dfs(current_day + 1, current_price);
    }
}

int main() {
    input();
    dfs(1, 0);

    cout << total_price;
}