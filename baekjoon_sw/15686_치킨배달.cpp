//
// Created by djdj7 on 2020-03-25.
//

/*
 * TODO 15686 치킨배달 풀이...
 *  1. 전체 도시 치킨거리 구함 -> 구할 필요가 없음.
 *  2. 결국 count 해나가면서 그거만 포함해서 센 도시 치킨거리의 최소값만 구하면 됨.
 *  M개 선택해서 전부 돌려 보면 됨 => Brute-Force
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 987654321;

typedef struct {
    int row;
    int col;
} Point;

int N, M;
int city_distance = INF;
int city_map[51][51];
bool isAlive[13] = { false };

vector<Point> house_point_v;
vector<Point> chicken_point_v;

void input() {
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            scanf("%1d", &city_map[i][j]);
            if(city_map[i][j] == 1) house_point_v.push_back(Point{i, j});
            else if(city_map[i][j] == 2) chicken_point_v.push_back(Point{i, j});
        }
    }
}

void calculate_distance() {
    int temp_result = 0;
    for(int i = 0 ; i < house_point_v.size() ; i++) {
        int house_to_chicken = INF;
        Point house_point = house_point_v[i];
        for(int j = 0 ; j < chicken_point_v.size() ; j++) {
            if(isAlive[j]){
                Point chicken_point = chicken_point_v[j];
                int row_dist = abs(house_point.row - chicken_point.row);
                int col_dist = abs(house_point.col - chicken_point.col);
                int temp_distance = row_dist + col_dist;
                if(house_to_chicken > temp_distance) house_to_chicken = temp_distance;
            }
        }
        temp_result += house_to_chicken;
    }
    if(city_distance > temp_result) city_distance = temp_result;
}

void dfs(int index, int count) {
    if(count == M) {
        calculate_distance();
        return;
    }
    if(index == chicken_point_v.size()) return;
    isAlive[index] = true;
    dfs(index+1, count+1);
    isAlive[index] = false;
    dfs(index+1, count);
}

int main() {
    input();
    dfs(0, 0);
    cout << city_distance;
}