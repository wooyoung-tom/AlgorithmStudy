//
// Created by djdj7 on 2020-05-28.
//

/*
 *  DFS 느낌으로 접근. 브루트 포스 문제임
 *  처음에 1씩 빼다가 0이되면 ++,
 *  그다음 1빼고 2빼고 이런식으로 접근.
 */

#include <iostream>
#include <vector>

using namespace std;

int T;
int count;
vector<int> result_v;

void solution(int n) {
    if (n == 0) {
        count++;
        return;
    }
    if (n - 1 >= 0) solution(n - 1);
    if (n - 2 >= 0) solution(n - 2);
    if (n - 3 >= 0) solution(n - 3);
}

void input_and_solve() {
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        solution(n);
        result_v.push_back(count);
        count = 0;
    }

    for (int j = 0; j < result_v.size(); ++j) {
        cout << result_v[j] << "\n";
    }
}

int main() {
    input_and_solve();
}