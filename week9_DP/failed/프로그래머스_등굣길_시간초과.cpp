//
// Created by 최우영 on 2021/01/19.
//

#include <string>
#include <utility>
#include <vector>

#define TARGET 1000000007

using namespace std;

struct Point {
    int col, row;
};

int way[101][101];

Point pMove[2] = {Point{1, 0}, Point{0, 1}};

bool isPuddle(int col, int row, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); ++i) {
        int pCol = puddles[i][0];
        int pRow = puddles[i][1];

        if (col == pCol && row == pRow) return true;
    }
    return false;
}

bool isInRange(int mCol, int mRow, int m, int n) {
    return mCol <= m && mRow <= n;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 집 가는 경우의 수를 1로 초기화
    way[1][1] = 1;

    // (1, 1) 부터 순회 시작
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 현재 있는 곳이 잠겨있으면 continue
            if (isPuddle(j, i, puddles)) continue;

            // 오른쪽 및 아래로 이동
            for (int k = 0; k < 2; ++k) {
                int mCol = j + pMove[k].col;
                int mRow = i + pMove[k].row;

                // 웅덩이인지, 범위 내에 있는지 확인
                if (isPuddle(mCol, mRow, puddles)) continue;
                if (!isInRange(mCol, mRow, m, n)) continue;

                way[mCol][mRow] += way[j][i];
            }
        }
    }

    answer = way[m][n] % TARGET;

    printf("%d", answer);

    return answer;
}

int main() {
    int m = 4, n = 3;
    vector<vector<int>> puddles = {
            {2, 2}
    };

    solution(m, n, puddles);
}