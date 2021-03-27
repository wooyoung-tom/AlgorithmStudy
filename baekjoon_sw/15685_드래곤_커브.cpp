//
// Created by djdj7 on 2020-03-23.
//

/*
 * TODO 15685 드래곤커브 풀이...
 * 전형적인 시뮬레이션 문제, 톱니바퀴와 비슷하게 조건에 맞게
 * 모두 돌려보는것.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int x, y, d, g;
int result;

vector<vector<int>> direction;
bool graph[102][102] = { false };

void decide_directions() {
    vector<int> temp_direction;

    for(int i = 0 ; i <= g ; i++) {
        if(i == 0) {
            temp_direction.push_back(d);
            direction.push_back(temp_direction);
        } else if(i == 1) {
            temp_direction.push_back((d+1) % 4);
            direction.push_back(temp_direction);
        } else {
            for(int k = direction[i - 1].size() - 1 ; k >= 0 ; k--) {
                temp_direction.push_back((direction[i - 1][k] + 1) % 4);
            }
            for(int k = 0 ; k < direction[i - 1].size() ; k++) {
                temp_direction.push_back(direction[i - 1][k]);
            }
            direction.push_back(temp_direction);
        }
        temp_direction.clear();
    }
}

void curve() {
    decide_directions();
    for(int i = 0 ; i < direction.size() ; i++) {
        vector<int> temp_v = direction[i];
        for(int j = 0 ; j < temp_v.size() ; j++) {
            switch (temp_v[j]) {
                case 0: x++; break;
                case 1: y--; break;
                case 2: x--; break;
                case 3: y++; break;
            }
            graph[x][y] = true;
        }
    }
    direction.clear();
}

int main() {
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        cin >> x >> y >> d >> g;
        graph[x][y] = true;
        curve();
    }

    for(int i = 0 ; i < 101 ; i++) {
        for(int j = 0 ; j < 101 ; j++) {
            if(graph[i][j] && graph[i][j+1] && graph[i+1][j] && graph[i+1][j+1])
                result++;
        }
    }
    cout << result;
}