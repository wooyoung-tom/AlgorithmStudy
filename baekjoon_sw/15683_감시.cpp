//
// Created by djdj7 on 2020-03-21.
//

/*
 * TODO 15683번 감시 답 보고 풀었음...
 * 카메라가 어디에 있는지, 어디로 봐야하는지 정해주면 되나?
 * DFS에 대해서 조금 더 공부해야 함.
 * 카메라 한대당 각도 바꿔주면서 DFS 돌면서 사각지대 개수 탐색
 * -> 개수 탐색 후 min 바꿔줌
 * DFS 생각 좀 더 해서 풀어볼 수 있지 않을까, 한 번더 풀어보아야 함.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

typedef struct {
    int y, x;
}Direction;

int N, M;
int result;
int office_info[8][8], copy_map[8][8];
vector<pair<int, int>> cam_v;
vector<int> angle;
Direction moveDir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool isVisited[8][8][4];

void copyMap() {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            copy_map[i][j] = office_info[i][j];
        }
    }
}

int checkBlindSpot() {
    int local_result = 0;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            if(copy_map[i][j] == 0) local_result++;
        }
    }
    return local_result;
}

void dfs(int index) {
    if(index == cam_v.size()) {
        for(int i = 0 ; i < cam_v.size() ; i++) {
            int y = cam_v[i].first;
            int x = cam_v[i].second;

            for(int j = 0 ; j < 4 ; j++) {
                if(isVisited[y][x][j]) {
                    int nX = x + moveDir[(angle[i] + j) % 4].x;
                    int nY = y + moveDir[(angle[i] + j) % 4].y;

                    while(true) {
                        if(copy_map[nY][nX] == 6) break;
                        if(!(0 <= nY && nY < N && 0 <= nX && nX < M)) break;
                        if(copy_map[nY][nX] == 0) copy_map[nY][nX] = -1;
                        nX += moveDir[(angle[i] + j) % 4].x;
                        nY += moveDir[(angle[i] + j) % 4].y;
                    }
                }
            }
        }
        result = min(result, checkBlindSpot());
        copyMap();
        return;
    }

    for(int i = 0 ; i < 4 ; i++) {
        angle.push_back(i);
        dfs(index + 1);
        angle.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            cin >> office_info[i][j];
            if(office_info[i][j] != 0 && office_info[i][j] != 6) cam_v.push_back({i, j});

            switch (office_info[i][j]) {
                case 1:
                    isVisited[i][j][0] = true;
                    break;
                case 2:
                    isVisited[i][j][0] = true;
                    isVisited[i][j][2] = true;
                    break;
                case 3:
                    isVisited[i][j][0] = true;
                    isVisited[i][j][1] = true;
                    break;
                case 4:
                    isVisited[i][j][0] = true;
                    isVisited[i][j][1] = true;
                    isVisited[i][j][2] = true;
                    break;
                case 5:
                    isVisited[i][j][0] = true;
                    isVisited[i][j][1] = true;
                    isVisited[i][j][2] = true;
                    isVisited[i][j][3] = true;
                    break;
            }
        }
    }

    result = INF;
    copyMap();
    dfs(0);
    cout << result << "\n";
}