//
// Created by djdj7 on 2020-04-02.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 12

using namespace std;

typedef struct {
    int nutrition = 0;
    vector<int> tree_info;
    vector<int> dead_tree;
} Land;

int N, M, K;
int result = 0;
/* 양분 및 땅 나타내는 배열 */
Land land_info[MAX][MAX];
int winter_nutrition[MAX][MAX];
/* 행렬 이동 */
int move_row[] = {0, 1, -1};
int move_col[] = {1, -1, 0};

void input() {
    cin >> N >> M >> K;
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            land_info[i][j].nutrition = 5;
            cin >> winter_nutrition[i][j];
        }
    }
    for(int i = 0 ; i < M ; i++) {
        int row, col, age;
        cin >> row >> col >> age;
        land_info[row][col].tree_info.push_back(age);
    }
}

void spring_summer() {
    for(int row = 1 ; row <= N ; row++) {
        for(int col = 1 ; col <= N ; col++) {
            if(!land_info[row][col].tree_info.empty()) {
                sort(land_info[row][col].tree_info.begin(), land_info[row][col].tree_info.end());
                for(int i = 0 ; i < land_info[row][col].tree_info.size() ; i++) {
                    if(land_info[row][col].nutrition - land_info[row][col].tree_info[i] < 0) {
                        land_info[row][col].dead_tree.push_back(land_info[row][col].tree_info[i]);
                    } else {
                        land_info[row][col].nutrition -= land_info[row][col].tree_info[i];
                        land_info[row][col].tree_info[i]++;
                    }
                }
                while(!land_info[row][col].dead_tree.empty()) {
                    int dead_age = land_info[row][col].dead_tree[land_info[row][col].dead_tree.size() - 1];
                    land_info[row][col].tree_info.pop_back();
                    land_info[row][col].dead_tree.pop_back();
                    land_info[row][col].nutrition += (int) dead_age/2;
                }
            }
        }
    }
}

void make_tree(int row, int col) {
    /*
     * 00:우/01:좌/02:제자리
     * 10:아래_우/11:아래_좌/12:아래
     * 20:위_우/21:위_좌/22:위
     */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int _row = row + move_row[i];
            int _col = col + move_col[j];
            if(i == 0 && j == 2) continue;
            if (_row >= 1 && _row <= N && _col >= 1 && _col <= N) {
                land_info[_row][_col].tree_info.push_back(1);
            }
        }
    }
}

void autumn() {
    for(int row = 1 ; row <= N ; row++) {
        for(int col = 1 ; col <= N ; col++) {
            for (int i = 0; i < land_info[row][col].tree_info.size(); i++) {
                if (land_info[row][col].tree_info[i] % 5 == 0) {
                    make_tree(row, col);
                }
            }
        }
    }
}

void winter() {
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            result += land_info[i][j].tree_info.size();
            land_info[i][j].nutrition += winter_nutrition[i][j];
        }
    }
}

int main() {
    input();

    for(int i = 1 ; i <= K ; i++) {
        result = 0;
        spring_summer();
        autumn();
        winter();
    }
    cout << result;
}