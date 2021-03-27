//
// Created by djdj7 on 2020-03-23.
//

/*
 * TODO 15684 사다리 조작 풀이...
 * 이 문제도 감시 문제처럼 DFS 사용함.
 * 다리 하나씩 놓으면서 DFS?
 * Brute Force 문제, 전부 다 검사해보아야함.
 * 사다리 column을 옮기면서, 가로선을 그을 때의 로직을 한번더 생각해보아야함.
 * 어떤 방식으로 DFS를 돌리는지에 대해서 생각해볼 필요가있음.
 * 5번 column은 아예 줄이 안그어짐.
 * 1~4번 column 돌면서 원래 있던 가로줄에 대해서는 어떻게 처리하는가?
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int h, n;
int result = 987654321;
bool ladder[30][10];

bool answer_check() {
    for(int i = 0 ; i < N ; i++) {
        int temp = i;
        for(int j = 0 ; j < H ; j++) {
            if(ladder[j][temp]) temp += 1;
            else if (temp > 0 && ladder[j][temp-1]) temp -= 1;
        }
        if(temp != i) return false;
    }
    return true;
}

void dfs(int count, int _h, int _n) {
    if(result <= count) return;
    if(answer_check()) {
        if(result > count) result = count;
        return;
    }
    if(count == 3) return;
    for(int i = _h ; i < H ; i++, _n = 0) {
        for(int j = _n ; j < N-1 ; j++) {
            if(ladder[i][j]) j += 1;
            else {
                ladder[i][j] = true;
                dfs(count + 1, i, j + 2);
                ladder[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M >> H;

    for(int i = 0 ; i < M ; i++) {
        cin >> h >> n;
        ladder[h-1][n-1] = true;
    }

    dfs(0, 0, 0);

    cout << (result < 4 ? result : -1);
}