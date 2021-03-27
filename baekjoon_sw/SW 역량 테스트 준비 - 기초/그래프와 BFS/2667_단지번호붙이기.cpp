//
// Created by djdj7 on 2020-04-20.
//  23:00 ~ 23:40

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int map[25][25];
bool isVisited[25][25];

int move_row[] = {0, 0, 1, -1};
int move_col[] = {1, -1, 0, 0};

vector<int> result_vector;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
            isVisited[i][j] = false;
        }
    }
}

void bfs(int row, int col) {
    int count = 1;
    queue<pair<int, int>> queue;
    pair<int, int> position = make_pair(row, col);
    queue.push(position);

    while (!queue.empty()) {
        pair<int, int> current_position = queue.front();
        queue.pop();

        /* 0: 오른쪽/1: 왼쪽/2: 아래쪽/3: 위쪽 */
        for(int i = 0 ; i < 4 ; i++) {
            int _row = current_position.first + move_row[i];
            int _col = current_position.second + move_col[i];
            if(_row >= 0 && _row < N && _col >= 0 && _col < N) {
                if(!isVisited[_row][_col] && map[_row][_col] == 1) {
                    queue.push(make_pair(_row, _col));
                    count++;
                    isVisited[_row][_col] = true;
                }
            }
        }
    }
    result_vector.push_back(count);
}

void sort() {
    int temp = 0;
    for(int i = 0 ; i < result_vector.size()-1 ; i++) {
        for(int j = 0 ; j < result_vector.size()-1-i ; j++) {
            if(result_vector[j] > result_vector[j+1]) {
                temp = result_vector[j];
                result_vector[j] = result_vector[j+1];
                result_vector[j+1] = temp;
            }
        }
    }
}

int main() {
    input();
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            if(!isVisited[i][j] && map[i][j] == 1) {
                isVisited[i][j] = true;
                bfs(i, j);
            }
        }
    }
    sort();
    cout << result_vector.size() << "\n";
    for(int i = 0 ; i < result_vector.size() ; i++) {
        cout << result_vector[i] << "\n";
    }
    return 0;
}